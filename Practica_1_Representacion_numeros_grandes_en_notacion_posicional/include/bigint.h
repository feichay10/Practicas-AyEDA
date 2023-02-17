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
#include <algorithm>

template <size_t Base>
class BigInt {
  // Inserción y extracción en flujo
  /**
   * @brief Operador de insercion en flujo
   * 
   * @param os 
   * @param number_big 
   * @return std::ostream& 
   */
  friend std::ostream& operator<<(std::ostream& os, const BigInt<Base>& number_big) {
    std::string number_str = number_big.toString();
    os << number_str;
    return os;
  }

  /**
   * @brief Operador de extraccion de flujo
   * 
   * @param is 
   * @param number_big 
   * @return std::istream& 
   */
  friend std::istream& operator>>(std::istream& is, BigInt<Base>& number_big) {
    std::string str;
    is >> str;
    number_big = BigInt<Base>(str);
    return is;
  }

  // Operador de comparacion
  /**
   * @brief Operador de comparacion ==
   * 
   * @param a 
   * @param b 
   * @return true 
   * @return false 
   */
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

  /**
   * @brief Operador de comparacion >
   * 
   * @param a 
   * @param b 
   * @return true 
   * @return false 
   */
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

  /**
   * @brief Operador de comparacion <
   * 
   * @param a 
   * @param b 
   * @return true 
   * @return false 
   */
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
  /**
   * @brief Operador de suma +
   * 
   * @param a 
   * @param b 
   * @return BigInt<Base> 
   */
  friend BigInt<Base> operator+(const BigInt<Base> &a, const BigInt<Base> &b) {
    // recorrer los numeros de derecha a izquierda y si el resultado es =< <base>, entonces:
    // si resultado >= base hacer MOD de la base 2(resultado) % <10>, lo guarda en esa posicion
    // si si el resultado se pasa de la base 
    // 9 + 3 = 12 pos ahora con 2, y a la siguiente pos le suma el carry, en este caso 1
    BigInt<Base> number1 = a;
    BigInt<Base> number2 = b;
    BigInt<Base> result;
    int carry = 0;
    std::vector<char> digits_sum;

    result.digits_.clear();

    // Si los dos numeros son del mismo signo
    if (number1.sign_ == number2.sign_) {
      result.sign_ = number1.sign_;
    } else {                      // Si los dos numeros son de signos diferentes
      if (number1.sign_ == -1) {  // Si el primer numero es negativo
        number1.sign_ = 1;
        result = number2 - number1;
        number1.sign_ = -1;
      } else {                    // Si el segundo numero es negativo
        number2.sign_ = 1;
        result = number1 - number2;
        number2.sign_ = -1;
      }
      return result;
    }

    // Si el primer numero es mayor que el segundo
    if (number1 > number2) {
      // Añadir ceros al principio del numero mas pequeño
      for (int i = 0; i < number1.digits_.size() - number2.digits_.size(); i++) {
        number2.digits_.insert(number2.digits_.end(), 0);
      }
    } else {                      // Si el segundo numero es mayor que el primero
      // Añadir ceros al principio del numero mas pequeño
      for (int i = 0; i < number2.digits_.size() - number1.digits_.size(); i++) {
        number1.digits_.insert(number2.digits_.end(), 0);
      }
    }

    std::cout << "number1: " << number1 << std::endl;
    std::cout << "number2: " << number2 << std::endl;

    // Hacer la suma de los digitos
    for (int i = number1.digits_.size() - 1; i >= 0; i--) {
      int sum = number1.digits_[i] + number2.digits_[i] + carry;
      carry = sum / Base;
      sum = sum % Base;

      digits_sum.push_back(sum);
    }

    if (carry == 1) {
      digits_sum.push_back(carry);
    }

    // Invertir el vector
    std::reverse(digits_sum.begin(), digits_sum.end());

    // Guardar los digitos en el resultado
    result.digits_ = digits_sum;

    return result;
  }

  /**
   * @brief Operador de division /
   * 
   * @param number1 
   * @param number2 
   * @return BigInt<Base> 
   */
  friend BigInt<Base> operator/(const BigInt<Base> &number1, const BigInt<Base> &number2) {
    BigInt<Base> number1_aux = number1.Abs();
    BigInt<Base> number2_aux = number2.Abs();

    // if number2_aux is 0 we can't divide
    if (number2_aux.IsZero()) {
      throw std::invalid_argument("Can't divide by 0");
      return BigInt<Base>("0");
    }

    int i = -1;
    while (number1_aux >= number2_aux) {
      number1_aux = number1_aux - number2_aux;
      i++;
    }
  
    if (number1.GetSign() != number2.GetSign()) {
      return -i;
    }

    return i;
  }
  
 public:
  // Constructores
  BigInt(long n = 0);
  BigInt(std::string&);
  BigInt(const char*);
  BigInt(const BigInt<Base>&);  // Constructor de copia

  // Asignación
  /**
   * @brief Operador de asignacion =
   * 
   * @param n 
   * @return BigInt<Base>& 
   */
  BigInt<Base>& operator=(const BigInt<Base>& n) {
    sign_ = n.sign_;
    digits_ = n.digits_;
    return *this;
  }

  // Accesor
  int sign() const;            // Signo: 1 o -1
  char operator[](int) const;  // Acceso al i-ésimo dígito

  // Comparación
  /**
   * @brief Operador de comparacion !=
   * 
   * @param n 
   * @return true 
   * @return false 
   */
  bool operator!=(const BigInt<Base>& n) const {
    return !(*this == n);
  }

  /**
   * @brief Operador de comparacion >=
   * 
   * @param n 
   * @return true 
   * @return false 
   */
  bool operator>=(const BigInt<Base>& n) const {
    return !(*this < n);
  }

  /**
   * @brief Operador de comparacion <=
   * 
   * @param n 
   * @return true 
   * @return false 
   */
  bool operator<=(const BigInt<Base>& n) const {
    return !(*this > n);
  }

  // Incremento y decremento
  // Pre-incremento 
  /**
   * @brief Operador de incremento ++
   * 
   * @return BigInt<Base>& 
   */
  BigInt<Base>& operator++() {
    BigInt<Base> one("1");
    *this = *this + one;
    return *this;
  }
  
  // Post-incremento
  /**
   * @brief Operador de incremento ++
   * 
   * @param int 
   * @return BigInt<Base> 
   */
  BigInt<Base> operator++(int) {
    BigInt<Base> temp = *this;
    ++*this;
    return temp;
  }
  
  // Pre-decremento
  /**
   * @brief Operador de decremento --
   * 
   * @return BigInt<Base>& 
   */
  BigInt<Base>& operator--() {
    BigInt<Base> one("1");
    *this = *this - one;
    return *this;
  }

  // Post-decremento
  /**
   * @brief Operador de decremento --
   * 
   * @return BigInt<Base> 
   */
  BigInt<Base> operator--(int) {
    BigInt<Base> temp = *this;
    --*this;
    return temp;
  } 

  // Operaciones aritméticas
  /**
   * @brief Operador de resta -
   * 
   * @param n 
   * @return BigInt<Base> 
   */
  BigInt<Base> operator-(const BigInt<Base>& n) const {
    BigInt<Base> number1 = *this;
    BigInt<Base> number2 = n;
    BigInt<Base> result;
    int carry = 0;

    result.digits_.clear();

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

  /**
   * @brief Operador de cambio de signo -
   * 
   * @return BigInt<Base> 
   */
  BigInt<Base> operator-() const {
    BigInt<Base> number_aux = *this;
    number_aux.SetSign(-number_aux.GetSign());
    return number_aux;
  }

  /**
   * @brief Operador de multiplicacion *
   * 
   * @param n 
   * @return BigInt<Base> 
   */
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

  /**
   * @brief Operador de modulo %
   * 
   * @param n 
   * @return BigInt<Base> 
   */
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

  // // Potencia a^b
  // friend BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);

  // Metodos auxiliares
  bool IsZero();
  std::string toString() const;
  BigInt<Base> Abs() const;
  BigInt<Base> fill_zeros(unsigned) const ;

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

  // std::cout << "Constructor BigInt(std::string& s): " << std::endl;
  // for (int i = 0; i < digits_.size(); i++) {
  //   std::cout << (int)digits_[i] << std::endl;
  // }
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
/**
 * @brief Devuelve el signo del BigInt
 * 
 * @tparam Base 
 * @return int 
 */
template <size_t Base>
int BigInt<Base>::sign() const {
  return sign_;
}

/**
 * @brief Devuelve el dígito en la posición i del BigInt
 * 
 * @tparam Base 
 * @param i 
 * @return char 
 */
template <size_t Base>
char BigInt<Base>::operator[](int i) const {
  return digits_[i];
}

// Metodos auxiliares
/**
 * @brief Comprueba si el BigInt es cero
 * 
 * @tparam Base 
 * @return true 
 * @return false 
 */
template <size_t Base>
bool BigInt<Base>::IsZero() {
  for (int i = 0; i < digits_.size(); i++) {
    if (digits_[i] != 0) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Devuelve el string correspondiente al BigInt
 * 
 * @tparam Base 
 * @return std::string 
 */
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

/**
 * @brief Devuelve el valor absoluto del BigInt
 * 
 * @tparam Base 
 * @return BigInt<Base> 
 */
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

#endif  // _BIGINT_H_