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
  bool search(const Key& k) const;
  bool insert(const Key& k);
  bool isFull() const;
  void print();

 private:
  Key* synonyms_;
  int blockSize_;
};

template<class Key>
Block<Key>::Block() {

}

template<class Key>
Block<Key>::Block(int size) {
  synonyms_ = new Key[size];
  blockSize_ = size;
}

template<class Key>
bool Block<Key>::search(const Key& k) const {
  for (int i = 0; i < blockSize_; i++) {
    if (synonyms_[i] == k) {
      return true;
    }
  }
  return false;
}

template<class Key>
bool Block<Key>::insert(const Key& k) {
  if (!search(k)) {
    for (int i = 0; i < blockSize_; ++i) {
      if (synonyms_[i] == NULL) {
        synonyms_[i] = k;
        return true;
      }
    }
  }
  return false;
}

template<class Key>
bool Block<Key>::isFull() const {
  for (int i = 0; i < blockSize_; ++i) {
    if (synonyms_[i] == NULL) {
      return false;
    }
  }
  return true;
}

template <class Key>
void Block<Key>::print() {
  for (int i = 0; i < blockSize_; ++i) {
    if (synonyms_[i] == NULL) {
      continue;
    }
    std::cout << "[" << synonyms_[i] << "] "; 
  }
}

#endif  // BLOCK_H