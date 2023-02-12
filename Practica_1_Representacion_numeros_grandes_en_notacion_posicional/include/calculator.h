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

template <class T>
class Calculator {
 public:
  Calculator();

  void InitializeOperations();
  void SetTokens(const std::map<std::string, std::string>& tokens);
  T Calculate(std::vector<std::string> expression);
  void ProcessExpression();

 private:
};

#endif  // CALCULATOR_H_