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

// Generar dos arboles, ABB y AVL con 5000 datos aleatorios que van desde 0 hasta 50000, los dos arboles con los mismos datos
// Nº valores a insertar: mostrar el numero de valores insertados
// Calcular la altura del subarbol izquierdo y la del subarbol derecho y mostrar:
// ABB - Dif altura:
// AVL - Dif altura:

// Modo traza: 49, 27, 5 rotation, 45, 40, 41 rotacion, 17

// COMPILAR CON: make modificacion

#include <iostream>
#include <random>

#include "../include/Key.h"
#include "../include/ABB.h"
#include "../include/AVL.h"

typedef Key<long> keyType;

int main() {
  AB<keyType> *tree_abb; 
  AB<keyType> *tree_avl; 
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 50000);
  keyType random;
  int count_abb = 0, count_avl = 0;

  tree_abb = new ABB<keyType>();
  tree_avl = new AVL<keyType>();

  // Fallo en el insert del AVL
  for (int i = 0; i < 5000; i++) { 
    random = dis(gen);
    if (tree_abb->insert(random)) {
      ++count_abb;
    }
    if (tree_avl->insert(random)) {
      ++count_avl;
    }
  }

  std::cout << "Numero de valores insertados en el arbol ABB: " << count_abb << std::endl;
  std::cout << "Numero de valores insertado en el arbol AVL: " << count_avl << std::endl << std::endl;

  std::cout << "ABB: " << std::endl;
  std::cout << "Altura del subarbol izquierdo: " << tree_abb->height(tree_abb->getRoot()->getLeft()) << std::endl;
  std::cout << "Altura del subarbol derecho: " << tree_abb->height(tree_abb->getRoot()->getRight()) << std::endl;
  std::cout << "La diferencia altura entre los subarboles: " << tree_abb->height(tree_abb->getRoot()->getLeft()) - tree_abb->height(tree_abb->getRoot()->getRight()) << std::endl;

  std::cout << "\nAVL: " << std::endl;
  std::cout << "Altura del subarbol izquierdo: " << tree_avl->height(tree_avl->getRoot()->getLeft()) << std::endl;
  std::cout << "Altura del subarbol derecho: " << tree_avl->height(tree_avl->getRoot()->getRight()) << std::endl;
  std::cout << "La diferencia altura entre los subarboles: " << tree_avl->height(tree_avl->getRoot()->getLeft() - tree_avl->height(tree_avl->getRoot()->getRight())) << std::endl;
}