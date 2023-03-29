/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Implementación de Tabla de Hash
 * @file key.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/key.h"

Key::Key() {
  key_.key1_ = 0;
  key_.key2_ = 0;
  entireKey_ = 0;
}

Key::Key(long key1, long key2) {
  key_.key1_ = key1;
  key_.key2_ = key2;
  entireKey_ = key1 + key2;
}

long Key::getEntireKey() {
  return entireKey_;
}

void Key::setKey(const long key1, const long key2) {
  key_.key1_ = key1;
  key_.key2_ = key2;
  entireKey_ = key1 + key2;
}

bool Key::operator==(const Key& key) const {
  return entireKey_ == key.entireKey_;
}

bool Key::operator!=(const Key& key) const {
  return entireKey_ != key.entireKey_;
}

bool Key::operator<(const Key& key) const {
  return entireKey_ < key.entireKey_;
}

bool Key::operator>(const Key& key) const {
  return entireKey_ > key.entireKey_;
}

bool Key::operator<=(const Key& key) const {
  return entireKey_ <= key.entireKey_;
}

bool Key::operator>=(const Key& key) const {
  return entireKey_ >= key.entireKey_;
}

Key Key::operator+(const Key& key) const {
  return Key(key_.key1_ + key.key_.key1_, key_.key2_ + key.key_.key2_);
}

Key Key::operator-(const Key& key) const {
  return Key(key_.key1_ - key.key_.key1_, key_.key2_ - key.key_.key2_);
}

Key Key::operator*(const Key& key) const {
  return Key(key_.key1_ * key.key_.key1_, key_.key2_ * key.key_.key2_);
}

Key Key::operator/(const Key& key) const {
  return Key(key_.key1_ / key.key_.key1_, key_.key2_ / key.key_.key2_);
}

Key Key::operator%(const Key& key) const {
  return Key(key_.key1_ % key.key_.key1_, key_.key2_ % key.key_.key2_);
}

std::ostream& operator<<(std::ostream& os, const Key& key) {
  os << key.entireKey_;
  return os;
}

std::istream& operator>>(std::istream& is, Key& key) {
  is >> key.key_.key1_ >> key.key_.key2_;
  key.entireKey_ = key.key_.key1_ + key.key_.key2_;
  return is;
}