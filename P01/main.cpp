#include "vectorizacion.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

const int width = 800;
const int height = 600;
std::vector<uint8_t> pixels;
uint32_t BLANCO = 0xFFFFFFFF, NEGRO = 0x00000000;

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

void bresenham(int x0, int y0, int x1, int y1, uint32_t color) {
  int sx, sy, error, e2;
  int dx = std::abs(x1-x0);
  int dy = std::abs(y1-y0);
  if (x0 < x1) {
    sx = 1;
  } else {
    sx = -1;
  }
  if (y0 < y1) {
    sy = 1;
  } else {
    sy = -1;
  }
  error = dx-dy;
  while (x0 != x1 || y0 != y1 ) {
    pinta(x0, y0, color);
    e2 = 2*error;
    if (e2 > -dy) {
      error = error-dy;
      x0 = x0+sx;
    }
    if (e2 < dx) {
      error = error+dx;
      y0 = y0+sy;
    }
  }
}

int main() {
  int grados = 0;
  sf::Texture texture;
  texture.create(width, height);
  sf::RenderWindow window(sf::VideoMode(width, height), "Trazado de lineas");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
          grados++;
        } else if (event.key.code == sf::Keyboard::Right) {
          grados--;
        }
      }
    }
    initPixels(BLANCO);
    std::vector<Vector3> vertices_vp = vectoriza(grados, width, height);
    for (int i = 0; i < vertices_vp.size(); i++) {
      pinta(vertices_vp[i].getX(), vertices_vp[i].getY(), NEGRO);
    }
    bresenham(vertices_vp[0].getX(), vertices_vp[0].getY(), vertices_vp[1].getX(), vertices_vp[1].getY(), NEGRO);
    bresenham(vertices_vp[0].getX(), vertices_vp[0].getY(), vertices_vp[3].getX(), vertices_vp[3].getY(), NEGRO);
    bresenham(vertices_vp[0].getX(), vertices_vp[0].getY(), vertices_vp[4].getX(), vertices_vp[4].getY(), NEGRO);
    bresenham(vertices_vp[2].getX(), vertices_vp[2].getY(), vertices_vp[1].getX(), vertices_vp[1].getY(), NEGRO);
    bresenham(vertices_vp[2].getX(), vertices_vp[2].getY(), vertices_vp[3].getX(), vertices_vp[3].getY(), NEGRO);
    bresenham(vertices_vp[2].getX(), vertices_vp[2].getY(), vertices_vp[6].getX(), vertices_vp[6].getY(), NEGRO);
    bresenham(vertices_vp[5].getX(), vertices_vp[5].getY(), vertices_vp[4].getX(), vertices_vp[4].getY(), NEGRO);
    bresenham(vertices_vp[5].getX(), vertices_vp[5].getY(), vertices_vp[6].getX(), vertices_vp[6].getY(), NEGRO);
    bresenham(vertices_vp[5].getX(), vertices_vp[5].getY(), vertices_vp[1].getX(), vertices_vp[1].getY(), NEGRO);
    bresenham(vertices_vp[7].getX(), vertices_vp[7].getY(), vertices_vp[4].getX(), vertices_vp[4].getY(), NEGRO);
    bresenham(vertices_vp[7].getX(), vertices_vp[7].getY(), vertices_vp[6].getX(), vertices_vp[6].getY(), NEGRO);
    bresenham(vertices_vp[7].getX(), vertices_vp[7].getY(), vertices_vp[3].getX(), vertices_vp[3].getY(), NEGRO);
    bresenham(vertices_vp[0].getX(), vertices_vp[0].getY(), vertices_vp[2].getX(), vertices_vp[2].getY(), 0x0000FFFF);
    bresenham(vertices_vp[1].getX(), vertices_vp[1].getY(), vertices_vp[3].getX(), vertices_vp[3].getY(), 0x0000FFFF);
    bresenham(vertices_vp[4].getX(), vertices_vp[4].getY(), vertices_vp[6].getX(), vertices_vp[6].getY(), 0xFF0000FF);
    bresenham(vertices_vp[5].getX(), vertices_vp[5].getY(), vertices_vp[7].getX(), vertices_vp[7].getY(), 0xFF0000FF);
    pinta(vertices_vp[8].getX(), vertices_vp[8].getY(), 0xe51abeFF);
    texture.update(pixels.data());
    sf::Sprite sprite(texture);
    window.clear();
    window.draw(sprite);
    window.display();
  }
  return 0;
}
