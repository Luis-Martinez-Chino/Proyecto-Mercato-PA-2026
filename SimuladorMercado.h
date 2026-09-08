#pragma once
#include <string>
#include <vector>
#include "Club.h"
#include "DatosIniciales.h"

using namespace std;

class SimuladorMercado {
private:
    vector<Club> clubes;
    int clubUsuario;
    int diaActual;
    int diasTotales;
    vector<Oferta> ofertas;
    vector<Transferencia> historial;

    Jugador* crearJugadorDesdeDato(const DatoJugador& dato); 

public:
    void iniciarPartida();
    void verMiClub();
    void explorarJugadores(string filtro);
    void realizarOferta(int idJugador, int monto);
    void revisarOfertasRecibidas();
    void verHistorial();
    void avanzarDia();
    void generarReporteFinal();
    ~SimuladorMercado();
};