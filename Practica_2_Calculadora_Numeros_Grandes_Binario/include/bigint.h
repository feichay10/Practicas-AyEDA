/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: Calculadora de números grandes en binario
 * @file bigint.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-03-03
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
#include <algorithm>

template <size_t Base>
class BigInt {
  // Inserción y extracción en flujo
  friend std::ostream& operator<<(std::ostream& os, const BigInt<Base>& number) {
    std::string number_str = number.toString();
    os << number_str;
    return os;
  }

  friend std::istream& operator>>(std::istream& is, BigInt<Base>& number) {
    std::string str;
    is >> str;
    number = BigInt<Base>(str);
    return is;
  }

  // Operador de comparacion
  friend bool operator==(const BigInt<Base>& a, const BigInt<Base>& b) {
    BigInt<Base> number1 = a;
    BigInt<Base> number2 = b;

    if (number1.IsZero() && number2.IsZero()) {
      return true;
    }

    if (number1.sign() != number2.sign()) {
      return false;
    }

    if (number1.digits_.size() != number2.digits_.size()) {
      return false;
    }

    for (int i = 0; i < number1.digits_.size(); i++) {
      if (number1.digits_[i] != number2.digits_[i]) {
        return false;
      }
    }

    return true;
  }

  friend bool operator>(const BigInt<Base>& a, const BigInt<Base>& b) {
    BigInt<Base> number1 = a;
    BigInt<Base> number2 = b;

    if (number1.sign_ > number2.sign_) {
      return true;
    } else if (number1.sign_ < number2.sign_) {
      return false;
    }
    
    for (int i = number1.digits_.size() - 1; i >= 0; i--) {
      if (number1.digits_[i] > number2.digits_[i]) {
        return true;
      } else if (number1.digits_[i] < number2.digits_[i]) {
        return false;
      }
    }

    return false;
  }

  friend bool operator<(const BigInt<Base>& a, const BigInt<Base>& b) {
    BigInt<Base> number1 = a;
    BigInt<Base> number2 = b;

    if (number1.sign_ < number2.sign_) {
      return true;
    } else if (number1.sign_ > number2.sign_) {
      return false;
    }
    
    for (int i = number1.digits_.size() - 1; i >= 0; i--) {
      if (number1.digits_[i] < number2.digits_[i]) {
        return true;
      } else if (number1.digits_[i] > number2.digits_[i]) {
        return false;
      }
    }

    return false;
  }

  // Operaciones aritméticas
  friend BigInt<Base> operator+(const BigInt<Base> &a, const BigInt<Base> &b) {
    // Recorrer los numeros de derecha a izquierda por cada posicion, si la suma de cada posicion, el resultado es
    // menor o igual que la base, se guarda en la posicion actual en un vector de resultado, si el resultado es mayor
    // que la base, se guarda el modulo de la base en la posicion actual, y se suma el carry a la siguiente posicion
    // En caso de que alguno de los numeros es mas grande que el otro, se rellena con 0s hasta que tengan el mismo tamaño
    
    // 12 + 12 = 24
    // 12++ = 13
    // 12 + 2 = 14

    BigInt<Base> number1 = a;
    BigInt<Base> number2 = b;
    BigInt<Base> result;
    int carry = 0;

    result.digits_.clear();

    if (number1.sign_ == number2.sign_) {
      result.sign_ = number1.sign_;
    } else {
      if (number1.sign_ == -1) {
        number1.sign_ = 1;
        result = number2 - number1;
        number1.sign_ = -1;
      } else {
        number2.sign_ = 1;
        result = number1 - number2;
        number2.sign_ = -1;
      }
      return result;
    }

    for (int i = 0; i < number1.digits_.size() || i < number2.digits_.size(); i++) {
      int sum = carry;
      if (i < number1.digits_.size()) {
        sum += number1.digits_[i];
      }

      if (i < number2.digits_.size()) {
        sum += number2.digits_[i];
      }

      result.digits_.push_back(sum % Base);
      carry = sum / Base;
    }

    if (carry != 0) {
      result.digits_.push_back(carry);
    }

    return result;
  }

  friend BigInt<Base> operator/(const BigInt<Base> &number1, const BigInt<Base> &number2) {
    BigInt<Base> number1_aux = number1.Abs();
    BigInt<Base> number2_aux = number2.Abs();

    // if number2_aux is 0 we can't divide
    if (number2_aux.IsZero()) {
      throw std::invalid_argument("Can't divide by 0");
      return BigInt<Base>("0");
    }

    int i = 0;
    while (number1_aux >= number2_aux) {
      number1_aux = number1_aux - number2_aux;
      i++;
    }
  
    if ((number1.GetSign() != number2.GetSign()) && (i != 0)) {
      // std::cout << "Entra" << std::endl;
      return -i;
    }

    // std::cout << "i: " << i << std::endl;
    return i;
  }

  friend BigInt<Base> pow(const BigInt<Base>& a, const BigInt<Base>& b) {
    BigInt<Base> number1 = a.Abs();
    BigInt<Base> number2 = b.Abs();
    BigInt<Base> result("1");
    BigInt<Base> i("0");
    BigInt<Base> zero("0");
    BigInt<Base> two("2");

    if (number2 == i) {
      return result;
    }

    if (number2.GetSign() == -1) {
      throw std::invalid_argument("Can't pow by negative number");
    }

    for (i = zero; i < number2; ++i) {
      result = result * number1;
    }

    if (a.GetSign() == -1) {
      if (number1 % two == zero) {
        return result;
      }
      return -result;
    }
    return result;
  }
  
 public:
  // Constructores
  BigInt(long n = 0);
  BigInt(std::string&);
  BigInt(const char*);
  BigInt(const BigInt<Base>&);  // Constructor de copia

  // Asignación
  BigInt<Base>& operator=(const BigInt<Base>& n) {
    sign_ = n.sign_;
    digits_ = n.digits_;
    return *this;
  }

  // Accesor
  int sign() const;            // Signo: 1 o -1
  char operator[](int) const;  // Acceso al i-ésimo dígito

  // Comparación
  bool operator!=(const BigInt<Base>& n) const {
    return !(*this == n);
  }

  bool operator>=(const BigInt<Base>& n) const {
    return !(*this < n);
  }

  bool operator<=(const BigInt<Base>& n) const {
    return !(*this > n);
  }

  // Incremento y decremento
  // Pre-incremento 
  BigInt<Base>& operator++() {
    BigInt<Base> one("1");
    *this = *this + one;
    return *this;
  }
  
  // Post-incremento
  BigInt<Base> operator++(int) {
    BigInt<Base> temp = *this;
    ++*this;
    return temp;
  }
  
  // Pre-decremento
  BigInt<Base>& operator--() {
    BigInt<Base> one("1");
    *this = *this - one;
    return *this;
  }

  // Post-decremento
  BigInt<Base> operator--(int) {
    BigInt<Base> temp = *this;
    --*this;
    return temp;
  } 

  // Operaciones aritméticas
  BigInt<Base> operator-(const BigInt<Base>& n) const { 
    BigInt<Base> number1 = *this;
    BigInt<Base> number2 = n;
    BigInt<Base> result;
    int carry = 0;

    result.digits_.clear();

    if (number1.sign_ == number2.sign_) { // 4 - 2 = 2
      if (number1.sign_ == -1) {
        number1.sign_ = 1;
        number2.sign_ = -1;
        result = number2 + number1;
        result.sign_ = (number1 > number2) ? 1 : -1;
        return result;
      } else {
        if (number1 < number2) {
          result = number2 - number1;
          result.sign_ = -1;
          return result;
        }
      }
    } else {
      if (number1.sign_ == -1) {
        number1.sign_ = 1;
        result = number1 + number2;
        result.sign_ = -1;
        return result;
      } else {
        number2.sign_ = 1;
        result = number1 + number2;
        return result;
      }
    }

    for (int i = 0; i < number1.digits_.size(); i++) {
      int sub = number1.digits_[i] - carry;
      if (i < number2.digits_.size()) {
        sub -= number2.digits_[i];
      }

      if (sub < 0) {
        sub += Base;
        carry = 1;
      } else {
        carry = 0;
      }

      result.digits_.push_back(sub);
    }

    return result;
  }

  BigInt<Base> operator-() const {
    BigInt<Base> number_aux = *this;
    number_aux.SetSign(-number_aux.GetSign());
    return number_aux;
  }

  BigInt<Base> operator*(const BigInt<Base>& n) const {
    BigInt<Base> number1 = *this;
    BigInt<Base> number2 = n;
    BigInt<Base> result;
    int carry = 0;

    result.digits_.clear();

    if (number1.sign_ == number2.sign_) {
      result.sign_ = 1;
    } else {
      result.sign_ = -1;
    }

    for (int i = 0; i < number1.digits_.size(); i++) {
      for (int j = 0; j < number2.digits_.size(); j++) {
        int mul = number1.digits_[i] * number2.digits_[j] + carry;
        if (i + j < result.digits_.size()) {
          mul += result.digits_[i + j];
        }

        if (i + j >= result.digits_.size()) {
          result.digits_.push_back(mul % Base);
        } else {
          result.digits_[i + j] = mul % Base;
        }

        carry = mul / Base;
      }

      if (carry != 0) {
        result.digits_.push_back(carry);
        carry = 0;
      }
    }

    return result;
  }

  BigInt<Base> operator%(const BigInt<Base>& n) const {
    BigInt<Base> number1_aux = this->Abs();
    BigInt<Base> number2_aux = n.Abs();
    BigInt<Base> result("0");

    // Si el numerto number2_aux es 0, lanzamos una excepción
    if (number2_aux == result) {
      throw std::invalid_argument("Can't divide by 0");
    }

    for (; number2_aux <= number1_aux; ++result) {
      // std::cout << "number1_aux: " << number1_aux.toString() << std::endl;
      number1_aux = number1_aux - number2_aux;
    }

    if (this->GetSign() == -1) {
      return -number1_aux;
    }

    return number1_aux;
  }

  BigInt<Base> operator^(const BigInt<Base>& n) const {
    return pow(*this, n);
  }

  // Modificacion: Sobre cargar el operador de cambio de tipo
  operator BigInt<2>() const {
    std::string binary;
    BigInt<Base> n(*this), zero("0"), two("2"), next_digit, mod;

    while (n != zero) {
      next_digit = n / two; 
      mod = n % two;        
      binary.insert(binary.begin(), mod.GetDigits()[0] + '0');
      n = next_digit;
    }

    return BigInt<2>(binary);
  }

  // Metodos auxiliares
  bool IsZero();
  std::string toString() const;
  BigInt<Base> Abs() const;
  BigInt<Base> fill_zeros(unsigned) const;

  // Getters y Setters
  BigInt<Base> SetSign(int);
  BigInt<Base> SetDigits(std::vector<char>);
  std::vector<char> GetDigits() const;
  int GetSign() const;

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
}

template <size_t Base>
BigInt<Base>::BigInt(std::string& s) {
  if (s.empty()) {
    sign_ = 0;
    digits_.push_back(0);
    return;
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

// Accesor
template <size_t Base>
int BigInt<Base>::sign() const {
  return sign_;
}

template <size_t Base>
char BigInt<Base>::operator[](int i) const {
  return digits_[i];
}

// Metodos auxiliares
template <size_t Base>
bool BigInt<Base>::IsZero() {
  for (int i = 0; i < digits_.size(); i++) {
    if (digits_[i] != 0) {
      return false;
    }
  }
  return true;
}

template <size_t Base>
std::string BigInt<Base>::toString() const {
  std::string str;
  if (sign_ == -1) {
    str += "-";
  }

  for (int i = digits_.size() - 1; i >= 0; i--) {
    if (digits_[i] < 10) {
      str += digits_[i] + '0';
    } else {
      str += digits_[i] - 10 + 'A';
    }
  }

  return str;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::Abs() const {
  BigInt<Base> abs = *this;
  abs.sign_ = 1;
  return abs;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::fill_zeros(unsigned number_zero) const {
  std::string number_str = this->toString();
  number_str.insert(number_str.begin(), number_zero, '0');
  return BigInt<Base>(number_str);
}

// Getters y Setters
template <size_t Base>
BigInt<Base> BigInt<Base>::SetSign(int sign) {
  sign_ = sign;
  return *this;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::SetDigits(std::vector<char> digits) {
  digits_ = digits;
  return *this;
}

template <size_t Base>
std::vector<char> BigInt<Base>::GetDigits() const {
  return digits_;
}

template <size_t Base>
int BigInt<Base>::GetSign() const {
  return sign_;
}

// Clase BigInt<2>
template <>
class BigInt<2> {
  public:
    operator BigInt<8>() { // Codigo de conversion de binario a BigInt<8> 

    }

    operator BigInt<10>() { // Codigo de conversion de binario a BigInt<10> 

    }

    operator BigInt<16>() { // Codigo de conversion de binario a BigInt<16> 

    }

  private:
    std::vector<bool> digits_;
};


#endif  // _BIGINT_H_