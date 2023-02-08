/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Representación de números grandes en notación posicional
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/functions.h"

Functions::Functions() {}

/**
 * @brief Constructor de la clase Functions
 * @param filename Nombre del archivo de entrada
 *
 * Lee el archivo de entrada y almacena la base y las etiquetas y expresiones
 * en un mapa y un vector respectivamente
 */
Functions::Functions(const std::string& filename) {
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
int Functions::getBase() const { return base_; }

/**
 * @brief Devuelve las etiquetas leídas del archivo de entrada
 * @return Mapa de etiquetas y valores
 */
std::map<std::string, std::string> Functions::getLabels() const { return labels_; }

/**
 * @brief Devuelve las expresiones leídas del archivo de entrada
 * @return Vector de expresiones
 */
std::vector<std::string> Functions::getExpressions() const { return expressions_; }

/**
 * @brief Comprueba si el número de parámetros es correcto
 *
 * @param argc Número de parámetros
 * @param argv Parámetros
 */
void Functions::CheckParameters(int argc, char* argv[]) {
  if (argc == 2) {
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