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

#include "ABB.h"
#include "NodoAVL.h"

template <class Key>
class AVL : public ABB<Key> {
 public:
  AVL(bool trace = false, NodoAVL<Key>* node = nullptr);
  bool Insert(const Key& data);

 protected:
  void SetRoot(NodoAVL<Key>* root);
  NodoAVL<Key>*& GetRoot();
  NodoAVL<Key>* GetRoot() const;

 private:
  bool trace_{false};
  void rotation_II(NodoAVL<Key>*& node);
  void rotation_DD(NodoAVL<Key>*& node);
  void rotation_ID(NodoAVL<Key>*& node);
  void rotation_DI(NodoAVL<Key>*& node);
  void InsertaBal(NodoAVL<Key>*& root, NodoAVL<Key>*& newOne, bool& grow);
};

template <typename Key>
AVL<Key>::AVL(bool trace, NodoAVL<Key>* node) : trace_(trace) {
  this->AB<Key>::setRoot(node);
}

template <typename Key>
bool AVL<Key>::Insert(const Key& data) {
  NodoAVL<Key>* newOne = new NodoAVL<Key>(data);
  bool grow{false};
  this->InsertaBal(this->GetRoot(), newOne, grow);
  return grow;
}

template <typename Key>
void AVL<Key>::SetRoot(NodoAVL<Key>* root) {
  this->AB<Key>::SetRoot(root);
}

template <typename Key>
NodoAVL<Key>*& AVL<Key>::GetRoot() {
  return reinterpret_cast<NodoAVL<Key>*&>(this->AB<Key>::GetRoot());
}

template <typename Key>
NodoAVL<Key>* AVL<Key>::GetRoot() const {
  return reinterpret_cast<NodoAVL<Key>*>(this->AB<Key>::GetRoot());
}

template <typename Key>
void AVL<Key>::rotation_II(NodoAVL<Key>*& node) {
  NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(node->GetPtrIzdo());
  node->SetPtrIzdo(reinterpret_cast<NodoAVL<Key>*&>(nodo1->GetPtrDcho()));
  nodo1->SetPtrDcho(node);
  if (nodo1->GetBal() == 1) {
    node->SetBal(0);
    nodo1->SetBal(0);
  } else {  ///< nodo1->GetBal() == 0
    node->SetBal(1);
    nodo1->SetBal(-1);
  }
  node = nodo1;
}

template <typename Key>
void AVL<Key>::rotation_DD(NodoAVL<Key>*& node) {
  NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(node->GetPtrDcho());
  node->SetPtrDcho(reinterpret_cast<NodoAVL<Key>*&>(nodo1->GetPtrIzdo()));
  nodo1->SetPtrIzdo(node);
  if (nodo1->GetBal() == -1) {
    node->SetBal(0);
    nodo1->SetBal(0);
  } else {  ///< nodo1->GetBal() == 0
    node->SetBal(-1);
    nodo1->SetBal(1);
  }
  node = nodo1;
}

template <typename Key>
void AVL<Key>::rotation_ID(NodoAVL<Key>*& node) {
  NodoAVL<Key>* nodo1 = node->GetPtrIzdo();
  NodoAVL<Key>* nodo2 = nodo1->GetPtrDcho();
  node->GetPtrIzdo() = nodo2->GetPtrDcho();  ///< Es esta linea
  nodo2->SetPtrDcho(node);
  nodo1->SetPtrDcho(nodo2->GetPtrIzdo());
  nodo2->GetPtrIzdo() = nodo1;
  if (nodo2->GetBal() == -1)
    nodo1->SetBal(1);
  else
    nodo1->SetBal(0);
  if (nodo2->GetBal() == 1)
    node->SetBal(-1);
  else
    node->SetBal(0);
  nodo2->SetBal(0);
  node = nodo2;
}

template <typename Key>
void AVL<Key>::rotation_DI(NodoAVL<Key>*& node) {
  NodoAVL<Key>* nodo1 = node->GetPtrDcho();
  NodoAVL<Key>* nodo2 = nodo1->GetPtrIzdo();
  node->GetPtrDcho() = nodo2->GetPtrIzdo();  ///< Y esta otra
  nodo2->SetPtrIzdo(node);
  nodo1->SetPtrIzdo(nodo2->GetPtrDcho());
  nodo2->SetPtrDcho(nodo1);
  if (nodo2->GetBal() == 1)
    nodo1->SetBal(-1);
  else
    nodo1->SetBal(-1);
  if (nodo2->GetBal() == -1)
    node->SetBal(1);
  else
    node->SetBal(0);
  nodo2->SetBal(0);
  node = nodo2;
}

template <typename Key>
void AVL<Key>::InsertaBal(NodoAVL<Key>*& root, NodoAVL<Key>*& newOne, bool& grow) {
  if (root == NULL) {
    root = newOne;
    grow = true;
  } else if (newOne->getData() < root->getData()) {
    insertBal(reinterpret_cast<NodoAVL<Key>*&>(root->getLeft()), newOne, grow);
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
          if (reinterpret_cast<NodoAVL<Key>*&>(root->getLeft())->getBal() == -1) {
            rotation_II(root);
          } else {
            rotation_ID(root);
          }
          grow = false;
          break;
      }
    }
  } else if (newOne->getData() > root->getData()) {
    insertBal(reinterpret_cast<NodoAVL<Key>*&>(root->getRight()), newOne, grow);
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
          if (reinterpret_cast<NodoAVL<Key>*&>(root->getRight())->getBal() == 1) {
            rotation_DD(root);
          } else {
            rotation_DI(root);
          }
          grow = false;
          break;
      }
    }
  } else {
    std::cout << "Clave duplicada" << std::endl;
  }
}


#endif //AVL_H_