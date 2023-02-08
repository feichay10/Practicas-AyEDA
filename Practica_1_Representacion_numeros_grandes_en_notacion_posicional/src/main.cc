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
  check.CheckParameters(argc, argv);

  if (argc == 2) {
    functions = Functions(argv[1]);
  } else {
    functions = Functions();
  }

  std::cout << "Base: " << functions.getBase() << std::endl;
  std::cout << "Labels: " << std::endl;
  for (auto& label : functions.getLabels()) {
    std::cout << label.first << " = " << label.second << std::endl;
  }
  std::cout << "Expressions: " << std::endl;
  for (auto& expression : functions.getExpressions()) {
    std::cout << expression << std::endl;
  }

  return 0;
}