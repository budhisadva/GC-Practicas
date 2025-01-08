#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../header/model.h"

class Ventana{
    public:
        GLuint width, height;
        GLFWwindow* window;
        glm::mat4 view, projection;
        Model *crash, *pinguin, *polar, *crystal, *skybox;
        float x = 0.0f, y = 5.0f, z = 15.0f;

        Ventana();
        Ventana(GLuint w, GLuint h);
        void initGLFW();
        void initGLEW();
        void initModels(Model* m, glm::mat4 model_m, int opcion);
        void initViewProyection();
        void render();
        void update();
        void idel();
        void finish();
};
