/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file QuickSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortMethod.h"

template<typename T>
class QuickSort: public SortMethod<T> {
 public:
  void Sort(std::vector<T>& vec, int n);
  
 private:
  void QSort(std::vector<T>& vec, int begin, int end);
  int Partition(std::vector<T>& vec, const int& begin, const int& end);
  void Swap(T& i, T& j);
};

template<typename T>
void QuickSort<T>::Sort(std::vector<T>& vec, int n) {
  this->QSort(vec, 0, int(n - 1));
}

template<typename T>
void QuickSort<T>::QSort(std::vector<T>& vec, int begin, int end) {
  if (begin >= end) return; ///< Caso base
  int pivot{this->Partition(vec, begin, end)}; ///< Particionamos el vector
  this->QSort(vec, begin, pivot - 1); ///< Ordenamos la parte izquierda
  this->QSort(vec, pivot + 1, end); ///< Ordenamos la parte derecha
}

template<typename T>
int QuickSort<T>::Partition(std::vector<T>& vec, const int& begin, const int& end) {
  long pivot{vec[begin]};
  int count{0};
  
  for (int i{begin + 1}; i <= end; ++i) if (vec[i] <= pivot) ++count;

  /// Le damos al pivote su posicion correcta
  int pivot_index{begin + count}; 
  this->Swap(vec[pivot_index], vec[begin]);

  for (auto i: vec) std::cout << i << " ";
  std::cout << std::endl;

  /// Ordenamos las partes izquierda y derecha del elemento pivote
  int i{begin};
  int j{end};
  while ((i < pivot_index) && (j > pivot_index)) {
    while (vec[i] <= pivot) ++i;
    while (vec[j] > pivot) --j;
    if ((i < pivot_index) && (j > pivot_index)) this->Swap(vec[i++], vec[j--]);
    for (auto k: vec) std::cout << k << " ";
    std::cout << std::endl;
  }

  return pivot_index;
}

template<typename T>
void QuickSort<T>::Swap(T& i, T& j) {
  T aux{i};
  i = j;
  j = aux;
}

#endif // QUICKSORT_H