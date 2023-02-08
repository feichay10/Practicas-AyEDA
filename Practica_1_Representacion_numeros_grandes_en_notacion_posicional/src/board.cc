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
 * Abre el archivo de entrada y lee los datos. Lee primero la base y luego
 * las parejas de etiquetas y valores. Almacena las etiquetas en un mapa
 * labels_ si la etiqueta no comienza con "E", y las almacena en un vector
 * expressions_ si la etiqueta comienza con "E".
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

    // Almacenar en un mapa si la etiqueta no comienza con "E"
    if (label[0] != 'E') {
      labels_[label] = value;
    }
    // Almacenar en un vector si la etiqueta comienza con "E"
    else {
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