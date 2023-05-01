/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @file AB.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-05-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AB_H_
#define AB_H_

#include <iostream>
#include <queue>

#include "NodoB.h"

template <typename Key>
class AB {
 public:
  NodoB<Key>* getRoot() const;
  virtual bool insert(const Key& k) = 0;
  virtual bool search(const Key& k) const = 0;
  void inorder() const;
  void inorder(NodoB<Key>* node) const;
  void write();

 protected:
  NodoB<Key>* root_;
};

template <typename Key>
void AB<Key>::inorder() const {
  inorder(root_);
}

template <typename Key>
void AB<Key>::inorder(NodoB<Key>* node) const {
  if (root_ != nullptr) {
    inorder(node->getLeft());
    std::cout << node->getData() << " ";
    inorder(node->getRight());
  }
}

template <typename Key>
NodoB<Key>* AB<Key>::getRoot() const {
  return root_;
}

template <typename Key>
void AB<Key>::write() {
  int k = 0;
  std::queue<NodoB<Key>*> queue, queueAux;
  queue.push(root_);
  while (!queue.empty()) {
    std::cout << "Nivel " << k << ": ";
    while (!queue.empty()) {
      if (queue.front() != nullptr) {
        std::cout << "[" << queue.front()->getData() << "]";
        queueAux.push(queue.front()->getLeft());
        queueAux.push(queue.front()->getRight());
      } else {
        std::cout << "[.]";
      }
      queue.pop();
    }
    queue = queueAux;
    while (!queueAux.empty()) {
      queueAux.pop();
    }
    k++;
    std::cout << "\n\n";
  }
}

#endif  // AB_H_