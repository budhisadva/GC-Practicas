#include "../header/model.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../header/stb_image.h"

Model::Model(std::string nombre, std::string imagen){
  lectorOBJ(nombre);
  if (!imagen.empty()) textura = new Textura(imagen);
}

void Model::initModel(glm::mat4 model){
  modelmat = model;
  shader = new Shader("./shader/bandicoot_shader.vert", "./shader/bandicoot_shader.frag");

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &NBO);
  glGenBuffers(1, &UVBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), vertices.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)0);
  glEnableVertexAttribArray(0);

  if (!normales.empty()) {
    glBindBuffer(GL_ARRAY_BUFFER, NBO);
    glBufferData(GL_ARRAY_BUFFER, normales.size()*sizeof(float), normales.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)0);
    glEnableVertexAttribArray(1);
  }
  if (!texturas.empty()) {
    glBindBuffer(GL_ARRAY_BUFFER, UVBO);
    glBufferData(GL_ARRAY_BUFFER, texturas.size()*sizeof(float), texturas.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (GLvoid*)0);
    glEnableVertexAttribArray(2);
  }
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, i_v.size()*sizeof(unsigned int), i_v.data(), GL_STATIC_DRAW);
}

void Model::updateModel(float timeValue){
  angle = glm::radians(timeValue * 0.2);                                      // 50 grados por segundo
  modelmat = glm::rotate(modelmat, angle, glm::vec3(0.0f, 1.0f, 0.0f));   // Rotar alrededor de (0.0, 1.0, 0.0)
}

void Model::renderModel(glm::mat4 view, glm::mat4 projection){
  shader->use();
  shader->setVec3("posCam", glm::vec3(0.0f,0.0f,-10.0f));
  shader->setMat4x4("model", modelmat);
  shader->setMat4x4("view", view);
  shader->setMat4x4("projection", projection);
  textura->activar(GL_TEXTURE0,shader->ID);
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, i_v.size(), GL_UNSIGNED_INT, 0);
}

void Model::finish(){
  shader->terminate();
  delete(shader);
  delete(textura);
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &NBO);
  glDeleteBuffers(1, &UVBO);
  glDeleteBuffers(1, &EBO);
}

void Model::lectorOBJ(std::string nombre){
  std::ifstream file(nombre);
  if (!file.is_open()) {
    std::cerr << "No se pudo abrir el archivo OBJ." << '\n';
    return;
  }
  std::string line;
  while (std::getline(file, line)) {
    if (line.substr(0, 2) == "v ") {
      std::istringstream iss(line.substr(2));
      float x, y, z;
      iss >> x >> y >> z;
      vertices.push_back(x);
      vertices.push_back(y);
      vertices.push_back(z);
      numeroVertices++;
    } else if (line.substr(0, 3) == "vt ") {
      std::istringstream iss(line.substr(3));
      float u, v;
      iss >> u >> v;
      texturas.push_back(u);
      texturas.push_back(v);
      numeroTexturas++;
    } else if (line.substr(0, 3) == "vn ") {
      std::istringstream iss(line.substr(3));
      float i, j, k;
      iss >> i >> j >> k;
      normales.push_back(i);
      normales.push_back(j);
      normales.push_back(k);
      numeroNormales++;
    } else if (line.substr(0, 2) == "f ") {
      std::istringstream iss(line.substr(2));
      std::string vertex;
      while (iss >> vertex) {
        std::istringstream viss(vertex);
        std::string index;
        if (std::getline(viss, index, '/')) {
          if (!index.empty()) i_v.push_back(std::stoi(index)-1);
        }
        if (std::getline(viss, index, '/')) {
          if (!index.empty()) i_vt.push_back(std::stoi(index)-1);
        }
        if (std::getline(viss, index, '/')) {
          if (!index.empty()) i_vn.push_back(std::stoi(index)-1);
        }
      }
      numeroCaras++;
    }
  }
  file.close();
  std::cout << "Modelo: " << nombre << '\n';
  std::cout << "Numero de Vertices: " << numeroVertices  << '\n';
  std::cout << "Numero de Caras: " << numeroCaras << '\n';
  std::cout << "==========================================" << '\n';
}
