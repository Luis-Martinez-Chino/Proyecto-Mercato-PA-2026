#pragma once
#include <iostream>
#include <string>
#include "Jugador.h"

using namespace std;

class Delantero : public Jugador {
public:
	Delantero(string nombre, int id, int valorMercado, string clubActual) : Jugador(nombre, id, valorMercado, clubActual) {
	}
	string mostrarDescripcion() override;
	string getTipo() override;
	~Delantero() override {
	}
};
