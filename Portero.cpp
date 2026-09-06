#include "pch.h"
#include "Portero.h"


string Portero::mostrarDescripcion() {
	return "Portero: " + nombre + ", ID: " + to_string(id) + ", Valor de Mercado: " + to_string(valorMercado) + ", Club Actual: " + clubActual;
}

string Portero::getTipo() {
	return "Portero";
}