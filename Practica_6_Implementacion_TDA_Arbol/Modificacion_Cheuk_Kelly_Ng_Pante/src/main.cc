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
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "../include/Key.h"
#include "../include/ABB.h"
#include "../include/AVL.h"

const std::string kRedBold = "\033[31m\033[1m";
const std::string kGreenBold = "\033[32m\033[1m";
const std::string kCyanBold = "\033[36m\033[1m";
const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m"; 

typedef Key<long> keyType;

int main() {
  int optionTree, option;

  std::cout << kBold << "Arboles de busqueda" << kReset << std::endl;
  std::cout << kRedBold << "  1." << kReset << kBold << " Árbol Binario de Búsqueda - ABB" << std::endl;
  std::cout << kRedBold << "  2." << kReset << kBold << " Árbol Binario de Búsqueda Balanceado - AVL" << std::endl;
  std::cout << "Seleccione tipo de arbol: " << kReset; 
  std::cin >> optionTree;

  AB<keyType> *tree;

  switch (optionTree) {
    case 1: 
      tree = new ABB<keyType>();
      break;
    case 2: 
      tree = new AVL<keyType>();
      break;
    default: std::cout << "Opcion invalida" << std::endl;
      exit(EXIT_FAILURE);
  }

  while (true) {
    std::cout << kBold << "\n\nOperaciones" << kReset << std::endl;
    std::cout << kRedBold << "  [0]" << kReset << kBold << " Salir" << std::endl;
    std::cout << kRedBold << "  [1]" << kReset << kBold << " Insertar clave" << std::endl;
    std::cout << kRedBold << "  [2]" << kReset << kBold << " Buscar clave" << std::endl;
    std::cout << kRedBold << "  [3]" << kReset << kBold << " Mostrar arbol inorden" << std::endl;
    std::cout << "Seleccione operacion: " << kReset; 
    std::cin >> option;

    keyType key;

    // Comprobar si el arbol está vacio
    if (tree->empty()) {
      std::cout << kBold << "\nArbol vacio" << kReset << std::endl;
      tree->write();
    }

    switch (option) {
      case 0:
        exit(EXIT_SUCCESS);
        break;
      case 1: 
        std::cout << kBold << "\nInsertar clave: " << kReset;
        std::cin >> key;
        tree->insert(key);
        break;
      case 2: 
        std::cout << kBold << "\nBuscar clave: " << kReset;
        std::cin >> key;
        if (tree->search(key)) {
          std::cout << kGreenBold << "Clave encontrada" << kReset << std::endl;
        } else {
          std::cout << kRedBold << "Clave no encontrada" << kReset << std::endl;
        }
        break;
      case 3: 
        std::cout << kBold << "\nMostrar arbol inorden: " << kReset << std::endl;
        tree->inorder();
        std::cout << std::endl;
        break;
      default: 
        std::cout << "Opcion invalida" << std::endl;
        std::cout << "\n\nSeleccione operacion: " << std::endl;
    }
    std::cout << std::endl;
    tree->write();
  }
}