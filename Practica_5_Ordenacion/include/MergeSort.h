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

template <class Key>
class MergeSort : public SortMethod<Key> {
 public:
  void Msort(std::vector<Key> &vector, int ini, int fin);
  void Sort(std::vector<Key> &vector, int size);
  void Mix(std::vector<Key> &vector, int ini, int cen, int fin);
};

template <class Key>
void MergeSort<Key>::Msort(std::vector<Key> &vector, int ini, int fin) {
  if (ini < fin) {
    int cen = (ini + fin) / 2;
    Msort(vector, ini, cen);
    Msort(vector, cen + 1, fin);
    Mix(vector, ini, cen, fin);
  }
}

template <class Key>
void MergeSort<Key>::Sort(std::vector<Key> &vector, int size) {
  Msort(vector, 0, size - 1);
}

template <class Key>
void MergeSort<Key>::Mix(std::vector<Key> &vector, int ini, int cen, int fin) {
  int i = ini;
  int j = cen + 1;

  std::vector<Key> aux(fin + 1);

  int k = ini;
  while ((i <= cen) && (j <= fin)) {
    if ((vector[i]) < (vector[j])) {
      aux[k] = vector[i];
      i++;
    } else {
      aux[k] = vector[j];
      j++;
    }
    k++;
  }

  if (i > cen)
    while (j <= fin) {
      aux[k] = vector[j];
      j++;
      k++;
    }
  else
    while (i <= cen) {
      aux[k] = vector[i];
      i++;
      k++;
    }
  for (int z = ini; z <= fin; z++) {
    vector[z] = aux[z];
  }
}

#endif  // MERGESORT_H