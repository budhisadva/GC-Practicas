#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

int fibonacci(int n, int acc1, int acc2){
  if (n == 0) {
    return acc1;
  }
  if (n == 1) {
    return acc1;
  }
  return fibonacci(n-1, acc1+acc2, acc1);
}

std::string decimal_a_binario(int n) {
  std::string cadena_binaria = "";
  if (n == 0) { return "0"; }
  while (n > 0) {
    cadena_binaria += std::to_string(n % 2);
    n = n / 2;
  }
  std::reverse(cadena_binaria.begin(), cadena_binaria.end());
  return cadena_binaria;
}

int chicharronera(int a, int b, int c) {
  double x, numerador;
  int delta;
  delta = pow(b,2) - (4*a*c);
  numerador = -b+sqrt(delta);
  x = numerador / (2*a);
  return x;
}

void setMenu(sf::Text* t, sf::Font* f) {
  (*t).setString("1.- Realizar secuencia fibonacci\n"
              "2.- Convertir decimal a binario\n"
              "3.- Calculadora\n"
              "4.- La chicharronera\n"
              "5.- Salir\n"
              "\n\nPresiona la opcion deseada:");
  (*t).setFont(*f);
  (*t).setCharacterSize(24);
  (*t).setPosition(100, 100);
}

int seleciona_opcion_menu(sf::RenderWindow* w) {
  bool continuar = false;
  sf::Event e;
  int n;
  while (!continuar) {
    while ((*w).pollEvent(e)) {
      if (e.type == sf::Event::Closed)
        (*w).close();
      if (e.type == sf::Event::KeyPressed) {
        n = static_cast<int>(e.key.code);
        if (n >= 27 && n <= 31) {
          continuar = true;
        }
      }
    }
  }
  return n;
}

int ingresa_numero_positivo(sf::RenderWindow* w) {
  bool enter_presionado = false;
  std::string entrada;
  sf::Event e;
  while (!enter_presionado) {
    while ((*w).pollEvent(e)) {
      if (e.type == sf::Event::Closed)
        (*w).close();
      if (e.type == sf::Event::TextEntered) {
        int tecla = e.text.unicode - '0';
        if (tecla >= 0 && tecla <= 9) {
          entrada += std::to_string(tecla);
        }
      }
      if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter) {
        enter_presionado = true;
      }
    }
  }
  return std::stoi(entrada);
}

int elegir_si_o_no(sf::RenderWindow* w) {
  bool opcion_tomada = false;
  int respuesta;
  sf::Event e;
  while (!opcion_tomada) {
    while ((*w).pollEvent(e)) {
      if (e.type == sf::Event::Closed)
      (*w).close();
      if (e.type == sf::Event::TextEntered) {
        int tecla = e.text.unicode - '0';
        if (tecla == 0 || tecla == 1) {
          respuesta = tecla;
          opcion_tomada = true;
        }
      }
    }
  }
  return respuesta;
}

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Menu multiusos");
  sf::Font font;
  if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
    return -1;
  }

  sf::Text menu;
  int eleccion;
  setMenu(&menu, &font);
  while (window.isOpen()) {
      window.clear();
      window.draw(menu);
      window.display();
      eleccion = seleciona_opcion_menu(&window);
      if (eleccion == 27) {
        int volver_intentar = 1;
        sf::Text t;
        while (volver_intentar) {
          window.clear();
          window.display();
          t.setString("Sucesion de fibonacci\n\n\n"
                      "Que posicion quieres?");
          t.setFont(font);
          t.setCharacterSize(24);
          t.setPosition(100, 100);
          window.draw(t);
          window.display();
          int n;
          n = ingresa_numero_positivo(&window);
          t.setString("La posicion "+std::to_string(n)+" es: "+std::to_string(fibonacci(n, 1, 1)));
          t.setPosition(100, 300);
          t.setFillColor(sf::Color::Cyan);
          window.draw(t);
          t.setString("Quieres volver a intentarlo?\n1 = si       0 = no");
          t.setPosition(100, 400);
          t.setFillColor(sf::Color::White);
          window.draw(t);
          window.display();
          volver_intentar = elegir_si_o_no(&window);
        }
      } else if (eleccion == 28) {
        int volver_intentar = 1;
        sf::Text t;
        while (volver_intentar) {
          window.clear();
          window.display();
          t.setString("Conversion decimal a binario\n"
          "Que numero quieres convertir? ");
          t.setFont(font);
          t.setCharacterSize(24);
          t.setPosition(100, 100);
          window.draw(t);
          window.display();
          int n;
          n = ingresa_numero_positivo(&window);
          t.setString("La posicion "+std::to_string(n)+" es: "+decimal_a_binario(n));
          t.setPosition(100, 300);
          t.setFillColor(sf::Color::Cyan);
          window.draw(t);
          t.setString("Quieres volver a intentarlo?\n1 = si       0 = no");
          t.setPosition(100, 400);
          t.setFillColor(sf::Color::White);
          window.draw(t);
          window.display();
          volver_intentar = elegir_si_o_no(&window);
        }
      } else if (eleccion == 29) {
        int volver_intentar = 1;
        sf::Text t;
        while (volver_intentar) {
          window.clear();
          window.display();
          int n, m;
          t.setString("Calculadora\n"
                      "Ingresa los operandos separados por un Enter: ");
          t.setFont(font);
          t.setCharacterSize(24);
          t.setPosition(100, 100);
          window.draw(t);
          window.display();
          n = ingresa_numero_positivo(&window);
          t.setString("n = "+std::to_string(n));
          t.setPosition(100, 150);
          window.draw(t);
          window.display();
          m = ingresa_numero_positivo(&window);
          t.setString("m = "+std::to_string(m));
          t.setPosition(300, 150);
          window.draw(t);
          t.setString("Suma: "+std::to_string(n+m)+"\n"
                      "Resta: "+std::to_string(n-m)+"\n"
                      "Multiplicacion: "+std::to_string(n*m)+"\n");
          t.setPosition(100, 200);
          t.setFillColor(sf::Color::Cyan);
          window.draw(t);
          if (m != 0) {
            t.setString("Division: "+std::to_string(n/m));
          } else {
            t.setString("No se puede dividir por cero.");
          }
          t.setPosition(100, 300);
          window.draw(t);
          t.setString("Quieres volver a intentarlo?\n1 = si       0 = no");
          t.setPosition(100, 400);
          t.setFillColor(sf::Color::White);
          window.draw(t);
          window.display();
          volver_intentar = elegir_si_o_no(&window);
        }
      } else if (eleccion == 30) {
        int volver_intentar = 1;
        sf::Text t;
        while (volver_intentar) {
          window.clear();
          window.display();
          int a, b, c, x;
          t.setString("Formula general\n"
                      "ingrese los valores: a, b, c. Seaparados por un Enter");
          t.setFont(font);
          t.setCharacterSize(24);
          t.setPosition(100, 100);
          window.draw(t);
          window.display();
          a = ingresa_numero_positivo(&window);
          t.setString("a = "+std::to_string(a));
          t.setPosition(100, 150);
          window.draw(t);
          window.display();
          b = ingresa_numero_positivo(&window);
          t.setString("b = "+std::to_string(b));
          t.setPosition(200, 150);
          window.draw(t);
          window.display();
          c = ingresa_numero_positivo(&window);
          t.setString("c = "+std::to_string(c));
          t.setPosition(300, 150);
          window.draw(t);
          x = chicharronera(a, b, c);
          t.setString("X = "+std::to_string(x)+"\n");
          t.setPosition(100, 200);
          t.setFillColor(sf::Color::Cyan);
          window.draw(t);
          t.setString("Quieres volver a intentarlo?\n1 = si       0 = no");
          t.setPosition(100, 400);
          t.setFillColor(sf::Color::White);
          window.draw(t);
          window.display();
          volver_intentar = elegir_si_o_no(&window);
        }
      } else {
        window.close();
      }
  }
  return 0;
}
