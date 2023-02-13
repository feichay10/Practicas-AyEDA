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

#pragma once

#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

template <size_t Base>
class BigInt {
 public:
  // Constructores
  BigInt(long n = 0);
  BigInt(std::string&);
  BigInt(const char*);
  BigInt(const BigInt<Base>&);  // Constructor de copia

  // Asignación
  BigInt<Base> &operator=(const BigInt<Base> &);

  // Inserción y extracción en flujo
  friend std::ostream& operator<<(std::ostream&, const BigInt<Base>&);
  friend std::istream& operator>>(std::istream&, BigInt<Base>&);

  // Accesor
  int sign() const;            // Signo: 1 o -1
  char operator[](int) const;  // Acceso al i-ésimo dígito

  // Comparación
  friend bool operator==(const BigInt<Base>&, const BigInt<Base>&);
  bool operator!=(const BigInt<Base>&) const;
  friend bool operator>(const BigInt<Base>&, const BigInt<Base>&);
  bool operator>=(const BigInt<Base>&) const;
  friend bool operator<(const BigInt<Base>&, const BigInt<Base>&);
  bool operator<=(const BigInt<Base>&) const;

  // // Incremento y decremento
  // BigInt<Base>& operator++();    // Pre-incremento
  // BigInt<Base> operator++(int);  // Post-incremento
  // BigInt<Base>& operator--();    // Pre-decremento
  // BigInt<Base> operator--(int);  // Post-decremento

  // // Operaciones aritméticas
  // friend BigInt<Base> operator+(const BigInt<Base>&, const BigInt<Base>&);
  // BigInt<Base> operator-(const BigInt<Base>&) const;
  // BigInt<Base> operator-() const;
  // BigInt<Base> operator*(const BigInt<Base>&) const;
  // friend BigInt<Base> operator/(const BigInt<Base>&, const BigInt<Base>&);
  // BigInt<Base> operator%(const BigInt<Base>&) const;

  // // Potencia a^b
  // friend BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);

  // Metodos
  // void Procesar();
  // void Calculadora();

 private:
  int sign_;                  // Signo: 1 o -1
  std::vector<char> digits_;  // Dígitos del número
};

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

  std::cout << "Constructor BigInt(long n): " << std::endl;
  for (int i = 0; i < digits_.size(); i++) {
    std::cout << (int)digits_[i] << std::endl;
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

  std::cout << "Constructor BigInt(std::string& s): " << std::endl;
  for (int i = 0; i < digits_.size(); i++) {
    std::cout << (int)digits_[i] << std::endl;
  }
}

template <size_t Base>
BigInt<Base>::BigInt(const char* s) {
  std::string str(s);
  *this = BigInt(str);

  std::cout << "Constructor BigInt(const char* s): " << std::endl;
  for (int i = 0; i < digits_.size(); i++) {
    std::cout << (int)digits_[i] << std::endl;
  }
}

template <size_t Base>
BigInt<Base>::BigInt(const BigInt<Base>& n) {
  sign_ = n.sign_;
  digits_ = n.digits_;
}

// // Asignacion
// template <size_t Base>
// BigInt<Base> &BigInt<Base>::operator=(const BigInt<Base> &number_big) {
//   sign_ = number_big.sign_;
//   digits_ = number_big.digits_;
//   return *this;
// }

// // Inserción y extracción en flujo
// template <size_t Base>
// std::ostream &operator<<(std::ostream &os, const BigInt<Base> &number_big) {
//   std::string number_str = number_big.to_string();
//   os << number_str;
//   return os;
// }

// template <size_t Base>
// std::istream& operator>>(std::istream& is, BigInt<Base>& number_big) {
//   std::string str;
//   is >> str;
//   number_big = BigInt<Base>(str);
//   return is;
// }

// // Accesor
// template <size_t Base>
// int BigInt<Base>::sign() const {
//   return sign_;
// }

// template <size_t Base>
// char BigInt<Base>::operator[](int i) const {
//   return digits_[i];
// }

#endif // _BIGINT_H_