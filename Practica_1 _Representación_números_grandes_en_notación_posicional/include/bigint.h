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

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

template <typename Base>

class BigInt {
 public:
  // Constructores
  BigInt(long n = 0);
  BigInt(std::string&);
  BigInt(const char*);
  BigInt(const BigInt<Base>&);  // Constructor de copia

  // Asignación
  BigInt<Base>& operator=(const BigInt<Base>&);

  // Inserción y extracción en flujo
  friend ostream& operator<<(ostream&, const BigInt<Base>&);
  friend istream& operator>>(istream&, BigInt<Base>&);

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

  // Incremento y decremento
  BigInt<Base>& operator++();    // Pre-incremento
  BigInt<Base> operator++(int);  // Post-incremento
  BigInt<Base>& operator--();    // Pre-decremento
  BigInt<Base> operator--(int);  // Post-decremento

  // Operaciones aritméticas
  friend BigInt<Base> operator+(const BigInt<Base>&, const BigInt<Base>&);
  BigInt<Base> operator-(const BigInt<Base>&) const;
  BigInt<Base> operator-() const;
  BigInt<Base> operator*(const BigInt<Base>&) const;
  friend BigInt<Base> operator/(const BigInt<Base>&, const BigInt<Base>&);
  BigInt<Base> operator%(const BigInt<Base>&) const;
  // Potencia a^b
  friend BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);

 private:
};