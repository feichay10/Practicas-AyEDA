/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-05-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "include/Key.h"
#include "include/ABB.h"

const std::string kRedBold = "\033[31m\033[1m";
const std::string kGreenBold = "\033[32m\033[1m";
const std::string kCyanBold = "\033[36m\033[1m";
const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m"; 

typedef Key<long> keyType;

int main() {
  int option;

  std::cout << kBold << "Arboles de busqueda" << kReset << std::endl;
  std::cout << kRedBold << "  1." << kReset << kBold << " Árbol Binario de Búsqueda - ABB" << std::endl;
  std::cout << kRedBold << "  2." << kReset << kBold << " Árbol Binario de Búsqueda Balancedo - AVL" << std::endl;
  std::cout << "Seleccione tipo de arbol: "; 
  std::cin >> option;

  // AB<keyType> *tree;

  switch (option) {
    case 1: 
      // tree = new ABB<keyType>();
      break;
    case 2: 
      // tree = new AVL<keyType>();
      break;
    default: std::cout << "Opcion invalida" << std::endl;
      return 0;
  }

  while (true) {
    std::cout << kBold << "Operaciones" << kReset << std::endl;
    std::cout << kRedBold << "  [0]" << kReset << kBold << " Salir" << std::endl;
    std::cout << kRedBold << "  [1]" << kReset << kBold << " Insertar clave" << std::endl;
    std::cout << kRedBold << "  [2]" << kReset << kBold << " Buscar clave" << std::endl;
    std::cout << kRedBold << "  [3]" << kReset << kBold << " Mostrar arbol inorden" << std::endl;
    std::cout << "Seleccione operacion: "; 
    std::cin >> option;

    keyType key;

    switch (option) {
      case 0:
        exit(EXIT_SUCCESS);
        break;
      case 1: 
        std::cout << "Insetar clave: ";
        // std::cin >> key;
        // if (tree->insert(key)) {
        //   std::cout << "Clave insertada" << std::endl;
        // } else {
        //   std::cout << "Clave ya existente" << std::endl;
        // }
        break;
      case 2: 
        std::cout << "Buscar clave: ";
        // std::cin >> key;
        // std::cout << "Clave " << key << ": " << tree->search(key) << std::endl;
        break;
      case 3: 
        std::cout << "Mostrar arbol inorden: ";
        // tree->inorder();
        break;
      default: 
        std::cout << "Opcion invalida" << std::endl;
    }
    // mostrar arbol
    // tree->Write();
  }
}