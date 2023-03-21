/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>

#include "../include/fdmodule.h"
#include "../include/fdrandom.h"
#include "../include/fdsum.h"
#include "../include/fedoubledispersion.h"
#include "../include/felineal.h"
#include "../include/fequadratic.h"
#include "../include/feredispersion.h"
#include "../include/hashtable.h"

const std::string kRedBold = "\033[31m\033[1m";
const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m";

typedef long keyType;

int main() {
  int tableSize, td, blockSize;
  char fd, fe;

  std::cout << "Introduzca el tamaño de la tabla: ";
  std::cin >> tableSize;
  std::cout << "Introduzca el tipo de función de dispersión: " << std::endl;
  std::cout << kRedBold << "  [M]." << kReset << kBold << " Módulo" << std::endl;
  std::cout << kRedBold << "  [S]." << kReset << kBold << " Basada en Suma"  << std::endl;
  std::cout << kRedBold << "  [P]." << kReset << kBold << " Pseudoaleatoria" << std::endl;
  std::cin >> fd;

  DispersionFunction<keyType>* dispersionFunction;
  switch(fd) {
    case 'M':
    case 'm':
      dispersionFunction = new fdModule<keyType>(tableSize);
      break;
    case 'S':
    case 's':
      dispersionFunction = new fdSum<keyType>(tableSize);
      break;
    case 'P':
    case 'p':
      dispersionFunction = new fdRandom<keyType>(tableSize);
      break;
    default:
      std::cout << "Opción no válida" << std::endl;
      exit(EXIT_FAILURE);
  };

  std::cout << "\n\nSelecciona una técnica de dispersión: " << std::endl;
  std::cout << kRedBold << "  [1]." << kReset << kBold << " Abierta" << std::endl;
  std::cout << kRedBold << "  [2]." << kReset << kBold << " Cerrada" << std::endl;
  std::cin >> td;

  HashTable<keyType>* hashTable;
  switch(td) {
    case 1:

    case 2:

    default:
      std::cout << "Opción no válida" << std::endl;
      exit(EXIT_FAILURE);
  };
}