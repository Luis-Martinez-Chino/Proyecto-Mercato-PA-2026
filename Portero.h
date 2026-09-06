#pragma once
#include <string>
#include <iostream>
#include "Jugador.h"

using namespace std;

class Portero : public Jugador {
public:
	Portero(string nombre, int id, int valorMercado, string clubActual) : Jugador(nombre, id, valorMercado, clubActual) {
	}
	string mostrarDescripcion() override;
	string getTipo() override;
	~Portero() override {
	}
};

