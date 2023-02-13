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

template <class T>
Calculator<T>::Calculator() {
  InitializeOperations();
}

template <class T>
void Calculator<T>::SetExpression(const std::map<std::string, std::string>& expression) {
  this->expression_ = expression;
}

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