/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file main_modification.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

// Compilar con makefile -> make modificacion

// MODIFICACION - Se ha modificado el codigo para que se pueda contar el numero de asignaciones
// Elegir una tecnica de ordenacion, pero en lugar de ejecutar con un tamaño de vector, es generar
// es utilizar un vector de tamaño aleatorio, y ejecutar el algoritmo de ordenacion con ese vector
// tamaño 100, 1000 y 10000 elementos

// La idea es quedarnos con el numero de comparaciones (asignaciones) numero de asignaciones de clave
// que se utilizan al realizar la operacion. Para contarlos lo haremos con una clave que tendra un campo que
// actue como clave (clase) y añadimos un contador estatico (static<long> counter) y añadimos el metodo numerico
// de asignacion 

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
  Key<long> key;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1000, 9999);

  std::vector<keyType> vectorOneHundred(100);
  std::vector<keyType> vectorOneThousand(1000);
  std::vector<keyType> vectorTenThousand(10000);

  for (int i = 0; i < 100; i++) {
    vectorOneHundred[i] = dis(gen);
  }

  for (int i = 0; i < 1000; i++) {
    vectorOneThousand[i] = dis(gen);
  }

  for (int i = 0; i < 10000; i++) {
    vectorTenThousand[i] = dis(gen);
  }

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

  sortMethod->Sort(vectorOneHundred, vectorOneHundred.size());
  std::cout << kBold << "\n\nVector ordenado de 100 elementos: " << kReset << std::endl;
  std::cout << kBold << "Número de comparaciones: " << kReset << key.get_counter() << std::endl;

  sortMethod->Sort(vectorOneThousand, vectorOneThousand.size());
  std::cout << kBold << "\n\nVector ordenado de 1000 elementos: " << kReset << std::endl;
  std::cout << kBold << "Número de comparaciones: " << kReset << key.get_counter() << std::endl;

  sortMethod->Sort(vectorTenThousand, vectorTenThousand.size());
  std::cout << kBold << "\n\nVector ordenado de 10000 elementos: " << kReset << std::endl;
  std::cout << kBold << "Número de comparaciones: " << kReset << key.get_counter() << std::endl;
  return 0;
}