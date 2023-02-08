/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Representación de números grandes en notación posicional
 * @file board.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

/**
 * @class Board
 * @brief Almacena los datos leídos de un archivo de entrada
 */
class Board {
 public:
  Board(const std::string& filename);
  int getBase() const;
  std::map<std::string, std::string> getLabels() const;
  std::vector<std::string> getExpressions() const;

 private:
  int base_;
  std::map<std::string, std::string> labels_;
  std::vector<std::string> expressions_;
};