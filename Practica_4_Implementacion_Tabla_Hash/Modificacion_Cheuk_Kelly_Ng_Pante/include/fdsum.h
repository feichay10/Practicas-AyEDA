/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file fdsum.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FDSUM_H
#define FDSUM_H

#include "dispersionfunction.h"

template <class Key>
class fdSum : public DispersionFunction<Key> {
 public:
  explicit fdSum(const unsigned n) : tableSize_(n) {}
  unsigned operator()(const Key& k) const;

 private:
  unsigned tableSize_;
};

template <class Key>
unsigned fdSum<Key>::operator()(const Key& k) const {
  long d = 0;
  long x = k;
  while (x > 0) {
    d += x % 10;
    x /= 10;
  }
  return (d % tableSize_);
}

#endif  // FDSUM_H