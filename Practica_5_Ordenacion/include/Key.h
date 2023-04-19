/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Implementación de Métodos de Ordenación
 * @file Key.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef KEY_H
#define KEY_H

template<typename T>
class Key {
  public:
    Key() = default;
    Key(T key) : key_(key) {}
    ~Key() = default;

    T get_key() const { return key_; }
    void set_key(T key) { key_ = key; }

    // Overload operators
    bool operator<(const Key<T> &other) const;
    bool operator>(const Key<T> &other) const;
    bool operator<=(const Key<T> &other) const;
    T operator/(const Key<T> &other) const;

  private:
    friend std::ostream& operator<<(std::ostream &os, const Key &key) {
      os << key.key_;
      return os;
    }

    friend std::istream& operator>>(std::istream &is, Key &key) {
      is >> key.key_;
      return is;
    }

    T key_;
};

template<typename T>
bool Key<T>::operator<(const Key<T> &other) const {
  return key_ < other.key_;
}

template<typename T>
bool Key<T>::operator>(const Key<T> &other) const {
  return key_ > other.key_;
}

template<typename T>
bool Key<T>::operator<=(const Key<T> &other) const {
  return key_ <= other.key_;
}

template<typename T>
T Key<T>::operator/(const Key<T> &other) const {
  return key_ / other.key_;
}

#endif // KEY_H