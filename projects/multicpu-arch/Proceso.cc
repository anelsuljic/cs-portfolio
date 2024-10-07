/** @file Proceso.cc
    @brief Código de la clase Proceso.
*/


#include "Proceso.hh"


Proceso::Proceso()
{
    id = 0;
    tam = 1;
    teje = 1;
    nulo = false;
}

Proceso::Proceso(int tam)
{
    this -> tam = tam;
    nulo = true;
}

void Proceso::avanzar_tiempo(int tiempo)
{
    teje -= tiempo;
}

bool Proceso::es_nulo() const
{
    return nulo;
}

int Proceso::consultar_id() const
{
    return id;
}

int Proceso::consultar_memoria() const
{
    return tam;
}

int Proceso::consultar_tiempo() const
{
    return teje;
}

void Proceso::leer()
{
    cin >> id >> tam >> teje;
}

void Proceso::escribir() const
{
    cout << id << ' ' << tam << ' ' << teje << endl;
}