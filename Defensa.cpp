#include "pch.h"
#include "Defensa.h"


string Defensa::mostrarDescripcion() {
	return "Defensa: " + nombre + ", ID: " + to_string(id) + ", Valor de Mercado: " + to_string(valorMercado) + ", Club Actual: " + clubActual;
}

string Defensa::getTipo() {
	return "Defensa";
}