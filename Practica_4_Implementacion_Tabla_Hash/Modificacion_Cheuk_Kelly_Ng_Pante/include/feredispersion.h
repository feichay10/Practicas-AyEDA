/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file feredispersion.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FEREDISPERSION_H
#define FEREDISPERSION_H

#include "explorationfunction.h"

template <class Key>
class feRedispersion : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const;
};

template<class Key>
unsigned feRedispersion<Key>::operator()(const Key& k, unsigned i) const {
  srand(k);
  int aux;
  for(unsigned j = 0; j <= i; j++) {
    aux = rand();
  }
  return aux;
}

#endif  // FEREDISPERSION_H