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
};

template <typename T>
void ShellSort<T>::Sort(std::vector<T> &vector, int size) {
  int j;
  T temp;
  float alpha;
  std::cout << "Introduzca un alfa entre 0 y 1: ";
  std::cin >> alpha;
  for (int h = (size * alpha) / 2; h > 0; h /= 2) {
    for (int i = h; i < size; i++) {
      temp = vector[i];
      for (j = i; j >= h && vector[j - h] > temp; j -= h) {
        vector[j] = vector[j - h];
      }
      vector[j] = temp;
    }
#ifdef TRAZA
    print(vector, size);
#endif
  }
}

#endif  // SHELLSORT_H