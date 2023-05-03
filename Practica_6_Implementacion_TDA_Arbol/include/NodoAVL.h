/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @file NodoAVL.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-05-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NODOAVL_H_
#define NODOAVL_H_

#include "NodoB.h"

template <class Key>
class NodoAVL : public NodoB<Key>{
 public:
  NodoAVL();
  NodoAVL(const Key& data, NodoAVL<Key>* left = NULL, NodoAVL<Key>* right = NULL);
  ~NodoAVL() = default;

  int getBal();
  NodoAVL<Key>* getLeft() const;
  NodoAVL<Key>*& getLeft();
  NodoAVL<Key>* getRight() const;
  NodoAVL<Key>*& getRight();
  void setBal(const int& bal);
  void setLeft(NodoAVL<Key>* &left = NULL);
  void setRight(NodoAVL<Key>* &right = NULL);

  NodoAVL<Key>& operator=(const NodoAVL<Key>& node);
  friend std::ostream& operator<<(std::ostream& out, const NodoAVL<Key>& node) {
    out << node.data_;
    return out;
  }

 private:
  int bal_;
};

template <typename Key>
NodoAVL<Key>::NodoAVL() {
  this->left_ = NULL;
  this->right_ = NULL;
  bal_ = 0;
}

template <typename Key>
NodoAVL<Key>::NodoAVL(const Key& data, NodoAVL<Key>* left, NodoAVL<Key>* right) {
  this->data_ = data;
  this->left_ = left;
  this->right_ = right;
  bal_ = 0;
}

template <typename Key>
int NodoAVL<Key>::getBal() {
  return bal_;
}

template <typename Key>
NodoAVL<Key>* NodoAVL<Key>::getLeft() const {
  return reinterpret_cast<NodoAVL<Key>*>(this->NodoB<Key>::getLeft());
}

template <typename Key>
NodoAVL<Key>*& NodoAVL<Key>::getLeft() {
  return reinterpret_cast<NodoAVL<Key>*&>(this->NodoB<Key>::getLeft());
}

template <typename Key>
NodoAVL<Key>* NodoAVL<Key>::getRight() const {
  return reinterpret_cast<NodoAVL<Key>*>(this->NodoB<Key>::getRight());
}

template <typename Key>
NodoAVL<Key>*& NodoAVL<Key>::getRight() {
  return reinterpret_cast<NodoAVL<Key>*&>(this->NodoB<Key>::getRight());
}

template <typename Key>
void NodoAVL<Key>::setBal(const int& bal) {
  bal_ = bal;
}

template <typename Key>
void NodoAVL<Key>::setLeft(NodoAVL<Key>* &left) {
  this->NodoB<Key>::setLeft(left);
}

template <typename Key>
void NodoAVL<Key>::setRight(NodoAVL<Key>* &right) {
  this->NodoB<Key>::setRight(right);
}

#endif //NODOAVL_H_