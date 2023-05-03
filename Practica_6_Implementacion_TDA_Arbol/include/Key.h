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
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef KEY_H_
#define KEY_H_

template <typename T>
class Key {
 public:
  Key(T key);
  Key() = default;
  ~Key() = default;
  T getKey() const;

  // Operator overload
  bool operator<(const Key& key);
  bool operator>(const Key& key);
  bool operator==(const Key& key);

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

template <typename T>
Key<T>::Key(T key) {
  key_ = key;
}

template <typename T>
T Key<T>::getKey() const {
  return key_;
}

template <typename T>
bool Key<T>::operator<(const Key& key) {
  return key_ < key.key_;
}

template <typename T>
bool Key<T>::operator>(const Key& key) {
  return key_ > key.key_;
}

template <typename T>
bool Key<T>::operator==(const Key& key) {
  return key_ == key.key_;
}

#endif //KEY_H_