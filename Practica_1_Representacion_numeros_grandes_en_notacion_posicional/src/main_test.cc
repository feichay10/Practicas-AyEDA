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
  // ================================================================================================
  // Pruebas para numeros en base 2
  // Numeros en base 2
  std::cout << "==============================================================================" << std::endl;
  std::cout << "====== Pruebas para numeros en base 2 ======\n" << std::endl;
  BigInt<2> num110_str("110");
  BigInt<2> num110_long("110");
  BigInt<2> num111("111");

  // Prueba del operador =
  BigInt<2> num110_2 = num110_str;
  std::cout << "num110_2: " << num110_2 << std::endl;
  std::cout << "num110_str: " << num110_str << std::endl;
  std::cout << "num110_long: " << num110_long << std::endl;

  // Prueba de los operadores de comparacion
  std::cout << "num110 == num110_2: " << std::boolalpha << (num110_str == num110_2) << std::endl;
  std::cout << "num110 == num111: " << std::boolalpha << (num110_str == num111) << std::endl;
  std::cout << "num110 != num110_2: " << std::boolalpha << (num110_str != num110_2) << std::endl;
  std::cout << "num110 != num111: " << std::boolalpha << (num110_str != num111) << std::endl;
  std::cout << "num110 > num111: " << std::boolalpha << (num110_str < num111) << std::endl;
  std::cout << "num111 > num110: " << std::boolalpha << (num111 < num110_str) << std::endl;
  std::cout << "num110 < num111: " << std::boolalpha << (num110_str < num111) << std::endl;
  std::cout << "num111 < num110: " << std::boolalpha << (num111 < num110_str) << std::endl;
  std::cout << "num110 >= num110_2: " << std::boolalpha << (num110_str >= num110_2) << std::endl;
  std::cout << "num110 >= num111: " << std::boolalpha << (num110_str >= num111) << std::endl;
  std::cout << "num110 <= num110_2: " << std::boolalpha << (num110_str <= num110_2) << std::endl;
  std::cout << "num110 <= num111: " << std::boolalpha << (num110_str <= num111) << std::endl;
  
  // Incremento y decremento
  // std::cout << "num110++: " << num110_str++ << std::endl;

  std::cout << "==============================================================================" << std::endl;
  // ================================================================================================

  // ================================================================================================
  // Pruebas para numeros en base 10
  // Numeros en base 10
  std::cout << "====== Pruebas para numeros en base 10 ======" << std::endl;
  BigInt<10> num123(123);
  BigInt<10> num456(456);
  BigInt<10> num_neg123(-123);
  BigInt<10> num_neg456(-456);

  // Prueba de salida por pantalla
  std::cout << "num123: " << num123 << std::endl;

  // Prueba del operador =
  BigInt<10> num123_2 = num123;
  std::cout << "num123_2: " << num123_2 << std::endl;

  // Prueba de los operadores de comparacion
  std::cout << "num123 == num123_2: " << std::boolalpha << (num123 == num123_2) << std::endl;
  std::cout << "num123 == num456: " << std::boolalpha << (num123 == num456) << std::endl;
  std::cout << "num123 != num123_2: " << std::boolalpha << (num123 != num123_2) << std::endl;
  std::cout << "num123 != num456: " << std::boolalpha << (num123 != num456) << std::endl;
  std::cout << "num123 > num456: " << std::boolalpha << (num123 > num456) << std::endl;
  std::cout << "num456 > num123: " << std::boolalpha << (num456 > num123) << std::endl;
  std::cout << "num123 < num456: " << std::boolalpha << (num123 < num456) << std::endl;
  std::cout << "num456 < num123: " << std::boolalpha << (num456 < num123) << std::endl;
  std::cout << "num123 >= num123_2: " << std::boolalpha << (num123 >= num123_2) << std::endl;
  std::cout << "num123 >= num456: " << std::boolalpha << (num123 >= num456) << std::endl;
  std::cout << "num123 <= num123_2: " << std::boolalpha << (num123 <= num123_2) << std::endl;
  std::cout << "num123 <= num456: " << std::boolalpha << (num123 <= num456) << std::endl;
  
  // Prueba de Incremento y decremento
  // std::cout << "num123++: " << num123++ << std::endl;
  // std::cout << "num456++: " << num456++ << std::endl;

  // Prueba de los operadores aritmeticos
  std::cout << "num123 + num456: " << num123 + num456 << std::endl;

  std::cout << "==============================================================================" << std::endl;
  // ================================================================================================

  // ================================================================================
  // Pruebas para numeros en base 16
  // Numeros en base 16
  std::cout << "====== Pruebas para numeros en base 16 ======" << std::endl;
  BigInt<16> numABC("ABC");
  BigInt<16> num1982ADC("1982ADC");
  BigInt<16> numFF12A("FF12A");

  // Prueba de salida por pantalla
  std::cout << "numABC: " << numABC << std::endl;
  std::cout << "num1982ADC: " << num1982ADC << std::endl;
  std::cout << "numFF12A: " << numFF12A << std::endl;

  return 0;
}