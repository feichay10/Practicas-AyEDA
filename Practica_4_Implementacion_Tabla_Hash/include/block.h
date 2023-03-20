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

#include "sequence.h"
#include <vector>

template<class Key>
class Block : public Sequence<Key> {
  public:
    Block() = default;
    Block(int size);
    ~Block() = default;
    bool search(const Key& k) const;
    bool insert(const Key& k);
    bool ifFull() const;

  private:
    int blockSize_;
    int numElements_;
    std::vector<Key> block_;
};

#endif // BLOCK_H