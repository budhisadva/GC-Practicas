#include "util/math.h"
#include <vector>
#include <cmath>

std::vector<Vector3> vectoriza(int gradosY, int gradosX, double escalamiento, int width, int height) {
  std::vector<Vector4> vertices_global;
  vertices_global.push_back(Vector4( 1,-1, 1, 1));
  vertices_global.push_back(Vector4( 1, 1, 1, 1));
  vertices_global.push_back(Vector4(-1, 1, 1, 1));
  vertices_global.push_back(Vector4(-1,-1, 1, 1));
  vertices_global.push_back(Vector4( 1,-1,-1, 1));
  vertices_global.push_back(Vector4( 1, 1,-1, 1));
  vertices_global.push_back(Vector4(-1, 1,-1, 1));
  vertices_global.push_back(Vector4(-1,-1,-1, 1));
  std::vector<Vector4> vertices_modelo;
  double thetaY = (gradosY*M_PI)/180.0;
  double thetaX = (gradosX*M_PI)/180.0;
  Matrix4 M_rotarY = Matrix4::rotateY(thetaY);
  Matrix4 M_rotarX = Matrix4::rotateX(thetaX);
  Matrix4 M_escalar = Matrix4::scale(0.25, 0.25, 0.25);
  Matrix4 M_rotaciones = Matrix4::multiply(M_rotarY, M_rotarX);
  Matrix4 M_modelo = Matrix4::multiply(M_rotaciones, M_escalar);
  for (int i = 0; i < vertices_global.size(); i++) {
    vertices_modelo.push_back( M_modelo.multiplyVector(vertices_global[i]) );
  }
  std::vector<Vector4> vertices_vista;
  Matrix4 M_camara = Matrix4::lookAt(Vector3(10,5,10), Vector3(0,0,0), Vector3(0,1,0));
  Matrix4 M_vista = Matrix4::multiply(M_camara, M_modelo);
  for (int i = 0; i < vertices_modelo.size(); i++) {
    vertices_vista.push_back( M_vista.multiplyVector(vertices_modelo[i]) );
  }
  std::vector<Vector4> vertices_clip;
  Matrix4 M_proyeccion = Matrix4::perspective(45.0, width/static_cast<double>(height), 0.1, 100.0);
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
  return vertices_vp;
}
