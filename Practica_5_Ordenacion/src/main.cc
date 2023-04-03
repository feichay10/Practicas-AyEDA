/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <random>
#include <vector>

#include "../include/SortMethod.h"
#include "../include/HeapSort.h"
#include "../include/Insertion.h"
#include "../include/MergeSort.h"
#include "../include/RadixSort.h"
#include "../include/ShellSort.h"

// typedef Key<int> keyType;
typedef long keyType;

int main() {
  int vectorSize, generateOption, algorithmOption;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1000, 9999);

  std::cout << " ====== Algoritmos de Ordenación ====== " << std::endl;
  std::cout << "Introduzca el tamaño del vector: ";
  std::cin >> vectorSize;

  std::vector<long> vector(vectorSize);

  std::cout << "  1. Aleatorio" << std::endl;
  std::cout << "  2. Manual" << std::endl;
  std::cout << "Introduzca como quiere rellenar el vector: ";
  std::cin >> generateOption;

  switch(generateOption) {
    case 1:
      std::cout << "Vector aleatorio" << std::endl;
      for (int i = 0; i < vectorSize; i++) {
        vector[i] = dis(gen);
      }
      break;
    case 2:
      std::cout << "Introduzca hasta " << vectorSize << " números para el vector: " << std::endl;
      for (int i = 0; i < vectorSize; i++) {
        std::cout << "Número " << i << " del vector: ";
        std::cin >> vector[i];
      }  
      break;
    default:
      std::cout << "Opción no válida" << std::endl;
      break;
  }

  std::cout << "El vector es: " << std::endl;
  std::cout << "[ ";
  for (int i = 0; i < vectorSize; i++) {
    std::cout << vector[i] << " ";
  }
  std::cout << "]" << std::endl;
  std::cout << std::endl;

  std::cout << "Seleccione algun algoritmo de ordenación: " << std::endl;
  std::cout << "  1. Inserción" << std::endl;
  std::cout << "  2. MergeSort" << std::endl;
  std::cout << "  3. ShellSort" << std::endl;
  std::cout << "  4. HeapSort" << std::endl;
  std::cout << "  5. RadixSort" << std::endl;
    std::cout << "Seleccione el algoritmo de ordenación: ";
  std::cin >> algorithmOption;

  SortMethod<keyType> *sortMethod;

  switch (algorithmOption) {
    case 1:
      sortMethod = new Insertion<keyType>();
      break;
    case 2:
      sortMethod = new MergeSort<keyType>();
      break;
    case 3:
      sortMethod = new ShellSort<keyType>();
      break;
    case 4:
      // sortMethod = new HeapSort<keyType>();
      break;
    case 5:
      // sortMethod = new RadixSort<keyType>();
      break;
    default:
      std::cout << "Opción no válida" << std::endl;
      break;
  } 

  std::cout << "\nOrdenando... " << std::endl;
  sortMethod->Sort(vector, vectorSize);
  std::cout << "Vector ordenado: " << std::endl;
  for (int i = 0; i < vectorSize; i++) {
    std::cout << vector[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}

