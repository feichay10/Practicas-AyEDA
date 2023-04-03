/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file fdrandom.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FDRANDOM_H
#define FDRANDOM_H

#include "dispersionfunction.h"

template <class Key>
class fdRandom : public DispersionFunction<Key> {
 public:
  explicit fdRandom(const unsigned n) : tableSize_(n) {}
  unsigned operator()(const Key& k) const;

 private:
  unsigned tableSize_;
};

template <class Key>
unsigned fdRandom<Key>::operator()(const Key& k) const {
  srand(k);
  return rand() % tableSize_;
}

#endif  // FDRANDOM_H