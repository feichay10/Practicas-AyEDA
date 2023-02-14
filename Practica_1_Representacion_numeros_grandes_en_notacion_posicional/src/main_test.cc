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
  // long number = 124312121;
  // std::string aux_string = "ADF124312121";
  // char aux_char = 'A';
  // BigInt<10> number1(number);
  // BigInt<16> number2(aux_string);
  // BigInt<16> number3(aux_char);

  BigInt<10> num123(123);
  BigInt<10> num456(456);
  BigInt<10> num789(789);
  BigInt<10> num123456789(123456789);
  BigInt<10> num123456789123456789(123456789123456789);

  // Prueba de salida por pantalla
  std::cout << "num123: " << num123 << std::endl;

  // Prueba del operador =
  BigInt<10> num123_2 = num123;
  std::cout << "num123_2: " << num123_2 << std::endl;

  // Prueba de los operadores de comparacion
  std::cout << "num123 == num123_2: " << (num123 == num123_2) << std::endl;
  // std::cout << "num123 != num123_2: " << (num123 != num123_2) << std::endl;
  // std::cout << "num123 != num456: " << (num123 != num456) << std::endl;
    
  return 0;
}