/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Representación de números grandes en notación posicional
 * @file calculator.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Clase que representa una calculadora de expresiones
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <functional>

template <class T>
class Calculator {
 public:
  /**
   * @brief Constructor por defecto
   * 
   */
  Calculator() {
    InitializeOperations();
  }

  /**
   * @brief Conjunto de expresiones a calcular
   * 
   * @param expression 
   */
  void SetExpression(const std::vector<std::vector<std::string>>& expression) {
    this->expressions_ = expression;
  }

  /**
   * @brief Calcula el resultado de una expresión
   * 
   */
  void InitializeOperations() {
    // Operaciones
    operations_["+"] = [](T a, T b) { return a + b; };
    operations_["-"] = [](T a, T b) { return a - b; };
    operations_["*"] = [](T a, T b) { return a * b; };
    operations_["/"] = [](T a, T b) { return a / b; };
    operations_["%"] = [](T a, T b) { return a % b; };
    operations_["^"] = [](T a, T b) { return a ^ b; };
    operations_["=="] = [](T a, T b) { return a == b; };
    operations_["!="] = [](T a, T b) { return a != b; };
    operations_["<"] = [](T a, T b) { return a < b; };
    operations_["<="] = [](T a, T b) { return a <= b; };
    operations_[">"] = [](T a, T b) { return a > b; };
    operations_[">="] = [](T a, T b) { return a >= b; };
    operations_["="] = [](T a, T b) { return a = b; };

    // Operaciones unarias
    unary_operations_["++"] = [](T a) { return ++a; };
    unary_operations_["--"] = [](T a) { return --a; };
    unary_operations_["-"] = [](T a) { return -a; };
  }
  
  /**
   * @brief Calcula el resultado de una expresión con notación polaca inversa
   * 
   * @param expression 
   * @return T 
   */
  T Calculate(std::vector<std::string> expression) {
    std::stack<T> stack;
    for (auto& token : expression) {
      if (operations_.find(token) != operations_.end()) {
        T a = stack.top();
        stack.pop();
        T b = stack.top();
        stack.pop();
        stack.push(operations_[token](b, a));
      } else if (unary_operations_.find(token) != unary_operations_.end()) {
        T a = stack.top();
        stack.pop();
        stack.push(unary_operations_[token](a));
      } else {
        stack.push(variables_[token]);
      }
    }
    return stack.top();
  }

  /**
   * @brief Calcula el resultado de una expresión
   * 
   */
  void ProcessExpression() {
    for (auto& line : expressions_) {
      if (line.size() == 3 && line[1] == "=") {
        if (variables_.count(line[2]) == 1) {
          variables_[line[0]] = variables_[line[2]];
        } else {
          variables_[line[0]] = T(line[2]);
        }
      } else if (line.size() > 3) {
        if (line[1] != "=") {
          std::cout << "Error in line: ";
          for (auto& token : line) {
            std::cout << token << " ";
          }
          continue;
        }
        std::vector<std::string> expressions_line(line.begin() + 2, line.end());
        variables_[line[0]] = Calculate(expressions_line);
      } else {
        std::cout << "Error in line: ";
        for (auto& token : line) {
          std::cout << token << " ";
        }
      }
    }
  }

  template <class U>
  friend std::ostream& operator<<(std::ostream& os, const Calculator<U>& c);

 private:
  std::vector<std::vector<std::string>> expressions_;
  std::map<std::string, T> variables_;
  std::map<std::string, std::function<T(T, T)>> operations_;
  std::map<std::string, std::function<T(T)>> unary_operations_;
};

/**
 * @brief Impresión de las variables y sus valores
 * 
 * @tparam U 
 * @param os 
 * @param c 
 * @return std::ostream& 
 */
template <class U>
std::ostream& operator<<(std::ostream& os, const Calculator<U>& c) {
  for (auto& variable : c.variables_) {
    os << variable.first << " = " << variable.second << std::endl;
  }
  return os;
}

#endif  // CALCULATOR_H_