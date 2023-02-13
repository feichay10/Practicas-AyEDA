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
  Functions functions;
  Functions check;
  // Calculator<BigInt<2>> calculator2;
  // Calculator<BigInt<8>> calculator8;
  // Calculator<BigInt<10>> calculator10;
  // Calculator<BigInt<16>> calculator16;

  long number = 124312121;
  std::string aux_string = "ADF124312121";
  char aux_char = 'A';
  BigInt<10> number1(number);
  BigInt<16> number2(aux_string);
  BigInt<16> number3(aux_char);

  check.CheckParameters(argc, argv);
  functions.ReadFile(argv[1]);
  functions.WriteOnScreen();

  switch (functions.getBase()) {
    case 2:
      std::cout << "Base 2" << std::endl;
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