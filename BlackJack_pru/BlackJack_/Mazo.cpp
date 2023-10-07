#include "Mazo.h"

Mazo::Mazo() : 
{
}

Mazo::~Mazo()
{
}

void Mazo::agregarCarta(Carta* c)
{
	cartasJugador.push(c);
}

void Mazo::sacarCarta()
{
}

string Mazo::mostrarCartas()
{
	return string();
}

int Mazo::puntajeTotal()
{
	return 0;
}
