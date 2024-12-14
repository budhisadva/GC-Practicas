#include "../header/model.h"

Model::Model(char* nombre){
  std::ifstream file(nombre);
  if (!file.is_open()) {
    std::cerr << "No se pudo abrir el archivo OBJ." << '\n';
    return;
  }
  std::string line;
  while (std::getline(file, line)) {
    if (line[0] == 'v' && line[1] == ' ') {
      std::istringstream stream(line);
      std::string palabra;
      std::vector<std::string> punto;
      while (stream >> palabra) {
        punto.push_back(palabra);
      }
      for (int i = 1; i < 4; i++) {
        vertices_global.push_back(std::stod(punto[i]));
      }
      numeroVertices++;
    } else if (line[0] == 'f' && line[1] == ' ') {
      std::istringstream stream(line);
      std::string palabra;
      std::vector<std::string> cara;
      while (stream >> palabra) {
        cara.push_back(palabra);
      }
      for (int i = 1; i < 4; i++) {
        indices_global.push_back(std::stod(cara[i])-1);
      }
      numeroCaras++;
    }
  }
  file.close();
  std::cout << "Modelo: " << nombre << '\n';
  std::cout << "Numero de Vertices: " << numeroVertices << '\n';
  std::cout << "Numero de Triangulos: " << numeroCaras << '\n';
}

void Model::initModel(){
  modelmat = glm::mat4(1.0f);
  shader = new Shader("./shader/cubo.vert", "./shader/cubo.frag");
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices_global.size() * sizeof(float), vertices_global.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_global.size() * sizeof(unsigned int), indices_global.data(), GL_STATIC_DRAW);
  // Especificar el layout del vertex shader
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);
}

void Model::updateModel(float timeValue){
  angle = timeValue * glm::radians(50.0f);                                      // 50 grados por segundo
  modelmat = glm::rotate(glm::mat4(1.0), angle, glm::vec3(0.0f, 1.0f, 0.0f));   // Rotar alrededor de (0.5, 1.0, 0.0)
}

void Model::renderModel(glm::mat4 view, glm::mat4 projection){
  shader->use();
  // Enviar las matrices al shader
  shader->setVec3("posCam", glm::vec3(0.0f,0.0f,-3.0f));
  shader->setMat4x4("model", modelmat);
  shader->setMat4x4("view", view);
  shader->setMat4x4("projection", projection);
  // Dibujar el cubo
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices_global.size()), GL_UNSIGNED_INT, 0);
}

void Model::finish(){
  shader->terminate();
  delete(shader);
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}
