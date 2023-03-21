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

Key::Key(long key1, long key2) {
  key_.key1_ = key1;
  key_.key2_ = key2;
  entireKey_ = key1 + key2;
}

Key::Key() {
  Key(0, 0);
}

long Key::getEntireKey() {
  return entireKey_;
}

long Key::getEntireKey() const {
  return entireKey_;
}

void Key::setKey(const long key1, const long key2) {
  key_.key1_ = key1;
  key_.key2_ = key2;
  entireKey_ = key1 + key2;
}

// Sobrecarga de operadores de comparación
bool Key::operator==(const Key& key) {
  return this->entireKey_ == key.entireKey_;
}

bool Key::operator!=(const Key& key) {
  return this->entireKey_ != key.entireKey_;
}

bool Key::operator<(const Key& key) {
  return this->entireKey_ < key.entireKey_;
}

bool Key::operator>(const Key& key) {
  return this->entireKey_ > key.entireKey_;
}

bool Key::operator<=(const Key& key) {
  return this->entireKey_ <= key.entireKey_;
}

bool Key::operator>=(const Key& key) {
  return this->entireKey_ >= key.entireKey_;
}

// Sobrecarga de operadores aritméticos
Key Key::operator+(const Key& key) {
  return Key(this->key_.key1_ + key.key_.key1_, this->key_.key2_ + key.key_.key2_);
}

Key Key::operator-(const Key& key) {
  return Key(this->key_.key1_ - key.key_.key1_, this->key_.key2_ - key.key_.key2_);
}

Key Key::operator*(const Key& key) {
  return Key(this->key_.key1_ * key.key_.key1_, this->key_.key2_ * key.key_.key2_);
}

Key Key::operator/(const Key& key) {
  return Key(this->key_.key1_ / key.key_.key1_, this->key_.key2_ / key.key_.key2_);
}

Key Key::operator%(const Key& key) {
  return Key(this->key_.key1_ % key.key_.key1_, this->key_.key2_ % key.key_.key2_);
}

// Sobrecarga de operadores >> y <<
std::ostream& operator<<(std::ostream& os, const Key& key) {
  os << key.entireKey_;
  return os;
}

std::istream& operator>>(std::istream& is, Key& key) {
  long key1, key2;
  is >> key1 >> key2;
  key.setKey(key1, key2);
  return is;
}

#endif  // KEY_H