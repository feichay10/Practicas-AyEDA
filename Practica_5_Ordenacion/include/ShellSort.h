/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file ShellSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "SortMethod.h"

template <typename T>
class ShellSort : public SortMethod<T> {
 public:
  void Sort(std::vector<T> &vector, int size);

 private:
  void DeltaSort(std::vector<T> &vector, int size, int delta);
};

template <typename T>
void ShellSort<T>::Sort(std::vector<T> &vector, int size) {
  unsigned int delta = size;
  while (delta > 1) {
    delta = delta / 2;
    DeltaSort(vector, size, delta);
  }
}

template <typename T>
void ShellSort<T>::DeltaSort(std::vector<T> &vector, int size, int delta) {
  T temp;
  for (int i = delta; i < size; i++) {
    temp = vector[i];
    int j = i;
    while (j >= delta && vector[j - delta] > temp) {
      vector[j] = vector[j - delta];
      j = j - delta;
    }
    vector[j] = temp;
#ifdef TRAZA
    print(vector, size);
#endif
  }
}

#endif  // SHELLSORT_H