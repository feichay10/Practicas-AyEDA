/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Representación de números grandes en notación posicional
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

const std::string HELP1 = "--help";
const std::string HELP2 = "-h";

/**
 * @class Functions
 * @brief Almacena los datos leídos de un archivo de entrada
 */
class Functions {
 public:
  Functions();

  int getBase() const;
  std::map<std::string, std::string> getExpressions() const;

  void CheckParameters(int, char**);
  void ReadFile(const std::string& filename);
  void WriteFile(const std::string& filename);
  void WriteOnScreen();

 private:
  int base_;
  std::map<std::string, std::string> expressions_;
};

#endif  // FUNCTIONS_H_