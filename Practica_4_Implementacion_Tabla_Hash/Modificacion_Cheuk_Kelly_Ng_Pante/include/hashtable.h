/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file hashtable.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

#include "block.h"
#include "dispersionfunction.h"
#include "explorationfunction.h"
#include "fdmodule.h"
#include "fdrandom.h"
#include "fdsum.h"
#include "fedoubledispersion.h"
#include "felineal.h"
#include "fequadratic.h"
#include "feredispersion.h"
#include "list.h"
#include "sequence.h"

template <class Key>
class HashTable {
 public:
  HashTable(int table_size, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe = nullptr, int block_size = 0);
  bool search(const Key& key) const;
  bool insert(const Key& key);
  void print();

  int getCount() {
    return count_;
  }

 private:
  int tableSize_;
  Sequence<Key>** table_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
  int blockSize_ = 0;
  int count_ = 0;
};

template <class Key>
HashTable<Key>::HashTable(int table_size, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe, int block_size) {
  tableSize_ = table_size;
  fe_ = fe;
  fd_ = fd;
  table_ = new Sequence<Key>*[tableSize_];
  if (fe_ == nullptr) {
    for (int i = 0; i < tableSize_; ++i) {
      table_[i] = new List<Key>;
    }
  } else {
    for (int i = 0; i < tableSize_; ++i) {
      table_[i] = new Block<Key>(block_size);
    }
  }
}

template <class Key>
bool HashTable<Key>::search(const Key& k) const {
  bool output = false;
  unsigned index = (*fd_)(k);
  if (table_[index]->search(k)) {
    output = true;
  } else {
    int attempt = 0;
    while (attempt < blockSize_ && !table_[index]->search(k)) {
      index = (*fe_)(k, index);
      if (table_[index]->search(k)) output = true;
      attempt++;
    }
  }
  return output;
}

template <class Key>
bool HashTable<Key>::insert(const Key& k) {
  bool output = false;
  unsigned index = (*fd_)(k);
  if (table_[index]->insert(k)) {
    count_++;
    output = true;
  } else {
    int attempt = 0;
    while (attempt < blockSize_ && !table_[index]->insert(k)) {
      index = (*fe_)(k, index);
      if (table_[index]->insert(k)) output = true;
      attempt++;
    }
  }
  return output;
}

template <class Key>
void HashTable<Key>::print() {
  for (int i = 0; i < tableSize_; ++i) {
    std::cout << i << ") [ ";
    table_[i]->print();
    std::cout << "]" << std::endl;
  }
}

#endif  // HASHTABLE_H