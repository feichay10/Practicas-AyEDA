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

/**
 * @brief Constructor por defecto
 * 
*/
Functions::Functions() {}

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

/**
 * @brief Lee el archivo de entrada
 *
 * @param filename Nombre del archivo de entrada
 */
void Functions::ReadFile(const std::string& filename) {
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

void Functions::WriteFile(const std::string& filename) {
  std::ofstream file(filename);
  std::string line;

  // Escribir la base
  file << "Base = " << base_ << std::endl;

  // Escribir las parejas de etiqueta y número
  for (auto& label : labels_) {
    file << label.first << " = " << label.second << std::endl;
  }

  // Escribir las expresiones
  for (auto& expression : expressions_) {
    file << expression << std::endl;
  }
}