#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Jugador {
protected:
	string nombre;
	int id;
	int valorMercado;
	string clubActual;
public:
	Jugador(string nombre, int id, int valorMercado, string clubActual) {
		this->nombre = nombre;
		this->id = id;
		this->valorMercado = valorMercado;
		this->clubActual = clubActual;
	}
	virtual void mostrarDescripcion();
	virtual string getTipo() = 0;
	virtual int getId() = 0;
	virtual string getNombre() = 0;
	virtual int getValorMercado() = 0;
	virtual void setValorMercado(int valor) = 0;
	virtual string getClubActual() = 0;
	virtual void setClubActual(string club) = 0;
	virtual ~Jugador() {
	}
};