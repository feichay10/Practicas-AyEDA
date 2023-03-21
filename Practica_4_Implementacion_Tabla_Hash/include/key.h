/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file key.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef KEY_H
#define KEY_H

#include <iostream>

class Key {
 public:
  Key() = default;
  Key(long key1, long key2);
  long getEntireKey();
  long getEntireKey() const;
  void setKey(const long key1, const long key2);

  // Sobrecarga de operadores de comparación
  bool operator==(const Key& key);
  bool operator!=(const Key& key);
  bool operator<(const Key& key);
  bool operator>(const Key& key);
  bool operator<=(const Key& key);
  bool operator>=(const Key& key);

  // Sobrecarga de operadores aritméticos
  Key operator+(const Key& key);
  Key operator-(const Key& key);
  Key operator*(const Key& key);
  Key operator/(const Key& key);
  Key operator%(const Key& key);

  // Sobrecarga de operadores >> y <<
  friend std::ostream& operator<<(std::ostream& os, const Key& key);
  friend std::istream& operator>>(std::istream& is, Key& key);
 private:
  struct {
    long key1_;
    long key2_;
  } key_;
  long entireKey_;
};

#endif  // KEY_H