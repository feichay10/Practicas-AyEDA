/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Representación de números grandes en notación posicional
 * @file calculator.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/calculator.h"

/**
 * @brief Constructor por defecto
 * 
 * @tparam T 
 */
template <class T>
Calculator<T>::Calculator() {
  InitializeOperations();
}

/**
 * @brief Calcula el resultado de la expresión
 * 
 * @tparam T 
 * @param expression 
 */
template <class T>
void Calculator<T>::SetExpression(const std::map<std::string, std::string>& expression) {
  this->expression_ = expression;
}

/**
 * @brief Calcula el resultado de la expresión
 * 
 * @tparam T 
 */
template <class T>
void Calculator<T>::InitializeOperations() {
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
 * @brief Metodo que procesa la expresion usando la notacion polaca inversa
 * 
 * @tparam T 
 * @param expression 
 * @return T 
 */
template <class T>
T Calculator<T>::Calculate(std::vector<std::string> expression) {
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
      stack.push(std::stoi(token));
    }
  }
  return stack.top();
}