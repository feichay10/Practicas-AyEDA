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
 * @date 2023-05-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NODOB_H_
#define NODOB_H_

template <class Key>
class NodoB {
  NodoB(Key data_, NodoB* left_ = nullptr, NodoB* right_ = nullptr)
      : data_(data_), left_(left_), right_(right_) {}
  NodoB() : left_(nullptr), right_(nullptr) {}
  ~NodoB() = default;
  Key getData() const;

 public:
  NodoB<Key>* getLeft() const;
  NodoB<Key>* getRight() const;

 private:
  Key data_;
  NodoB<Key>* left_;
  NodoB<Key>* right_;
};

template <class Key>
NodoB<Key>* NodoB<Key>::getLeft() const {
  return left_;
}

template <class Key>
NodoB<Key>* NodoB<Key>::getRight() const {
  return right_;
}

template <class Key>
Key NodoB<Key>::getData() const {
  return data_;
}

#endif  // NODOB_H_