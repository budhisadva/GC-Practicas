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

class Model{
public:
    Shader* shader;
    std::vector<GLfloat> vertices_global;
    std::vector<GLuint> indices_global;
    GLint numeroVertices = 0, numeroCaras = 0;
    float angle;
    glm::mat4 modelmat;
    GLuint VAO, VBO, EBO;

    Model(char* nombre);
    void initModel();
    void renderModel(glm::mat4 view, glm::mat4 projection);
    void updateModel(float timeValue);
    void finish();
};
