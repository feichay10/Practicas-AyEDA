/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file HeapSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "SortMethod.h"

template<typename T>
class HeapSort : public SortMethod<T> {
  public:
    void Sort(std::vector<T> &vector, int size);
};

template<typename T>
void HeapSort<T>::Sort(std::vector<T> &vector, int size) {
  T temp;
  for (int i = size / 2 - 1; i >= 0; i--) {
    for (int j = i; j < size; j++) {
      if (vector[j] > vector[i]) {
        temp = vector[i];
        vector[i] = vector[j];
        vector[j] = temp;
      }
    }
    print(vector, size);
  }
  for (int i = size - 1; i >= 0; i--) {
    temp = vector[0];
    vector[0] = vector[i];
    vector[i] = temp;
    for (int j = 0; j < i; j++) {
      if (vector[j] > vector[j + 1]) {
        temp = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = temp;
      }
    }
    print(vector, size);
  }
}

#endif // HEAPSORT_H