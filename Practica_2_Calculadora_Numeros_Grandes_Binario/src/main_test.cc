/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Representación de números grandes en notación posicional
 * @file main_test.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 * 
 * g++ src/main_test.cc -o main_test
 *
 */

#include <iostream>

#include "../include/bigint.h"

/**
 * @brief Funcion principal del programa
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char* argv[]) {
  BigInt<10> test(5);
  (BigInt<2>)test;
  std::cout << "test: " << test << std::endl;

  return 0;
}