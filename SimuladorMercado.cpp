#include "DatosIniciales.h"
#include "SimuladorMercado.h"
#include "Portero.h"
#include "Defensa.h"
#include "Mediocampista.h"
#include "Delantero.h"
#include <cstdlib>
#include <ctime>

Jugador* SimuladorMercado::crearJugadorDesdeDato(const DatoJugador& dato) {
    int valor = 0;

    if (dato.posicion == "Portero") {
        valor = 20 + rand() % (70 - 20 + 1);
		return new Portero(dato.nombre, dato.id, valor, dato.club);
    }
    else if (dato.posicion == "Defensa") {
        valor = 25 + rand() % (90 - 25 + 1);
        return new Defensa(dato.nombre, dato.id, valor, dato.club);
    }
    else if (dato.posicion == "Mediocampista") {
        valor = 30 + rand() % (110 - 30 + 1);
        return new Mediocampista(dato.nombre, dato.id, valor, dato.club);
    }
    else if (dato.posicion == "Delantero") {
        valor = 35 + rand() % (140 - 35 + 1);
        return new Delantero(dato.nombre, dato.id, valor, dato.club);
    }

    return nullptr;
}

void SimuladorMercado::iniciarPartida() {
    srand((unsigned int)time(nullptr)); 

    vector<string> nombresClubes = {
        "Real Madrid", "FC Barcelona", "Manchester City",
        "Liverpool", "Bayern Munich", "Paris Saint-Germain"
    };

    for (int i = 0; i < (int)nombresClubes.size(); i++) {
        Club nuevoClub;
        nuevoClub.id = i + 1;
        nuevoClub.nombre = nombresClubes[i];
        nuevoClub.presupuesto = 100 + rand() % (200 - 100 + 1);
        clubes.push_back(nuevoClub);
    }

    for (int i = 0; i < TOTAL_JUGADORES_INICIALES; i++) {
        Jugador* nuevoJugador = crearJugadorDesdeDato(DATOS_JUGADORES[i]);

        for (int c = 0; c < (int)clubes.size(); c++) {
            if (clubes[c].nombre == DATOS_JUGADORES[i].club) {
                clubes[c].jugadores.push_back(nuevoJugador);
                break;
            }
        }
    }
}