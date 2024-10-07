#include <iostream>
#include <vector>
using namespace std;

//#include "vectorIOint.hh"

/* Buscar  */    
/*int busqueda_lin(const vector<int>& v, int x) */
/* Pre: cierto */
/* Post: el resultado devuelve la posicion de x en v, en el caso de que        
		 exista. En caso contrario, devuelve -1. */
/* {
  int tam = v.size();
  int i = 0;
  bool b = false;
  while (i<tam and not b) {
    if (v[i]==x) b=true; 
    else ++i;
  }
  if (not b) i = -1;
  return i;
} */

int busqueda_lin(const vector<int>& v, int x)
 /* Pre: cierto */
 /* Post: si el resultado es v.size(), x no esta en v;
    en caso contrario, indica la posicion de la primera aparicion de x en v */
{
	bool found = false;
	int pos = 0;
	int size = v.size();
	while (not found and pos < size) {
		if (v[pos] == x) found = true;
		else ++pos;
	}
	
	return pos;
}

/* int main()
{
  vector<int> v;
  leer_vector_int(v); 
  cout << "Escribe el elemento a buscar: " << endl;
  int x;
  cin >> x; 
  int pos = busqueda_lin(v,x);
  if (pos != v.size())  cout << "El elemento " << x << " esta en la posicion " 
  							 << pos << '.' << endl << endl;
  else cout << "El elemento " << x << " no esta en el vector." << endl << endl;
  cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
  escribir_vector_int(v);
} */
