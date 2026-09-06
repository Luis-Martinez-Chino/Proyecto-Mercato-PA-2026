#include "pch.h"
#include "Jugador.h"


int Jugador::getId() {		// Implementación del método getId
	return id;
}

string Jugador::getNombre() {		// Implementación del método getNombre
	return nombre;
}

int Jugador::getValorMercado() {		// Implementación del método getValorMercado
	return valorMercado;
}

void Jugador::setValorMercado(int valor) {		// Implementación del método setValorMercado
	valorMercado = valor;
}

string Jugador::getClubActual() {		// Implementación del método getClubActual
	return clubActual;
}

void Jugador::setClubActual(string club) {		// Implementación del método setClubActual
	clubActual = club;
}