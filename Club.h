#pragma once
#include <string>
#include <vector>
#include "Jugador.h"

using namespace std;

struct Club {
    int id;
    string nombre;
    int presupuesto;
    vector<Jugador*> jugadores;
};

struct Oferta {
    int id;
    Jugador* jugador;
    int clubComprador;
    int clubVendedor;
    int monto;
    string estado;
};

struct Transferencia {
    int dia;
    Jugador* jugador;
    int clubOrigen;
    int clubDestino;
    int montoPagado;
};
