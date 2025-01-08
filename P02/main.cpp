#include "./header/ventana.h"
#include "./header/shader.h"
#include <iostream>

Ventana *ventana;
Model *crash, *pinguin, *polar, *cristal, *skybox;

void finish(){
    glfwTerminate();
    delete(crash);
    delete(pinguin);
    delete(polar);
    delete(cristal);
    delete(skybox);
    delete(ventana);
}

void init(){
  ventana = new Ventana();
  ventana->initGLFW();
  ventana->initGLEW();
  crash = new Model("./modelos/Crash/crash.obj", "./modelos/Crash/crash.png");
  pinguin = new Model("./modelos/Penguin/penguin.obj", "./modelos/Penguin/penguin.png");
  polar = new Model("./modelos/Polar/Polar.obj", "./modelos/Polar/PolarEyelid_PS2.png");
  cristal = new Model("./modelos/Crystal/crystal.obj", "./modelos/Crystal/image63.png");
  skybox = new Model("./modelos/Skybox/skybox.obj", "./modelos/Skybox/skybox.png");
  glm::mat4 m1, m2, m3, m4, m5, inter2, inter3, inter5;
  m1 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f));
  m2 = glm::translate(glm::mat4(1.0f), glm::vec3(5.0f, 0.0f, 0.0f));
  m3 = glm::translate(glm::mat4(1.0f), glm::vec3(-5.0f, 0.0f, 0.0f));
  m4 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
  m5 = glm::scale(glm::mat4(1.0f), glm::vec3(40.0)) * glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
  inter3 = glm::scale(glm::mat4(1.0f), glm::vec3(3.5)) * glm::rotate(glm::mat4(1.0f), glm::radians(100.0f), glm::vec3(0.0f, 1.0f, 0.0f));
  inter2 = glm::rotate(glm::mat4(1.0f), glm::radians(-80.0f), glm::vec3(0.0f, 1.0f, 0.0f));
  inter5 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.5f, 0.0f));

  ventana->initModels(crash, m1, 1);
  ventana->initModels(pinguin, m2*inter2, 2);
  ventana->initModels(polar, m3*inter3, 3);
  ventana->initModels(cristal, m4, 4);
  ventana->initModels(skybox, m5*inter5, 5);
  ventana->initViewProyection();
}

int main() {
  init();
  ventana->render();
  finish();
  return 0;
}
