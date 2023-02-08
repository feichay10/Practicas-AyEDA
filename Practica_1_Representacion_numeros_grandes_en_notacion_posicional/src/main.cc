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

/*
=========================== DUDAS =======================================
- ¿La entrada de los numeros de una base tiene que dar como resultado la misma base?
- DUDA GRANDE: Punto 4.
- Uso de templates 
========================================================================
*/

#include <iostream>

#include "../include/bigint.h"
#include "../include/checkparameters.h"
#include "../include/board.h"

/**
 * @brief Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
  CheckParameters(argc, argv);

  Board board(argv[1]);

  std::cout << "Base: " << board.getBase() << std::endl;
  std::map<std::string, std::string> labels = board.getLabels();
  for (const auto& label : labels) {
    std::cout << label.first << ": " << label.second << std::endl;
  }
  std::vector<std::string> expressions = board.getExpressions();
  for (const auto& expression : expressions) {
    std::cout << expression << std::endl;
  }

  return 0;
}