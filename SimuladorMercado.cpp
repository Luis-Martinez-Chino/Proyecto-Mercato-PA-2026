#include "pch.h"
#include "SimuladorMercado.h"
#include "DatosIniciales.h"
#include "Portero.h"
#include "Defensa.h"
#include "Mediocampista.h"
#include "Delantero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

    // 1. Crear los 6 clubes con presupuesto aleatorio
    for (int i = 0; i < (int)nombresClubes.size(); i++) {
        Club nuevoClub;
        nuevoClub.id = i + 1;
        nuevoClub.nombre = nombresClubes[i];
        nuevoClub.presupuesto = 100 + rand() % (200 - 100 + 1);
        clubes.push_back(nuevoClub);
    }

    // 2. Crear los 30 jugadores y asignarlos a su club correspondiente
    for (int i = 0; i < TOTAL_JUGADORES_INICIALES; i++) {
        Jugador* nuevoJugador = crearJugadorDesdeDato(DATOS_JUGADORES[i]);

        if (nuevoJugador != nullptr) {
            for (int c = 0; c < (int)clubes.size(); c++) {
                if (clubes[c].nombre == DATOS_JUGADORES[i].club) {
                    clubes[c].jugadores.push_back(nuevoJugador);
                    break;
                }
            }
        }
    }

    // 3. Solicitar al usuario que club desea administrar
    cout << "Clubes disponibles:" << endl;
    for (int c = 0; c < (int)clubes.size(); c++) {
        cout << clubes[c].id << ". " << clubes[c].nombre << endl;
    }

    do {
        cout << "Seleccione el numero del club que desea administrar: ";
        cin >> clubUsuario;
        if (clubUsuario < 1 || clubUsuario > (int)clubes.size()) {
            cout << "Club invalido. Por favor seleccione un numero entre 1 y " << clubes.size() << "." << endl;
        }
	} while (clubUsuario < 1 || clubUsuario >(int)clubes.size());

    // 4. Solicitar cantidad de dias de simulacion (validado entre 5 y 15)
    do {
        cout << "Ingrese la cantidad de dias de simulacion (5-15): ";
        cin >> diasTotales;
        if (diasTotales < 5 || diasTotales > 15) {
            cout << "Cantidad invalida. Debe estar entre 5 y 15." << endl;
        }
    } while (diasTotales < 5 || diasTotales > 15);

    diaActual = 1;

    // 5. Mostrar los datos generados antes de iniciar el primer dia
    cout << "\n===== DATOS INICIALES DE LA SIMULACION =====" << endl;
    for (int c = 0; c < (int)clubes.size(); c++) {
        cout << "\nClub: " << clubes[c].nombre
            << " | Presupuesto: " << clubes[c].presupuesto << "M" << endl;
        for (int j = 0; j < (int)clubes[c].jugadores.size(); j++) {
            cout << "  - " << clubes[c].jugadores[j]->mostrarDescripcion() << endl;
        }
    }
    cout << "\nDias de simulacion: " << diasTotales << endl;
    cout << "==============================================\n" << endl;
}

SimuladorMercado::~SimuladorMercado() {
    for (int c = 0; c < (int)clubes.size(); c++) {
        for (int j = 0; j < (int)clubes[c].jugadores.size(); j++) {
            delete clubes[c].jugadores[j];
            clubes[c].jugadores[j] = nullptr;
        }
        clubes[c].jugadores.clear();
    }
}
