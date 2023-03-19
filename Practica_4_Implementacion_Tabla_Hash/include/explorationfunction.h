/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file explorationfunction.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef EXPLORATIONFUNCTION_H
#define EXPLORATIONFUNCTION_H

template <class Key>
class ExplorationFunction {
 public:
  unsigned operator()(const Key& k, unsigned i) const = 0;
};

#endif  // EXPLORATIONFUNCTION_H