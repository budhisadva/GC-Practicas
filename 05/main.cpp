#include "./header/ventana.h"
#include "./header/shader.h"
#include <iostream>

Ventana *ventana;
Model *model;

void finish(){
    glfwTerminate();
    delete(model);
    delete(ventana);
}

void init(char* nombre){
  ventana = new Ventana(600,600);
  ventana->initGLFW();
  ventana->initGLEW();
  model = new Model(nombre);
  ventana->initModels(model);
  ventana->initViewProyection();
}

int main(int argc, char* argv[]) {
  init(argv[1]);
  ventana->render();
  finish();
  return 0;
}
