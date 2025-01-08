#include "./header/ventana.h"
#include "./header/shader.h"
#include <iostream>

Ventana *ventana;
Model *crash, *pinguin, *polar;

void finish(){
    glfwTerminate();
    delete(crash);
    delete(pinguin);
    delete(polar);
    delete(ventana);
}

void init(){
  ventana = new Ventana();
  ventana->initGLFW();
  ventana->initGLEW();
  polar = new Model("./modelos/Polar/Polar.obj", "./modelos/Polar/PolarEyelid_PS2.png");
  crash = new Model("./modelos/Crash/crash.obj", "./modelos/Crash/crash.png");
  pinguin = new Model("./modelos/Penguin/penguin.obj", "./modelos/Penguin/penguin.png");
  glm::mat4 m1, m2, m3, inter3;
  m1 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
  m2 = glm::translate(glm::mat4(1.0f), glm::vec3(7.0f, 0.0f, 0.0f));
  m3 = glm::translate(glm::mat4(1.0f), glm::vec3(-7.0f, 0.0f, 0.0f));
  inter3 = glm::scale(glm::mat4(1.0f), glm::vec3(3.5));

  ventana->initModels(crash, m1, 1);
  ventana->initModels(pinguin, m2, 2);
  ventana->initModels(polar, m3*inter3, 3);
  ventana->initViewProyection();
}

int main() {
  init();
  ventana->render();
  finish();
  return 0;
}
