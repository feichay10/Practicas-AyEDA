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

#include <cstdlib>
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
const std::string kGreenBold = "\033[32m\033[1m";
const std::string kCyanBold = "\033[36m\033[1m";
const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m";

typedef long keyType;

int main() {
  int tableSize, td, blockSize, numInsert = 0;
  char fd, fe;

  std::cout << "Introduzca el tamaño de la tabla: ";
  std::cin >> tableSize;
  system("clear");
  std::cout << kBold << "###### Función de dispersión ######" << kReset << std::endl;
  std::cout << kRedBold << "  [M]." << kReset << " Módulo" << std::endl;
  std::cout << kRedBold << "  [S]." << kReset << " Basada en Suma" << std::endl;
  std::cout << kRedBold << "  [P]." << kReset << " Pseudoaleatoria" << std::endl;
  std::cout << "Introduzca el tipo de función de dispersión: ";
  std::cin >> fd;
  system("clear");

  DispersionFunction<keyType>* dispersionFunction;
  switch (fd) {
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

  std::cout << kBold << "###### Técnica de dispersión ######" << kReset << std::endl;
  std::cout << kRedBold << "  [1]." << kReset << " Abierta" << std::endl;
  std::cout << kRedBold << "  [2]." << kReset << " Cerrada" << std::endl;
  std::cout << "\nSelecciona una técnica de dispersión: ";
  std::cin >> td;
  system("clear");

  HashTable<keyType>* hashTable;
  ExplorationFunction<keyType>* explorationFunction;

  switch (td) {
    case 1:
      hashTable = new HashTable<keyType>(tableSize, dispersionFunction);
      break;
    case 2:
      std::cout << "Introduce el tamaño del bloque: ";
      std::cin >> blockSize;
      system("clear");
      std::cout << kBold << "###### Función de exploración ######" << std::endl;
      std::cout << kRedBold << "  [L]." << kReset << kBold << " Lineal" << std::endl;
      std::cout << kRedBold << "  [Q]." << kReset << kBold << " Cuadrática" << std::endl;
      std::cout << kRedBold << "  [D]." << kReset << kBold << " Doble Dispersión" << std::endl;
      std::cout << kRedBold << "  [R]." << kReset << kBold << " Redispersión" << std::endl;
      std::cout << "Selecciona una función de exploración: ";
      std::cin >> fe;

      switch (fe) {
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
      system("clear");
      hashTable = new HashTable<keyType>(tableSize, dispersionFunction, explorationFunction, blockSize);
      break;
    default:
      std::cout << "Opción no válida" << std::endl;
      exit(EXIT_FAILURE);
  };

  int option = 0;
  keyType element;

  do {
    std::cout << "###### Tabla de Hash ######" << std::endl;
    std::cout << kRedBold << "  [1]." << kReset << kBold << " Insertar" << std::endl;
    std::cout << kRedBold << "  [2]." << kReset << kBold << " Buscar" << std::endl;
    std::cout << kRedBold << "  [3]." << kReset << kBold << " Imprimir tabla" << std::endl;
    std::cout << kRedBold << "  [4]." << kReset << kBold << " Salir" << kReset << std::endl;
    std::cout << "Selecciona una opción: ";
    std::cin >> option;

    switch (option) {
      case 1:
        std::cout << "Introduce el número de elementos a insertar: ";
        std::cin >> numInsert;
        for (int i = 0; i < numInsert; ++i) {
          std::cout << i + 1 << ") Valor: ";
          std::cin >> element;
          hashTable->insert(element);
        }
        std::cout << std::endl;
        break;
      case 2:
        std::cout << "\nIntroduce el elemento a buscar: ";
        std::cin >> element;
        if (!hashTable->search(element)) {
          std::cout << "El elemento " << kCyanBold << element << kReset << kRedBold << " NO" << kReset << " no se encuentra en la tabla" << kReset << std::endl << std::endl;
        } else {
          std::cout << "El elemento " << kCyanBold << element << kReset << kGreenBold << " SI" << kReset << " se encuentra en la tabla" << kReset << std::endl << std::endl;
        }
        break;
      case 3:
        std::cout << "\nTabla de Hash: " << std::endl;
        hashTable->print();
        std::cout << std::endl;
        break;
      case 4:
        system("clear");
        exit(EXIT_SUCCESS);
      default:
        std::cout << "Opción no válida" << std::endl << std::endl;
    }
  } while (option != 4);
}