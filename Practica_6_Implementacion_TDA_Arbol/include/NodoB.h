/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @file NodoB.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NODOB_H_
#define NODOB_H_

template <class Key>
class NodoB {
 public:
  NodoB(Key data_, NodoB<Key>* left_ = nullptr, NodoB<Key>* right_ = nullptr);
  NodoB();
  ~NodoB() = default;
  
  NodoB<Key>* getLeft() const;
  NodoB<Key>*& getLeft();
  NodoB<Key>* getRight() const;
  NodoB<Key>*& getRight();
  void setLeft(NodoB<Key>* left);
  void setRight(NodoB<Key>* right);
  void setData(Key data);
  Key getData() const;

 private:
  Key data_;
  NodoB<Key>* left_;
  NodoB<Key>* right_;
};

template <class Key>
NodoB<Key>::NodoB(Key data, NodoB<Key>* left, NodoB<Key>* right) {
  data_ = data;
  left_ = left;
  right_ = right;
}

template <class Key>
NodoB<Key>::NodoB() {
  data_ = 0;
  left_ = nullptr;
  right_ = nullptr;
}

template <class Key>
NodoB<Key>* NodoB<Key>::getLeft() const {
  return left_;
}

template <class Key>
NodoB<Key>*& NodoB<Key>::getLeft() {
  return left_;
}

template <class Key>
NodoB<Key>* NodoB<Key>::getRight() const {
  return right_;
}

template <class Key>
NodoB<Key>*& NodoB<Key>::getRight() {
  return right_;
}

template <class Key>
void NodoB<Key>::setLeft(NodoB<Key>* left) {
  NodoB::left_ = left;
}

template <class Key>
void NodoB<Key>::setRight(NodoB<Key>* right) {
  NodoB::right_ = right;
}

template <class Key>
void NodoB<Key>::setData(Key data) {
  NodoB::data_ = data;
}

template <class Key>
Key NodoB<Key>::getData() const {
  return data_;
}

#endif  // NODOB_H_