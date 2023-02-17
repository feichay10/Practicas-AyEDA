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

#include <fstream>
#include <iostream>

#include "../include/bigint.h"
#include "../include/calculator.h"

void ReadFile(std::string&);

/**
 * @brief Funcion principal del programa
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char* argv[]) {
  Calculator<BigInt<2>> calculator2;
  Calculator<BigInt<8>> calculator8;
  Calculator<BigInt<10>> calculator10;
  Calculator<BigInt<16>> calculator16;
  std::ifstream file_in(argv[1]);
  std::ofstream file_out(argv[2]);
  std::vector<std::vector<std::string>> expressions;
  std::string line;

  if (file_in.is_open()) {
    while (getline(file_in, line)) {
      std::istringstream iss(line);
      std::vector<std::string> line_expressions;
      std::string expression;
      while (iss >> expression) {
        line_expressions.push_back(expression);
      }
      expressions.push_back(line_expressions);
    }
  } else {
    std::cout << "No se ha podido abrir el archivo" << std::endl;
  }

  file_in.close();

  size_t base = std::stoi(expressions[0][expressions[0].size() - 1]);
  expressions.erase(expressions.begin());
  
  switch (base) {
    case 2:
      std::cout << "Base 2" << std::endl;
      calculator2.SetExpression(expressions);
      calculator2.ProcessExpression();
      file_out << calculator2;
      break;
    case 8:
      std::cout << "Base 8" << std::endl;
      calculator8.SetExpression(expressions);
      calculator8.ProcessExpression();
      file_out << calculator8;
      break;
    case 10:
      std::cout << "Base 10" << std::endl;
      calculator10.SetExpression(expressions);
      calculator10.ProcessExpression();
      file_out << calculator10;
      break;
    case 16:
      std::cout << "Base 16" << std::endl;
      calculator16.SetExpression(expressions);
      calculator16.ProcessExpression();
      file_out << calculator16;
      break;
    default:
      std::cout << "Base no soportada" << std::endl;
      break;
  }

  return 0;
}
