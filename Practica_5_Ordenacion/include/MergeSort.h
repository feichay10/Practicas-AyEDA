/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file MergeSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortMethod.h"

template<class Key>
class MergeSort : public SortMethod<Key> {
  public:
    void Sort(std::vector<Key> &vector, int size);
};

#enfif // MERGESORT_H