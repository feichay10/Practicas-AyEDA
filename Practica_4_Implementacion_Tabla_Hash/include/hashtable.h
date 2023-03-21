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
  HashTable(int size, DispersionFunction<Key> *dispersionFunction, ExplorationFunction<Key> *explorationFunction = nullptr, int blockSize = 0);
  ~HashTable() = default;
  bool search(const Key& k) const;
  bool insert(const Key& k);
 private:
  int tableSize;
  int blockSize;
  Sequence<Key> *table;
  DispersionFunction<Key> *fd;
  ExplorationFunction<Key> *fe;
};

template<class Key>
HashTable<Key>::HashTable(int tableSz, DispersionFunction<Key> *dispersionFunction, ExplorationFunction<Key> *explorationFunction, int blockSz) {
  tableSize = tableSz;
  blockSize = blockSz;
  fd = dispersionFunction;
  fe = explorationFunction;
  if (fe == nullptr) {
    table = new List<Key>(tableSize);
  } else {
    table = new Block<Key>(tableSize, blockSize);
    for (int i = 0; i < tableSize; i++) {
      table[i] = Block<Key>(blockSize);
    }
  }
}

template<class Key>
bool HashTable<Key>::insert(const Key& key) {
  unsigned index = (*fd)(key);
  if (fe == nullptr) {
    return table[index].insert(key);
  } else {
    unsigned i = 0;
    while (i < tableSize) {
      if (table[index].insert(key)) {
        return true;
      }
      index = (*fe)(index, i);
      i++;
    }
    return false;
  }
}

template<class Key>
bool HashTable<Key>::search(const Key& key) const {
  unsigned index = (*fd)(key);
  if (fe == nullptr) {
    return table[index].search(key);
  } else {
    unsigned i = 0;
    while (i < tableSize) {
      if (table[index].search(key)) {
        return true;
      }
      index = (*fe)(index, i);
      i++;
    }
    return false;
  }
}

#endif  // HASHTABLE_H