#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int fibonacci(int n, int acc1, int acc2){
  if (n == 0) {
    return acc1;
  }
  if (n == 1) {
    return acc1;
  }
  return fibonacci(n-1, acc1+acc2, acc1);
}

void opcion_fib() {
  int n;
  cout << "Sucesión de fibonacci" << endl;
  cout << "¿Qué posición quieres? ";
  cin >> n;
  while (n < 0) {
    cout << "Introduce un número mayor o igual a 0" << endl;
    cin >> n;
  }
  cout << "Respuesta: " << fibonacci(n, 1, 1) << endl;
}

string decimal_a_binario(int n) {
  string cadena_binaria = "";
  if (n == 0) { return "0"; }
  while (n > 0) {
    cadena_binaria += to_string(n % 2);
    n = n / 2;
  }
  reverse(cadena_binaria.begin(), cadena_binaria.end());
  return cadena_binaria;
}

void opcion_decimal_binario() {
  int n;
  cout << "Conversión decimal a binario" << endl;
  cout << "¿Qué número quieres convertir? ";
  cin >> n;
  while (n <0) {
    cout << "Introduce un número mayor o igual a 0" << endl;
    cin >> n;
  }
  cout << "Respuesta: " << decimal_a_binario(n) << endl;
}

void opcion_calculadora() {
  int n, m;
  cout << "Calculadora" << endl;
  cout << "Ingresa el primer operando: ";
  cin >> n;
  cout << "Ingresa el segundo operando: ";
  cin >> m;
  cout << "Suma: " << n+m << endl;
  cout << "Resta: " << n-m << endl;
  cout << "Multiplicación: " << n*m << endl;
  if (m != 0) {
    cout << "División: " << n/m << endl;
  } else {
    cout << "División: no se puede dividir por cero." << endl;
  }
}

int chicharronera(int a, int b, int c) {
  double x, numerador;
  int delta;
  delta = pow(b,2) - (4*a*c);
  numerador = -b+sqrt(delta);
  x = numerador / (2*a);
  return x;
}

void opcion_chicharronera() {
  int a, b, c;
  cout << "Formula general" << endl;
  cout << "Ingresa el término cuadrático: ";
  cin >> a;
  cout << "Ingresa el término lineal: ";
  cin >> b;
  cout << "Ingresa el término independiente: ";
  cin >> c;
  cout << "x = " << chicharronera(a, b, c) << endl;
}

void imprimir_menu() {
  cout << "Menú multiusos" << endl;
  cout << "1.- Realizar secuencia fibonacci" << endl;
  cout << "2.- Convertir decimal a binario" << endl;
  cout << "3.- Calculadora" << endl;
  cout << "4.- La chicharronera" << endl;
  cout << "5.- Salir" << endl;
  cout << "Ingresa la opcion deseada: ";
}

bool volver_intentar() {
  int eleccion;
  cout << "¿Quieres volver a intentarlo?" << endl;
  cout << "0 = No              1 = Si: ";
  cin >> eleccion;
  while (eleccion != 0 && eleccion!=1) {
    cout << "Por favor ingresa una opción valida." << endl;
    cin >> eleccion;
  }
  if (eleccion == 0) {
    return false;
  } else {
    return true;
  }
}

int main(){
  bool RUNNING, MANTENER_OPCION;
  int seleccion;
  RUNNING = true;
  while (RUNNING) {
    imprimir_menu();
    cin >> seleccion;
    MANTENER_OPCION = true;
    if (seleccion == 1) {
      while (MANTENER_OPCION) {
        opcion_fib();
        MANTENER_OPCION = volver_intentar();
      }
    } else if (seleccion == 2) {
      while (MANTENER_OPCION) {
        opcion_decimal_binario();
        MANTENER_OPCION = volver_intentar();
      }
    } else if (seleccion == 3) {
      while (MANTENER_OPCION) {
        opcion_calculadora();
        MANTENER_OPCION = volver_intentar();
      }
    } else if (seleccion == 4) {
      while (MANTENER_OPCION) {
        opcion_chicharronera();
        MANTENER_OPCION = volver_intentar();
      }
    } else if (seleccion == 5) {
      RUNNING = false;
    } else {
      cout << "Introduce un número válido." << endl;
    }
  }
  return 0;
}
