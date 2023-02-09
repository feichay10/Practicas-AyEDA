/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Representación de números grandes en notación posicional
 * @file bigint.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/bigint.h"

// Constructores
template<size_t Base>
BigInt<Base>::BigInt(long n) {
  if (n < 0) {
    sign_ = -1;
  }
  while (n != 0) {
    digits_.push_back(n % Base);
    n /= Base;
  }
}

template<size_t Base>
BigInt<Base>::BigInt(std::string& s) {
  if (s[0] == '-') {
    sign_ = -1;
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != '-') {
      digits_.push_back(s[i] - '0');
    }
  }
}

template<size_t Base>
BigInt<Base>::BigInt(const char* s) {
  if (s[0] == '-') {
    sign_ = -1;
  }
  for (int i = strlen(s) - 1; i >= 0; i--) {
    if (s[i] != '-') {
      digits_.push_back(s[i] - '0');
    }
  }
}

template<size_t Base>
BigInt<Base>::BigInt(const BigInt<Base>& n) {
  sign_ = n.sign_;
  digits_ = n.digits_;
}

// Asignacion
template<size_t Base>
BigInt<Base>& BigInt<Base>::operator=(const BigInt<Base>& n) {
  sign_ = n.sign_;
  digits_ = n.digits_;
  return *this;
}

// Inserción y extracción en flujo
template<size_t Base>
std::ostream& operator<<(std::ostream& os, const BigInt<Base>& n) {
  if (n.sign_ == -1) {
    os << '-';
  }
  for (int i = n.digits_.size() - 1; i >= 0; i--) {
    os << n.digits_[i];
  }
  return os;
}

template<size_t Base>
std::istream& operator>>(std::istream& is, BigInt<Base>& n) {
  std::string s;
  is >> s;
  n = BigInt<Base>(s);
  return is;
}