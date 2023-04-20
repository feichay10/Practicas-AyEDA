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

#include "../include/HeapSort.h"
#include "../include/Insertion.h"
#include "../include/Key.h"
#include "../include/MergeSort.h"
#include "../include/RadixSort.h"
#include "../include/ShellSort.h"
#include "../include/SortMethod.h"

const std::string kRedBold = "\033[31m\033[1m";
const std::string kGreenBold = "\033[32m\033[1m";
const std::string kCyanBold = "\033[36m\033[1m";
const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m";

typedef Key<long> keyType;

int main() {
  int vectorSize, generateOption, algorithmOption;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1000, 9999);

  std::cout << kBold << " ====== Algoritmos de Ordenación ====== " << std::endl;
  std::cout << "Introduzca el tamaño del vector: " << kReset;
  std::cin >> vectorSize;

  std::vector<keyType> vector(vectorSize);

  std::cout << kRedBold << "  1." << kReset << kBold << " Aleatorio" << std::endl;
  std::cout << kRedBold << "  2." << kReset << kBold << " Manual" << std::endl;
  std::cout << "Introduzca como quiere rellenar el vector: " << kReset;
  std::cin >> generateOption;

  system("clear");
  switch (generateOption) {
    case 1:
      std::cout << kBold << "Vector aleatorio" << kReset << std::endl;
      for (int i = 0; i < vectorSize; i++) {
        vector[i] = dis(gen);
      }
      std::cout << "El vector generado aleatoriamente es: " << std::endl;
      break;
    case 2:
      std::cout << kBold << "Vector manual" << kReset << std::endl;
      std::cout << "Introduzca hasta " << vectorSize << " números para el vector: " << std::endl;
      for (int i = 0; i < vectorSize; i++) {
        std::cout << "Número " << kRedBold << i << kReset << " del vector: ";
        std::cin >> vector[i];
      }
      std::cout << "El vector es: " << std::endl;
      break;
    default:
      std::cout << "Opción no válida" << std::endl;
      exit(EXIT_FAILURE);
      break;
  }

  std::cout << kCyanBold << "[ ";
  for (int i = 0; i < vectorSize; i++) {
    std::cout << vector[i] << " ";
  }
  std::cout << "]" << kReset << std::endl;

  std::cout << "\nSeleccione algun algoritmo de ordenación: " << std::endl;
  std::cout << kRedBold << "  1." << kReset << kBold << " Inserción" << std::endl;
  std::cout << kRedBold << "  2." << kReset << kBold << " MergeSort" << std::endl;
  std::cout << kRedBold << "  3." << kReset << kBold << " ShellSort" << std::endl;
  std::cout << kRedBold << "  4." << kReset << kBold << " HeapSort"  << std::endl;
  std::cout << kRedBold << "  5." << kReset << kBold << " RadixSort" << std::endl;
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
      sortMethod = new HeapSort<keyType>();
      break;
    case 5:
      sortMethod = new RadixSort<keyType>();
      break;
    default:
      std::cout << "Opción no válida" << std::endl;
      exit(EXIT_FAILURE);
      break;
  }

#ifdef TRAZA
  std::cout << "\nOrdenando..." << std::endl;
#endif

  sortMethod->Sort(vector, vectorSize);
  std::cout << "\n\nVector ordenado es: " << std::endl;
  std::cout << kGreenBold << "[ ";
  for (int i = 0; i < vectorSize; i++) {
    std::cout << vector[i] << " ";
  }
  std::cout << "]" << kReset << std::endl;
  std::cout << std::endl;
  return 0;
}
