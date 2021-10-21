#include <iostream>
#include "pila_array.hpp"

int main()
{
  Pila<int> p1;
  p1.apilar(4);
  p1.apilar(5);
  p1.apilar(6);
  p1.desapilar();
  p1.apilar(7);
  p1.apilar(8);
  std::cout <<"p1 tiene profundidad " << p1.profundidad() << "; p1 = " << p1 << ";\n";
  while (!p1.es_pila_vacia()) {
    std::cout << p1.cima() << "\n";
    p1.desapilar();
  }
}
