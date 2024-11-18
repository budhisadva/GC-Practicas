#include "vectorizacion.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

const int width = 800;
const int height = 600;
std::vector<uint8_t> pixels;
uint32_t BLANCO = 0xFFFFFFFF, NEGRO = 0x000000FF;

void initPixels(uint32_t color){
  pixels.reserve(width * height * 4);
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      uint32_t pixel = color;
      int index = (y * width + x) * 4;
      pixels[index + 0] = (pixel >> 24) & 0xFF; // R
      pixels[index + 1] = (pixel >> 16) & 0xFF; // G
      pixels[index + 2] = (pixel >> 8) & 0xFF;  // B
      pixels[index + 3] = pixel & 0xFF;         // A
    }
  }
}

void pinta(int x, int y, uint32_t color) {
  int index = (y * width + x) * 4;
  pixels[index + 0] = (color >> 24) & 0xFF;
  pixels[index + 1] = (color >> 16) & 0xFF;
  pixels[index + 2] = (color >> 8) & 0xFF;
  pixels[index + 3] = color & 0xFF;
}

int main(int argc, char* argv[]) {
  sf::Texture texture;
  texture.create(width, height);
  sf::RenderWindow window(sf::VideoMode(width, height), "Proyecto medio Semestre");
  int gradosY = 0;
  double escalamiento = 1;
  bool EJECUTAR = true;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
          gradosY++;
        } else if (event.key.code == sf::Keyboard::Right) {
          gradosY--;
        }
        EJECUTAR = true;
      }
      if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
          float delta = event.mouseWheelScroll.delta;
          if (escalamiento < 0.2) {
            escalamiento = 0.2;
          } else if (0.2 <= escalamiento && escalamiento < 1) {
            escalamiento += 0.1 * delta;
          } else if (1 <= escalamiento && escalamiento <= 10) {
            if (escalamiento == 1 && delta < 0) {
              escalamiento = 0.9;
            } else {
              escalamiento += delta;
            }
          } else {
            escalamiento = 10;
          }
        }
        EJECUTAR = true;
      }
    }
    if (EJECUTAR) {
      initPixels(NEGRO);
      std::vector<Vector3> vertices_vp = vectoriza(gradosY, escalamiento, width, height, argv[1]);
      for (int i = 0; i < vertices_vp.size(); i++) {
        if (vertices_vp[i].getX() >= 0 && vertices_vp[i].getX() <= width) {
          if (vertices_vp[i].getY() >= 0 && vertices_vp[i].getY() <= height) {
            pinta(vertices_vp[i].getX(), vertices_vp[i].getY(), BLANCO);
          }
        }
      }
      texture.update(pixels.data());
      sf::Sprite sprite(texture);
      window.clear();
      window.draw(sprite);
      window.display();
      EJECUTAR = false;
    }
  }
  return 0;
}
