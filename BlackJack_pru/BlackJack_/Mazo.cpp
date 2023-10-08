#include "Mazo.h"
#include <sstream>
using std::stringstream;

Mazo::Mazo() 
{
}

Mazo::~Mazo()
{
}

void Mazo::agregarCarta(Carta c)
{
	cartasJugador.push(c);
}

void Mazo::sacarCarta()
{
}

string Mazo::mostrarCartas()
{
	stringstream r;

	r << cartasJugador.top().toString() << endl;

	return r.str();
}

int Mazo::puntajeTotal()
{
	return 0;
}
