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

#include "block.h"
#include "dispersionfunction.h"
#include "explorationfunction.h"
#include "list.h"
#include "sequence.h"

template <class Key>
class HashTable {
 public:
  HashTable(int size, DispersionFunction<Key> *dispersionFunction,
            ExplorationFunction<Key> *explorationFunction = nullptr,
            int blockSize = 0);
  ~HashTable() = default;
  bool search(const Key &k) const;
  bool insert(const Key &k);

 private:
  int tableSize_;
  int blockSize_;
  Sequence<Key> *table_;
  DispersionFunction<Key> *fd_;
  ExplorationFunction<Key> *fe_;
};

template <class Key>
HashTable<Key>::HashTable(int tableSz,
                          DispersionFunction<Key> *dispersionFunction,
                          ExplorationFunction<Key> *explorationFunction,
                          int blockSz) {
  tableSize_ = tableSz;
  blockSize_ = blockSz;
  fd_ = dispersionFunction;
  fe_ = explorationFunction;
  if(fe_ == nullptr) {
    table_ = new List<Key> [tableSize_];
  } else {
      table_ = new Block<Key> [tableSize_];
      for(int i = 0; i < tableSize_; i++){
        table_[i] = Block<Key>(blockSize_);
      }
  }
}

template <class Key>
bool HashTable<Key>::insert(const Key &key) {
  unsigned index = (*fd_)(key);
  if(table_[index].insert(key)) {
    return true;
  } else {
    int attempt = 0;
    while (attempt < blockSize_ && !table_[index].insert(key)) {
        index = (*fe_)(key, index);
        attempt++;
    }
    if(attempt == blockSize_) {
      return false;
    } else {
      return true;
    }
  }
}

template <class Key>
bool HashTable<Key>::search(const Key &key) const {
  bool output = false;
  unsigned index = (*fd_)(key);
  if(table_[index].search(key)) output = true;
  else {
      int attempt = 0;
      while (attempt < blockSize_ && !table_[index].search(key)) {
          index = (*fe_)(key, index);
          if(table_[index].search(key)) output = true;
          attempt++;
      }
  }
  return output;
}

#endif  // HASHTABLE_H