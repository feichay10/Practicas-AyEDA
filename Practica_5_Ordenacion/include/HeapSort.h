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

template <typename T>
class HeapSort : public SortMethod<T> {
 public:
  void Sort(std::vector<T> &vector, int size);

 private:
  void PushDown(int i, std::vector<T>& vec, int n);
  void Swap(T& i, T& j);
};

template<typename T>
void HeapSort<T>::Sort(std::vector<T>& vector, int size) {
  std::cout << "Fase 1, inserciones\n";
  for (int i{int(size) / 2 - 1}; i >= 0; --i) {
    this->PushDown(i, vector, size);
    for (auto j: vector) std::cout << j << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
  
  std::cout << "Fase 2, extracciones\n";
  for (int i{int(size) - 1}; i > 0; --i) {
    this->Swap(vector[0], vector[i]);
    this->PushDown(0, vector, i);
    for (auto j: vector) std::cout << j << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

template<typename T>
void HeapSort<T>::PushDown(int i, std::vector<T>& vec, int n) {
  int largest{i};
  int left{2 * i + 1};
  int right{2 * i + 2};

  /// Si el hijo izquierdo es mas grande que el padre
  if ((left < n) && (vec[left] > vec[largest])) largest = left;
  
  /// Si el hijo derecho es mas grande que el mas grande hasta ahora
  if ((right < n) && (vec[right] > vec[largest])) largest = right;
  
  /// Si el mas grande no es el padre
  if (largest != i) {
    this->Swap(vec[i], vec[largest]);
  
    /// Llamamos recursivamente al sub-arbol afectado
    this->PushDown(largest, vec, n);
  }
}

template<typename T>
void HeapSort<T>::Swap(T& i, T& j) {
  T aux{i};
  i = j;
  j = aux;
}

#endif  // HEAPSORT_H