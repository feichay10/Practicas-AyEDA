/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file fedoubledispersion.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FEDOUBLEDISPERSION_H
#define FEDOUBLEDISPERSION_H

#include "explorationfunction.h"
#include "dispersionfunction.h"

template <class Key>
class feDoubleDispersion : public ExplorationFunction<Key> {
 public:
  feDoubleDispersion() {}
  feDoubleDispersion(DispersionFunction<Key> *function) : fd_(function) {}
  unsigned operator()(const Key &k, unsigned i) const;

 private:
  DispersionFunction<Key> *fd_;
};

template <class Key>
unsigned feDoubleDispersion<Key>::operator()(const Key &k, unsigned i) const {
  return i * fd_->operator()(k);
}

#endif  // FEDOUBLEDISPERSION_H