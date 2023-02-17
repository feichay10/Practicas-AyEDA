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
  //================================================================================================
  // Pruebas para numeros en base 2
  // Numeros en base 2
  // std::cout << "==============================================================================" << std::endl;
  // std::cout << "====== Pruebas para numeros en base 2 ======\n" << std::endl;
  // BigInt<2> num110_str("110");
  // BigInt<2> num110_long("110");
  // BigInt<2> num111("111");

  // // Prueba del operador =
  // BigInt<2> num110_2 = num110_str;
  // std::cout << "num110_2: " << num110_2 << std::endl;
  // std::cout << "num110_str: " << num110_str << std::endl;
  // std::cout << "num110_long: " << num110_long << std::endl;

  // // Prueba de los operadores de comparacion
  // std::cout << "num110 == num110_2: " << std::boolalpha << (num110_str == num110_2) << std::endl;
  // std::cout << "num110 == num111: " << std::boolalpha << (num110_str == num111) << std::endl;
  // std::cout << "num110 != num110_2: " << std::boolalpha << (num110_str != num110_2) << std::endl;
  // std::cout << "num110 != num111: " << std::boolalpha << (num110_str != num111) << std::endl;
  // std::cout << "num110 > num111: " << std::boolalpha << (num110_str < num111) << std::endl;
  // std::cout << "num111 > num110: " << std::boolalpha << (num111 < num110_str) << std::endl;
  // std::cout << "num110 < num111: " << std::boolalpha << (num110_str < num111) << std::endl;
  // std::cout << "num111 < num110: " << std::boolalpha << (num111 < num110_str) << std::endl;
  // std::cout << "num110 >= num110_2: " << std::boolalpha << (num110_str >= num110_2) << std::endl;
  // std::cout << "num110 >= num111: " << std::boolalpha << (num110_str >= num111) << std::endl;
  // std::cout << "num110 <= num110_2: " << std::boolalpha << (num110_str <= num110_2) << std::endl;
  // std::cout << "num110 <= num111: " << std::boolalpha << (num110_str <= num111) << std::endl;
  

  // // Incremento y decremento
  // // std::cout << "num110++: " << num110_str++ << std::endl;

  // // Prueba de los operadores aritmeticos
  // // 1101
  // // std::cout << "num110 + num111: " << num110_str + num111 << std::endl;

  // std::cout << "==============================================================================" << std::endl;
  // ================================================================================================

  // ================================================================================================
  // Pruebas para numeros en base 10
  // Numeros en base 10
  std::cout << "====== Pruebas para numeros en base 10 ======" << std::endl;
  BigInt<10> num123(123);
  BigInt<10> num456(456);
  BigInt<10> num_neg123(-123);
  BigInt<10> num_neg456(-456);
  BigInt<10> num20(20);
  BigInt<10> num12(12);
  BigInt<10> num4(4);
  BigInt<10> num5(5);
  BigInt<10> num0("0");
  BigInt<10> num8(8);
  BigInt<10> num2(2);
  BigInt<10> num_neg2(-2);
  BigInt<10> num1(1);

  BigInt<10> num442142117615672(442142117615672);
  BigInt<10> num46651367647546(46651367647546);

  // std::cout << "sum442142117615672 + num46651367647546: " << num442142117615672 + num46651367647546 << std::endl;

  // // Prueba de salida por pantalla
  // std::cout << "num123: " << num123 << std::endl;

  // // Prueba del operador =
  // BigInt<10> num123_2 = num123;
  // std::cout << "num123_2: " << num123_2 << std::endl;

  // // Prueba de los operadores de comparacion
  // std::cout << "num123 == num123_2: " << std::boolalpha << (num123 == num123_2) << std::endl;
  // std::cout << "num123 == num456: " << std::boolalpha << (num123 == num456) << std::endl;
  // std::cout << "num123 != num123_2: " << std::boolalpha << (num123 != num123_2) << std::endl;
  // std::cout << "num123 != num456: " << std::boolalpha << (num123 != num456) << std::endl;
  // std::cout << "num123 > num456: " << std::boolalpha << (num123 > num456) << std::endl;
  // std::cout << "num456 > num123: " << std::boolalpha << (num456 > num123) << std::endl;
  // std::cout << "num123 < num456: " << std::boolalpha << (num123 < num456) << std::endl;
  // std::cout << "num456 < num123: " << std::boolalpha << (num456 < num123) << std::endl;
  // std::cout << "num123 >= num123_2: " << std::boolalpha << (num123 >= num123_2) << std::endl;
  // std::cout << "num123 >= num456: " << std::boolalpha << (num123 >= num456) << std::endl;
  // std::cout << "num123 <= num123_2: " << std::boolalpha << (num123 <= num123_2) << std::endl;
  // std::cout << "num123 <= num456: " << std::boolalpha << (num123 <= num456) << std::endl;

  // // Prueba de Incremento y decremento
  std::cout << "num12++: " << num12++ << std::endl;
  std::cout << "num12 + num12: " << num12 + num12 << std::endl;
  std::cout << "num12 + num2: " << num12 + num2 << std::endl;
  std::cout << "num0--: " << num0-- << std::endl;

  //Prueba de los operadores aritmeticos
  // 579
  // BigInt<10> num1234981230("1234981230");
  // std::cout << "num1234981230 + num2: " << num1234981230 + num2 << std::endl;
  // std::cout << "num123 + num456: " << num123 + num456 << std::endl;
  // BigInt<10> num12(12);
  // std::cout << "num12 + num12: " << num12 + num12 << std::endl;
  // std::cout << "num_neg123 + num_neg456: " << num_neg123 + num_neg456 << std::endl;
  // std::cout << "num123 - num456: " << num123 - num456 << std::endl;
  // std::cout << "num_neg123 - num_neg456: " << num_neg123 - num_neg456 << std::endl;
  // std::cout << "num123 - num_neg456: " << num123 - num_neg456 << std::endl;
  // std::cout << "num123 * num456: " << num123 * num456 << std::endl;
	// std::cout << "num_neg123 * num_neg456: " << num_neg123 * num_neg456 << std::endl;
  // std::cout << "num123 * num_neg456: " << num123 * num_neg456 << std::endl;
  // std::cout << "num20 / num5: " << std::boolalpha << ((num20 / num5) == num4)<< std::endl;
  // std::cout << "num12 / num4: " << num12 / num4 << std::endl;
  // std::cout << "num12 / num5: " << num12 / num5 << std::endl;
  // std::cout << "num12 / num0: " << num12 / num0 << std::endl;
  // std::cout << "((num8 % num2) == num0): " << num8 % num2 << " " << std::boolalpha << ((num8 % num2) == num0) << std::endl;
  // std::cout << "(((-num8) % num2) == num0): " << (-num8) % num2 << " " << std::boolalpha << (((-num8) % num2) == num0) << std::endl;
  // std::cout << "((num8 % (-num2)) == num0): " << (num8 % (-num2)) << " " << std::boolalpha << ((num8 % (-num2)) == num0) << std::endl;
  // std::cout << "((num8 % (-num2)) == num0): " << ((-num8) % (-num2)) << " " << std::boolalpha << (((-num8) % (-num2)) == num0) << std::endl;
  // // Cambiando el orden de los operandos
  // std::cout << "((num2 % num8) == num2): " << std::boolalpha << ((num2 % num8) == num2) << std::endl;
  // std::cout << "(((-num2) % num8) == num_neg2): " << std::boolalpha << (((-num2) % num8) == num_neg2) << std::endl;
  // std::cout << "((num2 % (-num8)) == num2): " << std::boolalpha << ((num2 % (-num8)) == num2) << std::endl;
  // std::cout << "(((-num2) % (-num8)) == num_neg2): " << std::boolalpha << (((-num2) % (-num8)) == num_neg2) << std::endl;

  // Prueba del operador potencia
  BigInt<10> num6(6);
  std::cout << "num2 ^ num6: " << (num2 ^ num6) << std::endl;

  // std::cout << "==============================================================================" << std::endl;
  // ================================================================================================

  // ================================================================================
  // Pruebas para numeros en base 16
  // Numeros en base 16
  // std::cout << "====== Pruebas para numeros en base 16 ======" << std::endl;
  // BigInt<16> numABC("ABC");
  // BigInt<16> num1982ADC("1982ADC");
  // BigInt<16> numFF12A("FF12A");

  // // Prueba de salida por pantalla
  // std::cout << "numABC: " << numABC << std::endl;
  // std::cout << "num1982ADC: " << num1982ADC << std::endl;
  // std::cout << "numFF12A: " << numFF12A << std::endl;

  // // Prueba del operador =
  // BigInt<16> numABC_2 = numABC;
  // std::cout << "numABC_2: " << numABC_2 << std::endl;

  // // Prueba de los operadores de comparacion
  // std::cout << "numABC == numABC_2: " << std::boolalpha << (numABC == numABC_2) << std::endl;
  // std::cout << "numABC == num1982ADC: " << std::boolalpha << (numABC == num1982ADC) << std::endl;
  // std::cout << "numABC != numABC_2: " << std::boolalpha << (numABC != numABC_2) << std::endl;
  // std::cout << "numABC != num1982ADC: " << std::boolalpha << (numABC != num1982ADC) << std::endl;
  // std::cout << "numABC > num1982ADC: " << std::boolalpha << (numABC > num1982ADC) << std::endl;
  // std::cout << "num1982ADC > numABC: " << std::boolalpha << (num1982ADC > numABC) << std::endl;
  // std::cout << "numABC < num1982ADC: " << std::boolalpha << (numABC < num1982ADC) << std::endl;
  // std::cout << "num1982ADC < numABC: " << std::boolalpha << (num1982ADC < numABC) << std::endl;
  // std::cout << "numABC >= numABC_2: " << std::boolalpha << (numABC >= numABC_2) << std::endl;
  // std::cout << "numABC >= num1982ADC: " << std::boolalpha << (numABC >= num1982ADC) << std::endl;
  // std::cout << "numABC <= numABC_2: " << std::boolalpha << (numABC <= numABC_2) << std::endl;
  // std::cout << "numABC <= num1982ADC: " << std::boolalpha << (numABC <= num1982ADC) << std::endl;

  // // Prueba de Incremento y decremento
  // // std::cout << "numABC++: " << numABC++ << std::endl;
  // // std::cout << "num1982ADC++: " << num1982ADC++ << std::endl;

  // // Prueba de los operadores aritmeticos
  // // 1983A78
  // std::cout << "numABC + num1982ADC: " << numABC + num1982ADC << std::endl;
  // BigInt<16> numA("A");
  // std::cout << "numA + numA: " << numA + numA << std::endl;
  

  return 0;
}

// int a_size = a.digits_.size();
//     int b_size = b.digits_.size();
//     BigInt<Base> result;

//     result.GetDigits().clear();

//     while (result.digits_.size() < b_size) {
//       result.digits_.push_back(0);
//       ++a_size;
//     }

//     int i, bit_result, carry = 0;
//     if (a.sign_ == b.sign_) {
//       for (i = 0; i < a_size; ++i) {
//         bit_result = a.digits_[i] + carry;
//         if (i < b_size) {
//           bit_result += b.digits_[i];
//         }
//         carry = bit_result / Base;
//         result.digits_[i] = bit_result % Base;
//       }
//       if (carry != 0) {
//         result.digits_.push_back(carry);
//       }
//     } else {
//       for (i = 0; i < a_size; ++i) {
//         bit_result = a.digits_[i] - carry;
//         carry = 0;
//         if (i < b_size) {
//           bit_result -= b.digits_[i];
//         }
//         if (bit_result < 0) {
//           carry++;
//           bit_result = Base + bit_result;
//         }
//         result.digits_[i] = bit_result;
//       }

//       if (carry != 0) {
//         result.digits_.push_back(carry);
//       }

//       while (result.digits_.back() == 0 && result.digits_.size() > 1) {
//         result.digits_.resize(result.digits_.size() - 1);
//       }
//     }

//     return result;