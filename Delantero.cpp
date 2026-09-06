#include "pch.h"
#include "Delantero.h"

string Delantero::mostrarDescripcion() {
	return "Delantero: " + nombre + ", ID: " + to_string(id) + ", Valor de Mercado: " + to_string(valorMercado) + ", Club Actual: " + clubActual;
}

string Delantero::getTipo() {
	return "Delantero";
}