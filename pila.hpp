#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <stdexcept>

template <typename T>
struct Nodo {
  T e;
  Nodo<T>* s;
};

template <typename T>
class Pila {
private:
  Nodo<T>* pila;
  int _profundidad;

public:
  Pila();
  ~Pila();
  void pila_vacia(void);
  void apilar(const T& e);
  void desapilar(void);
  T& cima(void) const;
  bool es_pila_vacia(void) const;
  int profundidad(void) const;
  friend std::ostream& operator<< (std::ostream& out, const Pila<T>& p)
  {
    if (p.es_pila_vacia())
      out << "[]";
    out << "[";
    for (Nodo<T>* nodo = p.pila; nodo != nullptr; nodo = nodo->s)
      out << nodo->e << ", ";
    out << "\033[2D]";
    return out;
  }
};

template <typename T>
std::ostream &operator<< (std::ostream& out, const Pila<T>& p);


template <typename T>
Pila<T>::Pila()
{
  pila_vacia();
}

template <typename T>
Pila<T>::~Pila()
{
  if (!es_pila_vacia())
    std::cout << "Pila no vacia liberada.\n";
  while(!es_pila_vacia())
    desapilar();
}

template <typename T>
void Pila<T>::pila_vacia(void)
{
  pila = nullptr;
}

template <typename T>
void Pila<T>::apilar(const T& e)
{
  Nodo<T>* tmp = new Nodo<T>;
  tmp->s = pila;
  tmp->e = e;
  pila = tmp;
}

template <typename T>
void Pila<T>::desapilar(void)
{
  if (es_pila_vacia())
    throw std::invalid_argument("desapilar() indefinido para la pila vacia.");
  Nodo<T>* tmp = pila;
  pila = pila->s;
  delete tmp;
}

template <typename T>
T& Pila<T>::cima(void) const
{
  if (es_pila_vacia())
    throw std::invalid_argument("cima() indefinido para la pila vacia.");
  return pila->e;
}

template <typename T>
bool Pila<T>::es_pila_vacia(void) const
{
  return (pila == nullptr);
}

template <typename T>
int Pila<T>::profundidad(void) const
{
  int profundidad = 0;
  for (Nodo<T>* nodo = pila; nodo != nullptr; nodo = nodo->s) {
    profundidad++;
  }
  return profundidad;
}


#endif //PILA_H
