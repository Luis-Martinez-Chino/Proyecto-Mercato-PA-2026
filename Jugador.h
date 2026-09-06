#pragma once
#include <string>
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
	virtual string mostrarDescripcion() = 0;
	virtual string getTipo() = 0;
	virtual int getId();
	virtual string getNombre();
	virtual int getValorMercado();
	virtual void setValorMercado(int valor);
	virtual string getClubActual();
	virtual void setClubActual(string club);
	virtual ~Jugador() {
	}
};

