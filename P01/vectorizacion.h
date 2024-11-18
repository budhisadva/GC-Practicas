#include "util/math.h"
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

std::vector<Vector4> vertices_global;
bool EJECUTA = true;
double maximos[3] = {0,0,0};
double minimos[3] = {0,0,0};

void leeOBJ(std::string nombre) {
  std::ifstream file(nombre);
  if (!file.is_open()) {
    std::cerr << "No se pudo abrir el archivo OBJ." << '\n';
    return;
  }
  std::string line;
  int vertices = 0, caras = 0;
  while (std::getline(file, line)) {
    if (line[0] == 'v' && line[1] == ' ') {
      std::istringstream stream(line);
      std::string palabra;
      std::vector<std::string> punto;
      double x, y, z;
      while (stream >> palabra) {
        punto.push_back(palabra);
      }
      x = std::stod(punto[1]);
      y = std::stod(punto[2]);
      z = std::stod(punto[3]);
      if (x < minimos[0]) minimos[0] = x;
      if (y < minimos[1]) minimos[1] = y;
      if (z < minimos[2]) minimos[2] = z;
      if (x > maximos[0]) maximos[0] = x;
      if (y > maximos[1]) maximos[1] = y;
      if (z > maximos[2]) maximos[2] = z;
      vertices_global.push_back(Vector4(x, y, z, 1));
      vertices++;
    } else if (line[0] == 'f' && line[1] == ' ') {
      caras++;
    }
  }
  file.close();
  std::cout << "Modelo: " << nombre << '\n';
  std::cout << "Numero de vertices: " << vertices << '\n';
  std::cout << "Numero de caras: " << caras << '\n';
}

std::vector<Vector3> vectoriza(int gradosY, double escalamiento, int width, int height, std::string nombre) {
  if (EJECUTA) {
    leeOBJ(nombre);
  }
  std::vector<Vector4> vertices_modelo;
  double thetaY = (gradosY*M_PI)/180.0;
  Matrix4 M_rotarY = Matrix4::rotateY(thetaY);
  Matrix4 M_escalar = Matrix4::scale(escalamiento, escalamiento, escalamiento);
  Matrix4 M_modelo = Matrix4::multiply(M_rotarY, M_escalar);
  for (int i = 0; i < vertices_global.size(); i++) {
    vertices_modelo.push_back( M_modelo.multiplyVector(vertices_global[i]) );
  }
  std::vector<Vector4> vertices_vista;
  double max[3], min[3];
  for (size_t i = 0; i < 3; i++) {
    max[i] = maximos[i] * escalamiento;
    min[i] = minimos[i] * escalamiento;
  }
  Vector3 suma = Vector3::add(Vector3(max[0], max[1], max[2]), Vector3(min[0], min[1], min[2]));
  suma.set(suma.getX()*0.5, suma.getY()*0.5, suma.getZ()*0.5);
  Matrix4 M_camara = Matrix4::lookAt(Vector3(10,2,10), suma, Vector3(0,-1,0));
  Matrix4 M_vista = Matrix4::multiply(M_camara, M_modelo);
  for (int i = 0; i < vertices_modelo.size(); i++) {
    vertices_vista.push_back( M_vista.multiplyVector(vertices_modelo[i]) );
  }
  std::vector<Vector4> vertices_clip;
  Matrix4 M_proyeccion = Matrix4::perspective(100.0, width/static_cast<double>(height), 0.1, 100.0);
  for (int i = 0; i < vertices_vista.size(); i++) {
    vertices_clip.push_back( M_proyeccion.multiplyVector(vertices_vista[i]) );
  }
  std::vector<Vector3> vertices_ndc;
  for (int i = 0; i < vertices_clip.size(); i++) {
    vertices_ndc.push_back(Vector3(vertices_clip[i].getX(), vertices_clip[i].getY(), 1));
  }
  std::vector<Vector3> vertices_vp;
  Matrix3 M_vp = Matrix3::viewport(width, height);
  for (int i = 0; i < vertices_ndc.size(); i++) {
    vertices_vp.push_back(M_vp.multiplyVector(vertices_ndc[i]));
  }
  EJECUTA = false;
  return vertices_vp;
}
