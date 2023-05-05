/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @file AVL.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVL_H_
#define AVL_H_

#include <iostream>

#include "AB.h"
#include "ABB.h"
#include "NodoAVL.h"

template <class Key>
class AVL : public ABB<Key> {
 public:
  AVL(bool trace = false, NodoAVL<Key>* node = nullptr);
  bool insert(const Key& data) override;

 protected:
  void setRoot(NodoAVL<Key>* root);
  NodoAVL<Key>*& getRoot();
  NodoAVL<Key>* getRoot() const;

 private:
  bool trace_ = false;
  void rotation_II(NodoAVL<Key>*& node);
  void rotation_DD(NodoAVL<Key>*& node);
  void rotation_ID(NodoAVL<Key>*& node);
  void rotation_DI(NodoAVL<Key>*& node);
  void insertBal(NodoAVL<Key>*& root, NodoAVL<Key>*& newOne, bool& grow);
};

template <typename Key>
AVL<Key>::AVL(bool trace, NodoAVL<Key>* node) {
  this->trace_ = trace;
  this->AB<Key>::setRoot(node);
}

template <typename Key>
bool AVL<Key>::insert(const Key& data) {
  NodoAVL<Key>* newOne = new NodoAVL<Key>(data);
  bool grow = false;
  this->insertBal(this->getRoot(), newOne, grow);
  return grow;
}

template <typename Key>
void AVL<Key>::setRoot(NodoAVL<Key>* root) {
  this->AB<Key>::setRoot(root);
}

template <typename Key>
NodoAVL<Key>*& AVL<Key>::getRoot() {
  return reinterpret_cast<NodoAVL<Key>*&>(this->AB<Key>::getRoot());
}

template <typename Key>
NodoAVL<Key>* AVL<Key>::getRoot() const {
  return reinterpret_cast<NodoAVL<Key>*>(this->AB<Key>::getRoot());
}

template <typename Key>
void AVL<Key>::rotation_II(NodoAVL<Key>*& node) {
  #ifdef TRAZA
    std::cout << "Rotación II en [" << node->getData() << "]";
  #endif
  NodoAVL<Key>* node1 = reinterpret_cast<NodoAVL<Key>*&>(node->getLeft());
  node->setLeft(reinterpret_cast<NodoAVL<Key>*&>(node1->getRight()));
  node1->setRight(node);
  if (node1->getBal() == 1) {
    node->setBal(0);
    node1->setBal(0);
  } else {
    node->setBal(1);
    node1->setBal(-1);
  }
  node = node1;
}

template <typename Key>
void AVL<Key>::rotation_DD(NodoAVL<Key>*& node) {
  #ifdef TRAZA
    std::cout << "Rotación DD en [" << node->getData() << "]";
  #endif
  NodoAVL<Key>* node1 = reinterpret_cast<NodoAVL<Key>*&>(node->getRight());
  node->setRight(reinterpret_cast<NodoAVL<Key>*&>(node1->getLeft()));
  node1->setLeft(node);
  if (node1->getBal() == -1) {
    node->setBal(0);
    node1->setBal(0);
  } else {
    node->setBal(-1);
    node1->setBal(1);
  }
  node = node1;
}

template <typename Key>
void AVL<Key>::rotation_ID(NodoAVL<Key>*& node) {
  #ifdef TRAZA
    std::cout << "Rotación ID en [" << node->getData() << "]";
  #endif
  NodoAVL<Key>* node1 = node->getLeft();
  NodoAVL<Key>* node2 = node1->getRight();
  node->getLeft() = node2->getRight();
  node2->setRight(node);
  node1->setRight(node2->getLeft());
  node2->getLeft() = node1;
  if (node2->getBal() == -1) {
    node->setBal(1);
  } else {
    node->setBal(0);
  }
  if (node2->getBal() == 1) {
    node1->setBal(-1);
  } else {
    node1->setBal(0);
  }
  node2->setBal(0);
  node = node2;
}

template <typename Key>
void AVL<Key>::rotation_DI(NodoAVL<Key>*& node) {
  #ifdef TRAZA
    std::cout << "Rotación DI en [" << node->getData() << "]";
  #endif
  NodoAVL<Key>* node1 = node->getRight();
  NodoAVL<Key>* node2 = node1->getLeft();
  node->getRight() = node2->getLeft();
  node2->setLeft(node);
  node1->setLeft(node2->getRight());
  node2->setRight(node1);
  if (node2->getBal() == 1) {
    node1->setBal(-1);
  } else {
    node1->setBal(-1);
  }
  if (node2->getBal() == -1) {
    node->setBal(1);
  } else {
    node->setBal(0);
  }
  node2->setBal(0);
  node = node2;
}

template <typename Key>
void AVL<Key>::insertBal(NodoAVL<Key>*& root, NodoAVL<Key>*& newOne, bool& grow) {
  if (root == nullptr) {
    root = newOne;
    grow = true;
  } else if (newOne->getData() < root->getData()) { // Insertar balanceado por la izquierda
    insertBal(reinterpret_cast<NodoAVL<Key>*&>(root->getLeft()), newOne, grow);
    if (grow) {
      switch (root->getBal()) {
        case -1:
          root->setBal(0);
          grow = false;
          break;
        case 0:
          root->setBal(1);
          break;
        case 1:
          #ifdef TRAZA
            std::cout << "Desbalanceo: " << std::endl;
            this->write();
          #endif
          NodoAVL<Key>* node1 = reinterpret_cast<NodoAVL<Key>*&>(root->getLeft());
          if (node1->getBal() == 1) {
            rotation_II(root);
          } else {
            rotation_ID(root);
          }
          grow = false;
      }
    }
  } else if (newOne->getData() > root->getData()) { // Insertar balanceado por la derecha
    insertBal(reinterpret_cast<NodoAVL<Key>*&>(root->getRight()), newOne, grow);
    if (grow) {
      switch (root->getBal()) {
        case 1:
          root->setBal(0);
          grow = false;
          break;
        case 0:
          root->setBal(-1);
          break;
        case -1:
          #ifdef TRAZA
            std::cout << "Desbalanceo: " << std::endl;
            this->write();
          #endif
          NodoAVL<Key>* node1 = reinterpret_cast<NodoAVL<Key>*&>(root->getRight());
          if (node1->getBal() == -1) {
            rotation_DD(root);
          } else {
            rotation_DI(root);
          }
          grow = false;
      }
    }
  } else {
    std::cout << "\033[31m\033[1m" << "Clave duplicada" << "\033[0m" << std::endl;
  }
}

#endif  // AVL_H_