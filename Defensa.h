#pragma once
#include <iostream>
#include <string>
#include "Jugador.h"

using namespace std;

class Defensa : public Jugador {
public:
	Defensa(string nombre, int id, int valorMercado, string clubActual) : Jugador(nombre, id, valorMercado, clubActual) {
	}
	string mostrarDescripcion() override;
	string getTipo() override;
	~Defensa() override {
	}
};
