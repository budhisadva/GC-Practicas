#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../header/shader.h"
#include "../header/textura.h"

class Model{
public:
    Shader* shader;
    Textura* textura;
    std::vector<float> vertices, texturas, normales;
    std::vector<unsigned int> i_v, i_vn, i_vt;
    int numeroVertices = 0, numeroCaras = 0, numeroTexturas = 0, numeroNormales = 0;
    GLuint VAO, VBO, EBO, UVBO, NBO;
    glm::mat4 modelmat;
    double maximos[3] = {}, minimos[3] = {};
    float angle;

    Model(std::string nombre, std::string imagen);
    void initModel(glm::mat4 model);
    void renderModel(glm::mat4 view, glm::mat4 projection);
    void updateModel(float timeValue);
    void finish();
    void lectorOBJ(std::string nombre);
};
