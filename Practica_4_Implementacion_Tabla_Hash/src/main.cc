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
  std::cout << "\nSelecciona una técnica de dispersión: " << std::endl;
  std::cout << kRedBold << "  [1]." << kReset << kBold << " Abierta" << std::endl;
  std::cout << kRedBold << "  [2]." << kReset << kBold << " Cerrada" << std::endl;
  std::cin >> td;

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

  ExplorationFunction<keyType>* explorationFunction = nullptr;
  
  if (td == 1) {
    explorationFunction = new feLineal<keyType>;
  } else if (td == 2) {
    std::cout << "Introduce el tamaño del bloque: " << std::endl;
    std::cin >> blockSize;
    std::cout << "Selecciona una función de exploración: " << std::endl;
    std::cout << kRedBold << "  [L]." << kReset << kBold << " Lineal" << std::endl;
    std::cout << kRedBold << "  [Q]." << kReset << kBold << " Cuadrática" << std::endl;
    std::cout << kRedBold << "  [D]." << kReset << kBold << " Doble Dispersión" << std::endl;
    std::cout << kRedBold << "  [R]." << kReset << kBold << " Redispersión" << std::endl;
    std::cin >> fe;

    switch(fe) {
      case 'L':
      case 'l':
        explorationFunction = new feLineal<keyType>;
        break;
      case 'Q':
      case 'q':
        explorationFunction = new feQuadratic<keyType>;
        break;
      case 'D':
      case 'd':
        explorationFunction = new feDoubleDispersion<keyType>;
        break;
      case 'R':
      case 'r':
        explorationFunction = new feRedispersion<keyType>;
        break;
      default:
        std::cout << "Opción no válida" << std::endl;
        exit(EXIT_FAILURE);
    }
  } else {
    std::cout << "Opción no válida" << std::endl;
    exit(EXIT_FAILURE);
  }

  HashTable<keyType> hashTable(tableSize, dispersionFunction, explorationFunction, blockSize);

  int numInsert = 0;
  std::cout << "Introduce el número de elementos a insertar: ";
  std::cin >> numInsert;
  for (int i = 0; i < numInsert; i++) {
    int value = 0;
    std::cout << i + 1 << ") valor: " << std::endl;
    std::cin >> value;
    hashTable.insert(value);
  }
  
  hashTable.print();
}