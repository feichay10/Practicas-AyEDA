/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file RadixSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "SortMethod.h"

template<class Key>
class RadixSort : public SortMethod<Key> {
  public:
    void Sort(std::vector<Key> &vector, int size);
};

template<class Key>
void RadixSort<Key>::Sort(std::vector<Key> &vector, int size) {
  for(int i = 1; kMinimunNumber / i > 0; i *= 10){
    std::vector<Key> aux(size);
    int count[10] = {0};
    for(int j = 0; j < size; j++){
      int digit = (vector[j] / i) % 10;
      count[digit]++;
    }
    for(int j = 1; j < 10; j++){
      count[j] += count[j - 1];
    }
    for(int j = size - 1; j >= 0; j--){
      int digit = (vector[j] / i) % 10;
      aux[count[digit] - 1] = vector[j];
      count[digit]--;
    }
    for (int k = 0; k < size; k++){
      vector[k] = aux[k];
    }
    print(vector, size);
  }
}

#endif // RADIXSORT_H