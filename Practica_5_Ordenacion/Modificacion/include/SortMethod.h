/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file SortMethod.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SORTMETHOD_H
#define SORTMETHOD_H

#include <vector>

const int kMaximunNumber = 9999;
const int kMinimunNumber = 1000;

template <typename T>
class SortMethod {
 public:
  virtual void Sort(std::vector<T> &vector, int size) = 0;
  void print(std::vector<T> &vector, int size);

 private:
  unsigned size_;
};

template <typename T>
void print(std::vector<T> &vector, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << vector[i] << " ";
  }
  std::cout << std::endl;
}

#endif  // SORTMETHOD_H