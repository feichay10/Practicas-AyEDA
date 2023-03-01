/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: Calculadora de números grandes en binario
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-03-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <fstream>
#include <iostream>

#include "../include/bigint.h"
#include "../include/calculator.h"

const std::string HELP1 = "--help";
const std::string HELP2 = "-h";

void CheckParameters(int, char**);

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

  CheckParameters(argc, argv);

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
      std::cout << calculator2;
      file_out << calculator2;
      break;
    case 8:
      std::cout << "Base 8" << std::endl;
      calculator8.SetExpression(expressions);
      calculator8.ProcessExpression();
      std::cout << calculator8;
      file_out << calculator8;
      break;
    case 10:
      std::cout << "Base 10" << std::endl;
      calculator10.SetExpression(expressions);
      calculator10.ProcessExpression();
      std::cout << calculator10;
      file_out << calculator10;
      break;
    case 16:
      std::cout << "Base 16" << std::endl;
      calculator16.SetExpression(expressions);
      calculator16.ProcessExpression();
      std::cout << calculator16;
      file_out << calculator16;
      break;
    default:
      std::cout << "Base no soportada" << std::endl;
      break;
  }

  return 0;
}

void CheckParameters(int argc, char* argv[]) {
  if (argc == 3) {
    std::string parameter = argv[1];
    if (parameter == HELP1 || parameter == HELP2) {
      std::cout << "Uso: " << argv[0] << " <input file> || -h || --help" << std::endl;
      std::cout << "OPCION:" << std::endl;
      std::cout << "  -h, --help\t\tAyuda del programa." << std::endl;
      std::cout << "  <input file>\t\tFichero de entrada con los datos de entrada." << std::endl;
      exit(EXIT_SUCCESS);
    }
  } else {
    std::cout << "Error: El número de parámetros es incorrecto." << std::endl;
    std::cout << "Use -h o --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }
}