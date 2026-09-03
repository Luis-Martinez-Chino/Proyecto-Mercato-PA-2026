
// DatosIniciales contiene unicamente los datos crudos de los 30 jugadores iniciales.

#ifndef DATOS_INICIALES_H
#define DATOS_INICIALES_H

#include <string>

// Struct simple para representar una fila de la tabla de jugadores
struct DatoJugador {
    int id;
    std::string nombre;
    std::string posicion;   // "Portero", "Defensa", "Mediocampista" o "Delantero"
    std::string club;       // Nombre del club inicial
};

const int TOTAL_JUGADORES_INICIALES = 30;

// Arreglo fijo con los 30 jugadores.
const DatoJugador DATOS_JUGADORES[TOTAL_JUGADORES_INICIALES] = {
    // Real Madrid
    {1,  "Thibaut Courtois",     "Portero",       "Real Madrid"},
    {2,  "Eder Militao",         "Defensa",       "Real Madrid"},
    {3,  "Federico Valverde",    "Mediocampista", "Real Madrid"},
    {4,  "Kylian Mbappe",        "Delantero",     "Real Madrid"},
    {5,  "Jude Bellingham",      "Mediocampista", "Real Madrid"},

    // FC Barcelona
    {6,  "Joan Garcia",          "Portero",       "FC Barcelona"},
    {7,  "Jules Kounde",         "Defensa",       "FC Barcelona"},
    {8,  "Pedri",                "Mediocampista", "FC Barcelona"},
    {9,  "Robert Lewandowski",   "Delantero",     "FC Barcelona"},
    {10, "Lamine Yamal",         "Delantero",     "FC Barcelona"},

    // Manchester City
    {11, "Gianluigi Donnarumma", "Portero",       "Manchester City"},
    {12, "Ruben Dias",           "Defensa",       "Manchester City"},
    {13, "Rodri",                "Mediocampista", "Manchester City"},
    {14, "Erling Haaland",       "Delantero",     "Manchester City"},
    {15, "Phil Foden",           "Mediocampista", "Manchester City"},

    // Liverpool
    {16, "Alisson Becker",       "Portero",       "Liverpool"},
    {17, "Virgil van Dijk",      "Defensa",       "Liverpool"},
    {18, "Dominik Szoboszlai",   "Mediocampista", "Liverpool"},
    {19, "Alexander Isak",       "Delantero",     "Liverpool"},
    {20, "Mohamed Salah",        "Delantero",     "Liverpool"},

    // Bayern Munich
    {21, "Manuel Neuer",         "Portero",       "Bayern Munich"},
    {22, "Jonathan Tah",         "Defensa",       "Bayern Munich"},
    {23, "Joshua Kimmich",       "Mediocampista", "Bayern Munich"},
    {24, "Harry Kane",           "Delantero",     "Bayern Munich"},
    {25, "Michael Olise",        "Mediocampista", "Bayern Munich"},

    // Paris Saint-Germain
    {26, "Lucas Chevalier",      "Portero",       "Paris Saint-Germain"},
    {27, "Achraf Hakimi",        "Defensa",       "Paris Saint-Germain"},
    {28, "Vitinha",              "Mediocampista", "Paris Saint-Germain"},
    {29, "Ousmane Dembele",      "Delantero",     "Paris Saint-Germain"},
    {30, "Desire Doue",          "Delantero",     "Paris Saint-Germain"}
};

#endif