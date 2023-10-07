#pragma once
#include "ConjuntoJugadores.h"
#include "ConjuntoCartas.h"
#include <iostream>
using namespace std;

class Juego
{
public:
	Juego();
	
private:
	ConjuntoJugadores cjnJugadores;
	ConjuntoCartas cartas;
};

