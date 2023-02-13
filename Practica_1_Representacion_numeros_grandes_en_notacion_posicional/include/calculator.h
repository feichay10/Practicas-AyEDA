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
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional>
#include <stack>

template <class T>
class Calculator {
 public:
  Calculator();

  void InitializeOperations();
  void SetExpression(const std::map<std::string, std::string>&);
  T Calculate(std::vector<std::string>);
  void ProcessExpression();

 private:
  std::map<std::string, std::string> expression_;
  std::map<std::string, T> variables_;
  std::map<std::string, std::function<T(T, T)>> operations_;
  std::map<std::string, std::function<T(T)>> unary_operations_;
};

#endif  // CALCULATOR_H_