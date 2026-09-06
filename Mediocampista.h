#pragma once
#include <iostream>
#include <string>
#include "Jugador.h"

using namespace std;

class Mediocampista : public Jugador {
public:
	Mediocampista(string nombre, int id, int valorMercado, string clubActual) : Jugador(nombre, id, valorMercado, clubActual) {
	}
	string mostrarDescripcion() override;
	string getTipo() override;
	~Mediocampista() override {
	}
};
