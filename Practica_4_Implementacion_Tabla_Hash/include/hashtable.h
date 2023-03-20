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

#endif  // HASHTABLE_H