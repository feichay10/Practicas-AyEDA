/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file sequence.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>

template <class Key>
class Sequence {
  public:
    virtual bool search(const Key& k) const = 0;
    virtual bool insert(const Key& k) = 0;
    virtual bool isFull() const = 0;
    virtual void print() = 0;
};

#endif // SEQUENCE_H