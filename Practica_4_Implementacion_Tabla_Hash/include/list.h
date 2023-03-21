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

#include <list>

#include "sequence.h"

template<class Key>
class List : public Sequence<Key> {
  public:
    List() = default;
    ~List() = default;
    bool search(const Key& k) const;
    bool insert(const Key& k);
    bool ifFull() const;

  private:
    std::list<Key> list_;
};

template<class Key>
bool List<Key>::search(const Key& k) const {
  for (auto it = list_.begin(); it != list_.end(); it++) {
    if (*it == k) {
      return true;
    }
  }
  return false;
}

template<class Key>
bool List<Key>::insert(const Key& k) {
  if (search(k)) {
    return false;
  }
  list_.push_back(k);
  return true;
}

template<class Key>
bool List<Key>::ifFull() const {
  return false;
}

#endif // LIST_H