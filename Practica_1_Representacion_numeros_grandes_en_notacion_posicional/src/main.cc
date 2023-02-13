/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Representación de números grandes en notación posicional
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "../include/bigint.h"
#include "../include/calculator.h"
#include "../include/functions.h"

/**
 * @brief Funcion principal del programa
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char* argv[]) {
  Functions check;
  Functions functions;
  char base;
  std::map<std::string, std::string> label;
  std::vector<std::string> expression;
  Calculator<BigInt<2>> calculator2;
  Calculator<BigInt<8>> calculator8;
  Calculator<BigInt<10>> calculator10;
  Calculator<BigInt<16>> calculator16;

  check.CheckParameters(argc, argv);
  functions.ReadFile(argv[1]);
  // functions.WriteFile(argv[2]);

  base = functions.getBase();
  std::cout << "Base: " << base << std::endl;
  std::cout << "Labels: " << std::endl;
  label = functions.getLabels();
  for (auto& label : label) {
    std::cout << label.first << " = " << label.second << std::endl;
  }
  std::cout << "Expressions: " << std::endl;
  expression = functions.getExpressions();
  for (auto& expression : expression) {
    std::cout << expression << std::endl;
  }

  switch (base) {
    case 2:
      std::cout << "Base 2" << std::endl;
      // calculator2.Calculate(expression);
      // std::cout << "Result: " << calculator2.Calculate(expression) << std::endl;
      break;
    case 8:
      std::cout << "Base 8" << std::endl;
      break;
    case 10:
      std::cout << "Base 10" << std::endl;
      break;
    case 16:
      std::cout << "Base 16" << std::endl;
      break;
    default:
      std::cout << "Base no soportada" << std::endl;
      break;
  }

  return 0;
}