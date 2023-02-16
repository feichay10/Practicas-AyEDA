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
  // Inserción y extracción en flujo
  friend std::ostream& operator<<(std::ostream& os, const BigInt<Base>& number_big) {
    std::string number_str = number_big.toString();
    os << number_str;
    return os;
  }

  friend std::istream& operator>>(std::istream& is, BigInt<Base>& number_big) {
    std::string str;
    is >> str;
    number_big = BigInt<Base>(str);
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
    // 124321
    // 212321
    //-------
    // 336642

    // recorrer los numeros de derecha a izquierda y si el resultado es =< <base>, entonces:
    // si resultado >= base hacer MOD de la base 2(resultado) % <10>, lo guarda en esa posicion
    // si si el resultado se pasa de la base 
    // 9 + 3 = 12 pos ahora con 2, y a la siguiente pos le suma el carry, en este caso 1
    
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
  // BigInt<Base>& operator++() {
  //   BigInt<Base> one(1);
  //   *this = *this + one;
  //   return *this;
  // }
  
  // // Post-incremento
  // BigInt<Base> operator++(int) {
  //   BigInt<Base> temp = *this;
  //   ++*this;
  //   return temp;
  // }
  
  // Pre-decremento
  // BigInt<Base>& operator--() {
  //   BigInt<Base> one(1);
  //   *this = *this - one;
  //   return *this;
  // }

  // // Post-decremento
  // BigInt<Base> operator--(int) {
  //   BigInt<Base> temp = *this;
  //   --*this;
  //   return temp;
  // } 

  // // Operaciones aritméticas
  // friend BigInt<Base> operator+(const BigInt<Base>&, const BigInt<Base>&);
  BigInt<Base> operator-(const BigInt<Base>& n) const {
    BigInt<Base> number1 = *this;
    BigInt<Base> number2 = n;
    BigInt<Base> result;
    int carry = 0;

    result.digits_.clear();

    // -123 - (-456) = 333

    if (number1.sign_ == number2.sign_) {
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
    BigInt<Base> result = *this;
    result.sign_ = -result.sign_;
    return result;
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
  
  // friend BigInt<Base> operator/(const BigInt<Base>&, const BigInt<Base>&);
  // BigInt<Base> operator%(const BigInt<Base>&) const;

  // // Potencia a^b
  // friend BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);

  // Metodos auxiliares
  bool IsZero();
  std::string toString() const;
  BigInt<Base> fill_zeros(unsigned) const;
  BigInt<Base> Abs() const;
  void removeLeadingZeros();

  // Getters
  int GetSign() const { return sign_; }
  const std::vector<char>& Getdigits_() const { return digits_; }

  // Setters
  void SetSign(int sign) { sign_ = sign; }
  void Setdigits_(const std::vector<char>& digits_) { digits_ = digits_; }

 private:
  int sign_;                  // Signo: 1 o -1
  std::vector<char> digits_;  // Dígitos del número
};

// Constructores
/**
 * @brief Constructor de la clase BigInt a partir de un long
 *
 * @tparam Base
 * @param n
 */
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

  // std::cout << "digits_.size(): " << digits_.size() << std::endl;

  // std::cout << "Constructor BigInt(long n): " << std::endl;
  // for (int i = 0; i < digits_.size(); i++) {
  //   std::cout << (int)digits_[i] << std::endl;
  // }
}

/**
 * @brief Constructor de la clase BigInt a partir de un string
 *
 * @tparam Base
 * @param s
 */
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

/**
 * @brief Constructor de la clase BigInt a partir de un char *
 *
 * @tparam Base
 * @param s
 */
template <size_t Base>
BigInt<Base>::BigInt(const char* s) {
  std::string str(s);
  *this = BigInt(str);

  // std::cout << "Constructor BigInt(const char* s): " << std::endl;
  // for (int i = 0; i < digits_.size(); i++) {
  //   std::cout << (int)digits_[i] << std::endl;
  // }
}

/**
 * @brief Constructor de copia de la clase BigInt
 *
 * @tparam Base
 * @param n
 */
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
BigInt<Base> BigInt<Base>::fill_zeros(unsigned n) const {
  std::string number_str = this->toString();
  number_str.insert(number_str.begin(), n, '0');
  return BigInt<Base>(number_str);
}

template <size_t Base>
BigInt<Base> BigInt<Base>::Abs() const {
  BigInt<Base> number_aux = *this;
  number_aux.SetSign(1);
  return number_aux;
}

template <size_t Base>
void BigInt<Base>::removeLeadingZeros() {
  for (size_t i = digits_.size() - 1; i > 0 && digits_[i] == 0; i--) {
    std::cout << "Entra" << std::endl;
    digits_.pop_back();
  }

  if (digits_.size() == 1 && digits_[0] == 0) {
    sign_ = 0;
  }
}


#endif  // _BIGINT_H_