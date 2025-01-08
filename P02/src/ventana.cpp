#include "../header/ventana.h"
#include <iostream>

Ventana::Ventana(){
    width = 800;
    height = 600;
}

Ventana::Ventana(GLuint w, GLuint h){
    width = w;
    height = h;
}

void Ventana::initGLFW(){
  if (!glfwInit()) {
    std::cerr << "Error al inicializar GLFW" << std::endl;
    return;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  window = glfwCreateWindow(width, height, "Visualizador de modelos", nullptr, nullptr);
  if (!window) {
    std::cerr << "Error al crear la ventana" << std::endl;
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(window);
}

void Ventana::initGLEW(){
  if (glewInit() != GLEW_OK) {
    std::cerr << "Error al inicializar GLEW" << std::endl;
    return;
  }
  std::cout << "Inicialización Correcta de GLEW y GLFW" << std::endl;
  // Habilitar depth testing y face culling
  glEnable(GL_DEPTH_TEST);  // Prueba de profundidad
  glCullFace(GL_BACK);      // Culling de caras traseras
  glFrontFace(GL_CCW);      // Las caras frontales son las que tienen vértices en sentido antihorario
}

void Ventana::initModels(Model* m, glm::mat4 model_m, int opcion){
  if (opcion == 1) {
    crash = m;
    crash->initModel(model_m);
  } else if (opcion == 2) {
    pinguin = m;
    pinguin->initModel(model_m);
  } else if (opcion == 3) {
    polar = m;
    polar->initModel(model_m);
  } else if (opcion == 4) {
    crystal = m;
    crystal->initModel(model_m);
  } else if (opcion == 5) {
    skybox = m;
    skybox->initModel(model_m);
  }
}

void Ventana::initViewProyection(){
     // Configurar matrices de transformación (model, view, projection)
    view = glm::lookAt(glm::vec3(0.0f,5.0f,15.0f), glm::vec3(0.0f,5.0f,0.0f), glm::vec3(0.0,1.0,0.0));
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Ventana::render(){
  while (!glfwWindowShouldClose(window)) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
      if (x < 20) x++;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
      if (x > -20) x--;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
      if (z < 20) z++;
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
      if (z > -20) z--;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
      if (y < 20) y++;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
      if (y > 1) y--;
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    view = glm::lookAt(glm::vec3(x,y,z), glm::vec3(0.0f,5.0f,0.0f), glm::vec3(0.0,1.0,0.0));
    crash->renderModel(view, projection);
    pinguin->renderModel(view, projection);
    polar->renderModel(view, projection);
    crystal->renderModel(view, projection);
    skybox->renderModel(view, projection);
    glfwSwapBuffers(window);
    glfwPollEvents();
    update();
  }
}

void Ventana::update(){
  crystal->updateModel();
}

void Ventana::idel(){}

void Ventana::finish(){
  crash->finish();
  pinguin->finish();
  polar->finish();
  crystal->finish();
  skybox->finish();
}
