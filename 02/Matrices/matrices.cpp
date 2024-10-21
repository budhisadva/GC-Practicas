#include <iostream>
#include <string>

std::string array_to_string(int**& matriz, int filas, int columnas) {
  std::string acc = "[";
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if (i != filas-1 || j != columnas-1) {
        acc += std::to_string(*(*(matriz+i)+j))+" ";
      } else {
        acc += std::to_string(*(*(matriz+i)+j))+"]";
      }
    }
    if (i != filas-1) {
      acc += "\n";
    }
  }
  return acc;
}

void crear_matriz(int**& matriz, int filas, int columnas) {
  matriz = new int*[filas];
  for (int i = 0; i < filas; i++) {
    matriz[i] = new int[columnas];
  }
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      std::cout << "Ingrese valor para [" << i << "][" << j << "]: ";
      std::cin >> *(*(matriz+i)+j);
    }
  }
}

void suma_matrices(int**& M_a, int filas_a, int columnas_a, int**& M_b, int filas_b, int columnas_b) {
  if (filas_a != filas_b || columnas_a != columnas_b) {
    std::cout << "No se puede realizar la operacion" << '\n';
    std::cout << "Las dimenciones deben ser iguales" << '\n';
    return;
  }
  std::cout << "Matriz A" << '\n';
  std::cout << array_to_string(M_a, filas_a, columnas_a) << '\n';
  std::cout << "Matriz B" << '\n';
  std::cout << array_to_string(M_b, filas_b, columnas_b) << '\n';
  int **M_suma = new int*[filas_a];
  for (int i = 0; i < filas_a; i++) {
    M_suma[i] = new int[columnas_a];
  }
  for (int i = 0; i < filas_b; i++) {
    for (int j = 0; j < columnas_b; j++) {
      *(*(M_suma+i)+j) = *(*(M_a+i)+j) + *(*(M_b+i)+j);
    }
  }
  std::cout << "Matriz C = A + B" << '\n';
  std::cout << array_to_string(M_suma, filas_b, columnas_b) << '\n';
  for (int i = 0; i < filas_a; i++) {
    delete[] M_suma[i];
  }
  delete[] M_suma;
}

void producto_matrices(int**& M_a, int filas_a, int columnas_a, int**& M_b, int filas_b, int columnas_b) {
  if (filas_a != filas_b || columnas_a != columnas_b) {
    std::cout << "No se puede realizar la operacion" << '\n';
    std::cout << "Las dimenciones deben ser iguales" << '\n';
    return;
  }
  std::cout << "Matriz A" << '\n';
  std::cout << array_to_string(M_a, filas_a, columnas_a) << '\n';
  std::cout << "Matriz B" << '\n';
  std::cout << array_to_string(M_b, filas_b, columnas_b) << '\n';
  int acc = 0;
  for (int i = 0; i < filas_b; i++) {
    for (int j = 0; j < columnas_b; j++) {
      acc += *(*(M_a+i)+j) * *(*(M_b+i)+j);
    }
  }
  std::cout << "El resultado es: " << acc << '\n';
}

void igualdad_matrices(int**& M_a, int filas_a, int columnas_a, int**& M_b, int filas_b, int columnas_b) {
  if (filas_a != filas_b || columnas_a != columnas_b) {
    std::cout << "No se puede realizar la operacion" << '\n';
    std::cout << "Las dimenciones deben ser iguales" << '\n';
    return;
  }
  std::cout << "Matriz A" << '\n';
  std::cout << array_to_string(M_a, filas_a, columnas_a) << '\n';
  std::cout << "Matriz B" << '\n';
  std::cout << array_to_string(M_b, filas_b, columnas_b) << '\n';
  bool acc = true;
  for (int i = 0; i < filas_b; i++) {
    for (int j = 0; j < columnas_b; j++) {
      acc = acc && ( *(*(M_a+i)+j) == *(*(M_b+i)+j) );
    }
  }
  if (acc) {
    std::cout << "Las matrices son iguales" << '\n';
  } else {
    std::cout << "Las matrices no son iguales" << '\n';
  }
}

int main() {
  int filas_a, filas_b, columnas_a, columnas_b, opcion;
  int **matrix_a, **matrix_b;
  bool continuar = true;
  while (continuar) {
    std::cout << "Matriz A" << '\n';
    std::cout << "Ingrese número de columnas: ";
    std::cin >> columnas_a;
    std::cout << "Ingrese número de filas: ";
    std::cin >> filas_a;
    crear_matriz(matrix_a, filas_a, columnas_a);
    // ---------------------------------------
    std::cout << "Matriz B" << '\n';
    std::cout << "Ingrese número de columnas: ";
    std::cin >> columnas_b;
    std::cout << "Ingrese número de filas: ";
    std::cin >> filas_b;
    crear_matriz(matrix_b, filas_b, columnas_b);
    std::cout << "¿Qué operación quieres realizar?" << '\n';
    std::cout << "1)  Suma" << '\n';
    std::cout << "2)  Productos escalar" << '\n';
    std::cout << "3)  Comparacion de igualdad" << '\n';
    std::cin >> opcion;
    if (opcion == 1) {
      suma_matrices(matrix_a, filas_a, columnas_a, matrix_b, filas_b, columnas_b);
    } else if (opcion == 2) {
      producto_matrices(matrix_a, filas_a, columnas_a, matrix_b, filas_b, columnas_b);
    } else {
      igualdad_matrices(matrix_a, filas_a, columnas_a, matrix_b, filas_b, columnas_b);
    }
    std::cout << "¿Quieres intentarlo otra vez?" << '\n';
    std::cout << "0) no" << '\n';
    std::cout << "1) sí" << '\n';
    std::cin >> continuar;
  }
  for (int i = 0; i < filas_a; i++) {
    delete[] matrix_a[i];
    delete[] matrix_b[i];
  }
  delete[] matrix_a;
  delete[] matrix_b;
  return 0;
}
