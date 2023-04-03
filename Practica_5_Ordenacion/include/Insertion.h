/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file Insertion.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef INSERTION_H
#define INSERTION_H

#include "SortMethod.h"

template<class Key>
class Insertion : public SortMethod<Key> {
  public:
    void Sort(std::vector<Key> &vector, int size);
};

template<class Key>
void Insertion<Key>::Sort(std::vector<Key> &vector, int size) {
  for (int i = 1; i < size; i++) {
    Key key = vector[i];
    int j = i - 1;
    while (j >= 0 && vector[j] > key) {
      vector[j + 1] = vector[j];
      j--;
    }
    vector[j + 1] = key;
  }
}

#endif // INSERTION_H