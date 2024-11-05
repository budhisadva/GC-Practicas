#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>

const int width = 800;
const int height = 600;
std::vector<uint8_t> pixels;

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
  std::cout << "Fondo pantalla" << '\n';
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
  sf::Texture texture;
  texture.create(width, height);
  initPixels(0x00000000);
  // Begin
  uint32_t BLANCO = 0xFFFFFFFF, AZUL = 0x0000FFFF, ROJO = 0xFF0000FF, VERDE = 0x00FF00FF;
  int x0 = (int)width*0.5;
  int y0 = (int)height*0.5;
  uint32_t colores[] = {ROJO, VERDE, AZUL};
  for (int j = 200; j < 600; j++) {
    bresenham(x0, y0, j, 100, colores[j%3]);
    bresenham(x0, y0, j, 500, colores[j%3]);
  }
  for (int i = 100; i < 500; i++) {
    bresenham(x0, y0, 200, i, colores[i%3]);
    bresenham(x0, y0, 600, i, colores[i%3]);
  }
  // end
  texture.update(pixels.data());
  sf::Sprite sprite(texture);
  sf::RenderWindow window(sf::VideoMode(width, height), "Trazado de lineas");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear();
    window.draw(sprite);
    window.display();
  }
  return 0;
}
