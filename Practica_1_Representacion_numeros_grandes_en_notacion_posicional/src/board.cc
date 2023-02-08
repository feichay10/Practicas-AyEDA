/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Representación de números grandes en notación posicional
 * @file board.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/board.h"

/**
 * @brief Constructor de la clase Board
 * @param filename Nombre del archivo de entrada
 *
 * Lee el archivo de entrada y almacena la base y las etiquetas y expresiones
 * en un mapa y un vector respectivamente
 */
Board::Board(const std::string& filename) {
  std::ifstream file(filename);
  std::string line;

  // Leer la base
  std::getline(file, line);
  std::size_t pos = line.find("=");
  base_ = std::stoi(line.substr(pos + 2));

  // Leer las parejas de etiqueta y número
  while (std::getline(file, line)) {
    pos = line.find("=");
    std::string label = line.substr(0, pos - 1);
    std::string value = line.substr(pos + 2);

    // Almacena en un mapa si comienza con "N" que seria un numero BigInt
    // N1 = 442142117615672
    // N2 = 46651367647546
    // E1 = N1 N2 +
    // E2 = E1 N1 N2 - +
    if (label[0] == 'N') {
      labels_[label] = value;
    } else if (label[0] == 'E') {
      expressions_.push_back(value);
    }
  }
}

/**
 * @brief Devuelve la base leída del archivo de entrada
 * @return Valor de la base
 */
int Board::getBase() const { return base_; }

/**
 * @brief Devuelve las etiquetas leídas del archivo de entrada
 * @return Mapa de etiquetas y valores
 */
std::map<std::string, std::string> Board::getLabels() const { return labels_; }

/**
 * @brief Devuelve las expresiones leídas del archivo de entrada
 * @return Vector de expresiones
 */
std::vector<std::string> Board::getExpressions() const { return expressions_; }