#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <stdexcept>

#define INIT_CAP 4

template <typename T>
class Pila {
private:
  T* pila;
  int primero;
  int num_elems;
  int capacidad;

public:
  Pila();
  ~Pila();
  void pila_vacia(void);
  void apilar(const T& e);
  void desapilar(void);
  T& cima(void) const;
  bool es_pila_vacia(void) const;
  bool esta_llena(void) const;
  int profundidad(void) const;
  friend std::ostream& operator<< (std::ostream& out, const Pila<T>& p)
  {
    if (p.es_pila_vacia())
      out << "[]";
    out << "[";
    for (int i = p.primero; i < p.primero + p.num_elems; i++)
      out << p.pila[i%p.capacidad] << ", ";
    out << "\033[2D]";
    return out;
  }
};

template <typename T>
std::ostream& operator<< (std::ostream& out, const Pila<T>& p);

template <typename T>
Pila<T>::Pila()
{
  pila_vacia();
}

template <typename T>
Pila<T>::~Pila()
{
  if(!es_pila_vacia())
    std::cout << "Pila no vacia liberada.\n";
  delete pila;
}

template <typename T>
void Pila<T>::pila_vacia(void)
{
  pila = new T[INIT_CAP];
  primero = 0;
  num_elems = 0;
  capacidad = INIT_CAP;
}

template <typename T>
void Pila<T>::apilar(const T& e)
{
  if (!esta_llena()) {
    pila[(primero + num_elems) % capacidad] = e;
    num_elems++;
  }
  else {
     T* nueva_pila = new T[capacidad*2];
     for (int i = 0; i < capacidad; i++) {
       nueva_pila[i] = pila[(primero + i) % capacidad];
     }
     delete pila;
     pila = nueva_pila;

     pila[num_elems] = e;
     primero = 0;
     num_elems++;
     capacidad*=2;
  }
}

template <typename T>
void Pila<T>::desapilar(void)
{
  if(es_pila_vacia())
    throw std::invalid_argument("desapilar() indefinido para la pila vacia.");

  if (primero < capacidad - 1)
    primero++;
  else
    primero = 0;
  
  num_elems--;
}

template <typename T>
T& Pila<T>::cima(void) const
{
  if (es_pila_vacia())
    throw std::invalid_argument("cima() indefinido para la pila vacia.");

  return pila[primero];
}

template <typename T>
bool Pila<T>::es_pila_vacia(void) const
{
  return (num_elems == 0);
}

template <typename T>
int Pila<T>::profundidad(void) const
{
  return num_elems;
}

template <typename T>
bool Pila<T>::esta_llena(void) const
{
  return (num_elems == capacidad);
}

#endif //PILA_H
