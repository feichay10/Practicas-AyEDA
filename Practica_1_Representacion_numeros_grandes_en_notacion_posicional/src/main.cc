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

  check.CheckParameters(argc, argv);
  functions.ReadFile(argv[1]);
  functions.WriteFile(argv[2]);

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

  std::string aux = "12021342432";
  switch (base) {
    case 2:
      std::cout << "Base 2" << std::endl;
      // Convertir el numero que esta en label a un BigInt:
      // BigInt<2> bigint(aux);
      // for (auto& label : label) {
      //   BigInt<2> bigint(label.second);
      //   // std::cout << bigint << std::endl;
      // }
      break;
    case 8:
      // for (auto& expression : functions.getExpressions()) {
      //   BigInt<8> bigint(expression);
      //   std::cout << bigint << std::endl;
      // }
      std::cout << "Base 8" << std::endl;
      break;
    case 10:
      // for (auto& expression : functions.getExpressions()) {
      //   BigInt<10> bigint(expression);
      //   std::cout << bigint << std::endl;
      // }
      std::cout << "Base 10" << std::endl;
      break;
    case 16:
      // for (auto& expression : functions.getExpressions()) {
      //   BigInt<16> bigint(expression);
      //   std::cout << bigint << std::endl;
      // }
      std::cout << "Base 16" << std::endl;
      break;
    default:
      std::cout << "Base no soportada" << std::endl;
      break;
  }

  return 0;
}