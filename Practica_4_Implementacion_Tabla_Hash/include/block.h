/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file block.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "sequence.h"

template <class Key>
class Block : public Sequence<Key> {
 public:
  Block();
  Block(int size);
  ~Block();
  bool search(const Key& k) const;
  bool insert(const Key& k);
  bool isFull() const;

 private:
  int blockSize_;
  int numElements_;
  std::vector<Key> block_;
};

template <class Key>
Block<Key>::Block(){
  blockSize_ = 0;
  numElements_ = 0;
}

template <class Key>
Block<Key>::Block(int size) {
  blockSize_ = size;
  numElements_ = 0;
  block_.resize(size);
}

template <class Key>
Block<Key>::~Block() {}

template <class Key>
bool Block<Key>::search(const Key& k) const {
  bool output = false;
  for (auto& i : block_) {
    if (i == k) {
      output = true;
      break;
    }
  }
  return output;
}

template <class Key>
bool Block<Key>::insert(const Key& k) {
  bool output = true;
  if (!isFull() && !search(k)) {
    block_[numElements_] = k;
    numElements_++;
  } else {
    output = false;
  }
  return output;
}

template <class Key>
bool Block<Key>::isFull() const {
  bool output = false;
  if (numElements_ == blockSize_) {
      output = true;
  }
  return output;
}

#endif  // BLOCK_H