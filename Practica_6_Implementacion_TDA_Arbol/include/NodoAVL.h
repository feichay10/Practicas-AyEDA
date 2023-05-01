/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @file NodoAVL.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-05-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NODOAVL_H_
#define NODOAVL_H_

template <class Key>
class NodoAVL : public NodoB<Key>{
 public:
  NodoAVL(void);
  NodoAVL(const Key& data, NodoAVL<Key>* left = NULL, NodoAVL<Key>* right = NULL);
  ~NodoAVL() = default;

  int getBal(void);
  NodoAVL<Key>* getPtrLeft(void) const;
  NodoAVL<Key>*& getPtrLeft(void);
  NodoAVL<Key>* getPtrRight(void) const;
  NodoAVL<Key>*& getPtrRight(void);
  void setBal(const int& bal);
  void setPtrLeft(NodoAVL<Key>* &left = NULL);
  void setPtrRight(NodoAVL<Key>* &right = NULL);

  NodoAVL<Key>& operator=(const NodoAVL<Key>& nodo);
  friend std::ostream& operator<<(std::ostream& out, const NodoAVL<Key>& nodo) {
    out << nodo.data_;
    return out;
  }

 private:
  int bal_;
};

#endif //NODOAVL_H_