#include <iostream>
#include <string>

int *puntero;

std::string arrayToString(int* arr, int n) {
  std::string acc = "[";
  for (int i = 0; i < n; i++) {
    acc += std::to_string(arr[i]);
    if (i != n-1) acc += ", ";
  }
  acc += "]";
  return acc;
}

void arrayToStringApuntadores(int* arr, int n){
  std::cout << arrayToString(arr, n) << '\n';
  for (int* i = arr; i < arr+n; i++) {
    std::cout << i << " " << *i << '\n';
  }
}

void bubbleSort_regular(int* arr, int n) {
  std::cout << "Bubble Sort" << '\n';
  std::cout << arrayToString(arr, n) << '\n';
  for (int i = n-1; i >= 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (arr[j-1] > arr[j]) {
        int swap = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = swap;
      }
    }
  }
  std::cout << arrayToString(arr, n) << '\n';
}

void bubbleSort_apuntadores(int* arr, int n) {
  std::cout << "Bubble Sort" << '\n';
  arrayToStringApuntadores(arr, n);
  for (int* i = arr+n-1; i >= arr; i--) {
    for (int* j = arr+1; j <= i; j++) {
      if (*(j-1) > *j) {
        int swap = *(j-1);
        *(j-1) = *j;
        *j = swap;
      }
    }
  }
  arrayToStringApuntadores(arr, n);
}

int partition(int* arr, int izquierda, int derecha) {
  int pivote = arr[izquierda];
  int I = izquierda, D = derecha;
  while (I < D) {
    while (arr[I] <= pivote && I <= derecha) {
      I++;
    }
    while (arr[D] > pivote && D >= izquierda) {
      D--;
    }
    if (I < D) {
      int swap = arr[I];
      arr[I] = arr[D];
      arr[D] = swap;
    }
  }
  int mitad = D;
  int swap = arr[izquierda];
  arr[izquierda] = arr[mitad];
  arr[mitad] = swap;
  return mitad;
}

int* partition_apuntadores(int* arr, int* izquierda, int* derecha) {
  int pivote = *izquierda;
  int* I = izquierda;
  int* D = derecha;
  while (I < D) {
    while (*I <= pivote && I <= derecha) {
      I++;
    }
    while (*D > pivote && D >= izquierda) {
      D--;
    }
    if (I < D) {
      int swap = *I;
      *I = *D;
      *D = swap;
    }
  }
  int* mitad = D;
  int swap = *izquierda;
  *izquierda = *mitad;
  *mitad = swap;
  return D;
}

void q_sort(int* arr, int izquierda, int derecha) {
  if (izquierda < derecha) {
    int mitad = partition(arr, izquierda, derecha);
    q_sort(arr, izquierda, mitad-1);
    q_sort(arr, mitad+1, derecha);
  }
}

void q_sort_a(int* arr, int* izquierda, int* derecha) {
  if (izquierda < derecha) {
    int* mitad = partition_apuntadores(arr, izquierda, derecha);
    q_sort_a(arr, izquierda, mitad-1);
    q_sort_a(arr, mitad+1, derecha);
  }
}

void quickSort_regular(int* arr, int n) {
  std::cout << "Quick Sort" << '\n';
  std::cout << arrayToString(arr, n) << '\n';
  q_sort(arr, 0, n-1);
  std::cout << arrayToString(arr, n) << '\n';
}

void quickSort_apuntadores(int* arr, int n) {
  std::cout << "Quick Sort" << '\n';
  arrayToStringApuntadores(arr, n);
  q_sort_a(arr, arr, arr+n-1);
  arrayToStringApuntadores(arr, n);
}

void insertionSort_regular(int* arr, int n) {
  std::cout << "Insertion Sort" << '\n';
  std::cout << arrayToString(arr, n) << '\n';
  int j, indice;
  for (int i = 1; i < n; i++) {
    indice = arr[i];
    j = i;
    while (j > 0 &&  arr[j-1] > indice) {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = indice;
  }
  std::cout << arrayToString(arr, n) << '\n';
}

void insertionSort_apuntadores(int* arr, int n) {
  std::cout << "Insertion Sort" << '\n';
  arrayToStringApuntadores(arr, n);
  int indice;
  int* j;
  for (int* i = arr+1; i < arr+n; i++) {
    indice = *i;
    j = i;
    while (j > arr && *(j-1) > indice) {
      *j = *(j-1);
      j--;
    }
    *j = indice;
  }
  arrayToStringApuntadores(arr, n);
}

int* creaArreglo(int n) {
  puntero = new int[n];
  for (int i = 0; i < n; i++) {
    std::cout << "ingrese valor de la posición " << i << ": ";
    std::cin >> puntero[i];
  }
  return puntero;
}

int main() {
  int n, ordenamiento, tipo;
  std::cout << "Ingresa el tamaño del arreglo: ";
  std::cin >> n;
  int *arreglo = creaArreglo(n);
  std::cout << "¿Qué tipo de arreglo quieres?" << '\n';
  std::cout << "1)  Bubble Sort" << '\n';
  std::cout << "2)  Quick Sort" << '\n';
  std::cout << "3)  Insertion Sort" << '\n';
  std::cin >> ordenamiento;
  std::cout << "Forma de ordenar:" << '\n';
  std::cout << "1)  Regular" << '\n';
  std::cout << "2)  Punteros" << '\n';
  std::cin >> tipo;
  if (tipo == 1) {
    if (ordenamiento == 1) {
      bubbleSort_regular(arreglo, n);
    } else if (ordenamiento == 2) {
      quickSort_regular(arreglo, n);
    } else {
      insertionSort_regular(arreglo, n);
    }
  } else {
    if (ordenamiento == 1) {
      bubbleSort_apuntadores(arreglo, n);
    } else if (ordenamiento == 2) {
      quickSort_apuntadores(arreglo, n);
    } else {
      insertionSort_apuntadores(arreglo, n);
    }
  }
  delete [] puntero;
  return 0;
}
