/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-05-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef KEY_H_
#define KEY_H_

template <typename T>
class Key {
 public:
  Key(T key) : key_(key) {}
  Key() = default;
  ~Key() = default;
  T getKey() const { return key_; }

  // Operator overload
  bool operator<(const Key& key) const { return key_ < key.key_; }
  bool operator>(const Key& key) const { return key_ > key.key_; }
  bool operator==(const Key& key) const { return key_ == key.key_; }

  // Operator >> overload
  friend std::istream& operator>>(std::istream& is, Key& key) {
    is >> key.key_;
    return is;
  }

  // Operator << overload
  friend std::ostream& operator<<(std::ostream& os, const Key& key) {
    os << key.key_;
    return os;
  }

 private:
  T key_;
};

#endif //KEY_H_