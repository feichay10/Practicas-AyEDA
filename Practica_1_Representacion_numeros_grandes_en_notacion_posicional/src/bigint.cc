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
template <size_t Base>
BigInt<Base>::BigInt(long n) {
  if (n == 0) {
    sign_ = 0;
    digits_.push_back(0);
  }
  if (n < 0) {
    sign_ = -1;
    n = -n;
  } else {
    sign_ = 1;
  }
  while (n > 0) {
    digits_.push_back(n % Base);
    n /= Base;
  }
}

template <size_t Base>
BigInt<Base>::BigInt(std::string& s) {
  if (s.empty()) {
    sign_ = 0;
    digits_.push_back(0);
  }

  std::string big_number = s;
  digits_.clear();
  if (big_number[0] == '-') {
    sign_ = -1;
    big_number.erase(0, 1);
  } else {
    sign_ = 1;
  }
  for (int i = big_number.size() - 1; i >= 0; i--) {
    if (isdigit(big_number[i])) {
      digits_.push_back(big_number[i] - '0');
    } else if (big_number[i] >= 'A' && big_number[i] <= 'F') {
      digits_.push_back(big_number[i] - 'A' + 10);
    }
  }
}

template <size_t Base>
BigInt<Base>::BigInt(const char* s) {
  std::string str(s);
  *this = BigInt(str);
}

template <size_t Base>
BigInt<Base>::BigInt(const BigInt<Base>& n) {
  sign_ = n.sign_;
  digits_ = n.digits_;
}

// Asignacion
template <size_t Base>
BigInt<Base> &BigInt<Base>::operator=(const BigInt<Base> &number_big) {
  sign_ = number_big.sign_;
  digits_ = number_big.digits_;
  return *this;
}

// Inserción y extracción en flujo
template <size_t Base>
std::ostream& operator<<(std::ostream& os, const BigInt<Base>& number_big) {
  if (number_big.sign_ == -1) {
    os << '-';
  }
  for (int i = number_big.digits_.size() - 1; i >= 0; i--) {
    if (number_big.digits_[i] >= 0 && number_big.digits_[i] <= 9) {
      os << number_big.digits_[i];
    } else if (number_big.digits_[i] >= 10 && number_big.digits_[i] <= 15) {
      os << static_cast<char>(number_big.digits_[i] + 'A' - 10);
    }
  }
  return os;
}

template <size_t Base>
std::istream& operator>>(std::istream& is, BigInt<Base>& number_big) {
  std::string str;
  is >> str;
  number_big = BigInt<Base>(str);
  return is;
}

// Accesor
template <size_t Base>
int BigInt<Base>::sign() const {
  return sign_;
}

template <size_t Base>
char BigInt<Base>::operator[](int i) const {
  return digits_[i];
}

// Comparación
