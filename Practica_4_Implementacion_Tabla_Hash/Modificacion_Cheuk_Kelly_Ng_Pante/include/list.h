/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file list.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LIST_H
#define LIST_H

#include <vector>
#include <iostream>

#include "sequence.h"

template<class Key>
class List : public Sequence<Key> {
  public:
    List();
    List(const List& l) = default;
    bool search(const Key& k) const;
    bool insert(const Key& k);
    bool isFull() const;
    void print();

    int getCount() {
      return count_;
    }

  private:
    Key* synonyms_;
    int tam_ = 0;
    int count_ = 0;
};

template<class Key>
List<Key>::List() {
  synonyms_ = new Key[tam_];
}

template<class Key>
bool List<Key>::search(const Key& k) const {
  for (int i = 0; i < tam_; ++i) {
    if (synonyms_[i] == k) {
      return true;
    }
  }
  return false;
}

template<class Key>
bool List<Key>::insert(const Key& k) {
  if (!search(k)) {
    tam_++;
    for (int i = 0; i < tam_; ++i) {
      if (synonyms_[i] == NULL) {
        synonyms_[i] = k;
        return true;
      }
    }
    return true;
  }
  return false;
}

template<class Key>
bool List<Key>::isFull() const {
  return false;
}

template<class Key>
void List<Key>::print() {
  for (int i = 0; i < tam_; ++i) {
    std::cout << "[" << synonyms_[i] << "] "; 
  }
}

#endif // LIST_H