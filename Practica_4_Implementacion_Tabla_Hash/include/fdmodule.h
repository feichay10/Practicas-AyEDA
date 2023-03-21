/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file fdmodule.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FDMODULE_H
#define FDMODULE_H

#include "dispersionfunction.h"
template <class Key>
class fdModule : public DispersionFunction<Key> {
 public:
  explicit fdModule(const unsigned n) : tableSize_(n) {}
  unsigned operator()(const Key& k) const;

 private:
  unsigned tableSize_;
};

template <class Key>
unsigned fdModule<Key>::operator()(const Key& k) const {
  return k % tableSize_;
}

#endif  // FDMODULE_H