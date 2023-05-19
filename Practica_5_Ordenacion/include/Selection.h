/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file Selection.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SELECTION_H
#define SELECTION_H

#include "SortMethod.h"

template <typename T>
class Selection : public SortMethod<T> {
 public:
  void Sort(std::vector<T> &vector, int size);
};

template <typename T>
void Selection<T>::Sort(std::vector<T> &vector, int size) {
  T temp;
  for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (vector[j] < vector[min]) {
        min = j;
      }
    }
    temp = vector[min];
    vector[min] = vector[i];
    vector[i] = temp;
#ifdef TRAZA
    print(vector, size);
#endif
  }
}

#endif // SELECTION_H