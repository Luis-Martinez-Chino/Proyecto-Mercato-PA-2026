#include "pch.h"
#include "Mediocampista.h"

string Mediocampista::mostrarDescripcion() {
	return "Mediocampista: " + nombre + ", ID: " + to_string(id) + ", Valor de Mercado: " + to_string(valorMercado) + ", Club Actual: " + clubActual;
}

string Mediocampista::getTipo() {
	return "Mediocampista";
}
