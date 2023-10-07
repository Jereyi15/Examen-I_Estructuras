#pragma once
#include "ConjuntoJugadores.h"
#include "ConjuntoCartas.h"
#include "menusJuego.h"
#include <iostream>
using namespace std;

class Juego
{
public:
	Juego();
	void jugadoresM();
	void cartasM();
private:
	ConjuntoJugadores cjnJugadores;
	ConjuntoCartas cartas;
};

