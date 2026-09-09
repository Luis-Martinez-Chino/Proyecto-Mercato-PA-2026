
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
    
                                                                                               // CONFIG INICIAL CLUBES
    cout << "=== Bienvenido a Mercato 2026 ===" << endl;
    cout << "\nClubes disponibles:" << endl;
    for (int c = 0; c < (int)clubes.size(); c++) {
        cout << clubes[c].id << ". " << clubes[c].nombre << endl;
    }

    int idElegido;
    cout << "\nElige el club que deseas administrar (1-" << clubes.size() << "): ";
    cin >> idElegido;

    while (cin.fail() || idElegido < 1 || idElegido >(int)clubes.size()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Elige un numero entre 1 y " << clubes.size() << ": ";
        cin >> idElegido;
    }

    clubUsuario = idElegido - 1;

                                                                                               // CUANTOS DIAS A SIMULAR
    cout << "\nCuantos dias deseas simular (5-15): ";
    cin >> diasTotales;

    while (cin.fail() || diasTotales < 5 || diasTotales > 15) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Ingresa un numero entre 5 y 15: ";
        cin >> diasTotales;
    }

    diaActual = 1;

                                                                                               // DATOS INICALES
    cout << "\n=== Datos de la partida ===" << endl;
    cout << "Club administrado: " << clubes[clubUsuario].nombre << endl;
    cout << "Presupuesto inicial: " << clubes[clubUsuario].presupuesto << "M" << endl;
    cout << "Dias de simulacion: " << diasTotales << endl;

    cout << "\nPresupuestos de todos los clubes:" << endl;
    for (int c = 0; c < (int)clubes.size(); c++) {
        cout << " - " << clubes[c].nombre << ": " << clubes[c].presupuesto << "M" << endl;
    }

    cout << "\nPlantilla inicial de tu club:" << endl;
    for (int j = 0; j < (int)clubes[clubUsuario].jugadores.size(); j++) {
        cout << " - " << clubes[clubUsuario].jugadores[j]->mostrarDescripcion() << endl;
    }

    cout << "\n=== Comienza el mercado de fichajes ===" << endl;
}

void SimuladorMercado::verMiClub() {                                                              // VER MI CLUB

    Club& club = clubes[clubUsuario];
    cout << "\n===== INFORMACION DE MI CLUB =====" << endl;
    cout << "Club: " << club.nombre << " | Presupuesto: " << club.presupuesto << "M" << endl;
    cout << "Plantilla:" << endl;
    for (int j = 0; j < (int)club.jugadores.size(); j++) {
        cout << "  - " << club.jugadores[j]->mostrarDescripcion() << endl;
    }
    cout << "==================================\n" << endl;
}

void SimuladorMercado::explorarJugadores(string filtro) {
    bool esNumero = !filtro.empty();
    for (int k = 0; k < (int)filtro.size(); k++) {
        if (!isdigit(filtro[k])) {
            esNumero = false;
            break;
        }
    }

    bool encontrado = false;

    cout << "\n--- Jugadores disponibles en otros clubes ---" << endl;

    if (esNumero) {
        int idBuscado = stoi(filtro);
        for (int c = 0; c < (int)clubes.size(); c++) {
            if (c == clubUsuario) continue; // solo otros clubes

            for (int j = 0; j < (int)clubes[c].jugadores.size(); j++) {
                if (clubes[c].jugadores[j]->getId() == idBuscado) {
                    cout << clubes[c].jugadores[j]->mostrarDescripcion() << endl;
                    encontrado = true;
                }
            }
        }
    }
    else if (!filtro.empty()) {
        // Filtrar por posicion
        for (int c = 0; c < (int)clubes.size(); c++) {
            if (c == clubUsuario) continue;

            for (int j = 0; j < (int)clubes[c].jugadores.size(); j++) {
                if (clubes[c].jugadores[j]->getTipo() == filtro) {
                    cout << clubes[c].jugadores[j]->mostrarDescripcion() << endl;
                    encontrado = true;
                }
            }
        }
    }
    else {
        // Listar todos los jugadores de los otros clubes
        for (int c = 0; c < (int)clubes.size(); c++) {
            if (c == clubUsuario) continue;

            for (int j = 0; j < (int)clubes[c].jugadores.size(); j++) {
                cout << clubes[c].jugadores[j]->mostrarDescripcion() << endl;
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron jugadores con ese criterio." << endl;
    }
}

void SimuladorMercado::realizarOferta(int idJugador, int monto) {
    int clubVendedor = buscarClubDeJugador(idJugador);

    if (clubVendedor == -1) {
        cout << "Error: no existe un jugador con ese ID." << endl;
        return;
    }

    if (clubVendedor == clubUsuario) {
        cout << "Error: no puedes ofertar por un jugador de tu propio club." << endl;
        return;
    }

    Jugador* jugadorObjetivo = nullptr;
    for (int j = 0; j < (int)clubes[clubVendedor].jugadores.size(); j++) {
        if (clubes[clubVendedor].jugadores[j]->getId() == idJugador) {
            jugadorObjetivo = clubes[clubVendedor].jugadores[j];
            break;
        }
    }

    if (monto <= 0) {
        cout << "Error: el monto debe ser mayor a 0." << endl;
        return;
    }
    
    Oferta nuevaOferta;
    nuevaOferta.id = (int)ofertas.size() + 1;
    nuevaOferta.jugador = jugadorObjetivo;
    nuevaOferta.clubComprador = clubUsuario;
    nuevaOferta.clubVendedor = clubVendedor;
    nuevaOferta.monto = monto;
    nuevaOferta.estado = "Pendiente";

    ofertas.push_back(nuevaOferta);

    cout << "Oferta registrada por " << jugadorObjetivo->getNombre()
        << " por " << monto << " millones. Se resolvera al avanzar el dia." << endl;
}

int SimuladorMercado::buscarClubDeJugador(int idJugador) {
    for (int c = 0; c < (int)clubes.size(); c++) {
        for (int j = 0; j < (int)clubes[c].jugadores.size(); j++) {
            if (clubes[c].jugadores[j]->getId() == idJugador) {
                return c;
            }
        }
    }
    return -1;
}

void SimuladorMercado::actualizarValoresMercado() {
    for (int c = 0; c < (int)clubes.size(); c++) {
        for (int j = 0; j < (int)clubes[c].jugadores.size(); j++) {
            int valorActual = clubes[c].jugadores[j]->getValorMercado();
            int variacion = -5 + rand() % (5 - (-5) + 1);
            int nuevoValor = valorActual + (valorActual * variacion / 100);

            if (nuevoValor < 5) {
                nuevoValor = 5;
            }

            clubes[c].jugadores[j]->setValorMercado(nuevoValor);
        }
    }
}

void SimuladorMercado::avanzarDia() {
    for (int i = 0; i < (int)ofertas.size(); i++) {
        if (ofertas[i].estado != "Pendiente") {
            continue;
        }

        Jugador* jugador = ofertas[i].jugador;
        int valorActual = jugador->getValorMercado();
        int umbral = valorActual + (valorActual * 10 / 100);

        if (ofertas[i].monto < umbral) {
            ofertas[i].estado = "Rechazada";
            cout << "Oferta por " << jugador->getNombre() << " rechazada: monto insuficiente (menor al 110%)." << endl;
            continue;
        }

        int clubComprador = ofertas[i].clubComprador;
        int clubVendedor = ofertas[i].clubVendedor;

        // Contar jugadores del mismo tipo en el club vendedor
        int mismaPosicion = 0;
        for (int j = 0; j < (int)clubes[clubVendedor].jugadores.size(); j++) {
            if (clubes[clubVendedor].jugadores[j]->getTipo() == jugador->getTipo()) {
                mismaPosicion++;
            }
        }

        if (mismaPosicion <= 1) {
            ofertas[i].estado = "Rechazada";
            cout << "Oferta por " << jugador->getNombre() << " rechazada: el club vendedor se quedaria sin jugadores en esa posicion." << endl;
            continue;
        }

        if (clubes[clubComprador].presupuesto < ofertas[i].monto) {
            ofertas[i].estado = "Rechazada";
            cout << "Oferta por " << jugador->getNombre() << " rechazada: presupuesto insuficiente." << endl;
            continue;
        }

        // Si todo es valido se acepta la transferencia
        clubes[clubComprador].presupuesto -= ofertas[i].monto;
        clubes[clubVendedor].presupuesto += ofertas[i].monto;

        // Quitar el jugador del vector del club vendedor
        for (int j = 0; j < (int)clubes[clubVendedor].jugadores.size(); j++) {
            if (clubes[clubVendedor].jugadores[j] == jugador) {
                clubes[clubVendedor].jugadores.erase(clubes[clubVendedor].jugadores.begin() + j);
                break;
            }
        }

        // Agregarlo al club comprador
        clubes[clubComprador].jugadores.push_back(jugador);
        jugador->setClubActual(clubes[clubComprador].nombre);

        ofertas[i].estado = "Aceptada";

        // Registrar la transferencia en el historial
        Transferencia t;
        t.dia = diaActual;
        t.jugador = jugador;
        t.origen = clubVendedor;
        t.destino = clubComprador;
        t.montoPagado = ofertas[i].monto;
        historial.push_back(t);

        cout << "Oferta aceptada: " << jugador->getNombre() << " se transfiere por " << ofertas[i].monto << " millones." << endl;
    }

    actualizarValoresMercado();
    diaActual++;

    cout << "\n--- Avanzando al dia " << diaActual << " de " << diasTotales << " ---" << endl;
}

void SimuladorMercado::revisarOfertasRecibidas() {
    if (clubes[clubUsuario].jugadores.empty()) {
        cout << "Tu club no tiene jugadores disponibles para recibir ofertas." << endl;
        return;
    }

    // Elegir un jugador aleatorio del club del usuario
    int indiceJugador = rand() % clubes[clubUsuario].jugadores.size();
    Jugador* jugador = clubes[clubUsuario].jugadores[indiceJugador];

    // Elegir un club rival aleatorio (distinto al del usuario)
    int clubRival = clubUsuario;
    while (clubRival == clubUsuario) {
        clubRival = rand() % clubes.size();
    }

    // Generar monto entre 90% y 130% del valor actual
    int valorActual = jugador->getValorMercado();
    int minimo = valorActual * 90 / 100;
    int maximo = valorActual * 130 / 100;
    int monto = minimo + rand() % (maximo - minimo + 1);

    cout << "\nOferta recibida por " << jugador->getNombre()
        << " (" << jugador->getTipo() << ") de " << clubes[clubRival].nombre
        << " por " << monto << " millones." << endl;
    cout << "Deseas aceptar? (1 = Si, 0 = No): ";

    int respuesta;
    cin >> respuesta;
    while (cin.fail() || (respuesta != 0 && respuesta != 1)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Ingresa 1 (Si) o 0 (No): ";
        cin >> respuesta;
    }

    if (respuesta == 0) {
        cout << "Oferta rechazada." << endl;
        return;
    }

    // Validar que el club del usuario no se quede sin jugadores de esa posicion
    int mismaPosicion = 0;
    for (int j = 0; j < (int)clubes[clubUsuario].jugadores.size(); j++) {
        if (clubes[clubUsuario].jugadores[j]->getTipo() == jugador->getTipo()) {
            mismaPosicion++;
        }
    }
    if (mismaPosicion <= 1) {
        cout << "No puedes aceptar: te quedarias sin jugadores en esa posicion." << endl;
        return;
    }

    // Actualizar presupuestos
    clubes[clubRival].presupuesto -= monto;
    clubes[clubUsuario].presupuesto += monto;

    // Mover el puntero del jugador 
    clubes[clubUsuario].jugadores.erase(clubes[clubUsuario].jugadores.begin() + indiceJugador);
    clubes[clubRival].jugadores.push_back(jugador);
    jugador->setClubActual(clubes[clubRival].nombre);

    // Registrar en el historial la transferencia
    Transferencia t;
    t.dia = diaActual;
    t.jugador = jugador;
    t.origen = clubUsuario;
    t.destino = clubRival;
    t.montoPagado = monto;
    historial.push_back(t);

    cout << "Oferta aceptada. " << jugador->getNombre() << " se transfiere a " << clubes[clubRival].nombre << "." << endl;
}

void SimuladorMercado::verHistorial() {
    if (historial.empty()) {
        cout << "\nAun no se han realizado transferencias." << endl;
        return;
    }

    cout << "\n--- Historial de Transferencias ---" << endl;
    for (int i = 0; i < (int)historial.size(); i++) {
        cout << "Dia " << historial[i].dia
            << " | Jugador: " << historial[i].jugador->getNombre()
            << " | De: " << clubes[historial[i].origen].nombre
            << " | A: " << clubes[historial[i].destino].nombre
            << " | Monto: " << historial[i].montoPagado << "M" << endl;
    }
}

void SimuladorMercado::generarReporteFinal() {
    cout << "\n========== REPORTE FINAL ==========" << endl;
    cout << "Club administrado: " << clubes[clubUsuario].nombre << endl;
    cout << "Presupuesto final disponible: " << clubes[clubUsuario].presupuesto << "M" << endl;

    cout << "\nPlantilla final:" << endl;
    for (int j = 0; j < (int)clubes[clubUsuario].jugadores.size(); j++) {
        cout << " - " << clubes[clubUsuario].jugadores[j]->mostrarDescripcion() << endl;
    }

    int totalGastado = 0, totalRecibido = 0;
    int compras = 0, ventas = 0;

    for (int i = 0; i < (int)historial.size(); i++) {
        if (historial[i].destino == clubUsuario) {
            totalGastado += historial[i].montoPagado;
            compras++;
        }
        if (historial[i].origen == clubUsuario) {
            totalRecibido += historial[i].montoPagado;
            ventas++;
        }
    }

    cout << "\nTotal gastado en compras: " << totalGastado << "M" << endl;
    cout << "Total recibido en ventas: " << totalRecibido << "M" << endl;
    cout << "Jugadores comprados: " << compras << endl;
    cout << "Jugadores vendidos: " << ventas << endl;

    int aceptadas = 0, rechazadas = 0;
    for (int i = 0; i < (int)ofertas.size(); i++) {
        if (ofertas[i].estado == "Aceptada") aceptadas++;
        if (ofertas[i].estado == "Rechazada") rechazadas++;
    }
    cout << "Ofertas aceptadas: " << aceptadas << endl;
    cout << "Ofertas rechazadas: " << rechazadas << endl;

    verHistorial();
    cout << "====================================" << endl;
}

SimuladorMercado::~SimuladorMercado() {
    for (int c = 0; c < (int)clubes.size(); c++) {
        for (int j = 0; j < (int)clubes[c].jugadores.size(); j++) {
            delete clubes[c].jugadores[j];
        }
    }
}