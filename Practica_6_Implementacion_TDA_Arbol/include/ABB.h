/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @file ABB.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-05-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ABB_H_
#define ABB_H_

#include "AB.h"

template <class Key>
class ABB : public AB<Key> {
  bool insertBranch(NodoB<Key>*& node, Key k);
  bool searchBranch(NodoB<Key>* node, Key k) const;

  // methods from AB class
  bool insert(const Key& k);
  bool search(const Key& k) const;
};

template <class Key>
bool ABB<Key>::insert(const Key& k) {
  if (this->getRoot() == nullptr) {
    AB<Key>::root_ = new NodoB<Key>(k);
    return true;
  } else {
    return insertBranch(AB<Key>::root_, k);
  }
}

template <class Key>
bool ABB<Key>::insertBranch(NodoB<Key>*& node, Key k) {
  if (search(k)) {
    return false;
  }
  if (node == nullptr) {
    node = new NodoB<Key>(k);
  } else if (k < node->getData()) {
    insertBranch(node->getLeft(), k);
  } else {
    insertBranch(node->getRight(), k);
  }
  return true;
}

template <class Key>
bool ABB<Key>::search(const Key& k) const {
  return searchBranch(this->getRoot(), k);
}

template <class Key>
bool ABB<Key>::searchBranch(NodoB<Key>* node, Key k) const {
  if (node == nullptr) {
    return false;
  }
  if (k == node->getData()) {
    return true;
  }
  if (k < node->getData()) {
    return searchBranch(node->getLeft(), k);
  }
  return searchBranch(node->getRight(), k);
}

#endif  // ABB_H_