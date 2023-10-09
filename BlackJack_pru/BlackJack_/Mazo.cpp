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

void Mazo::sacarCartas()
{
	while (!cartasJugador.empty()) {
		cartasJugador.pop();
	}
}

string Mazo::mostrarCartas()
{
	stringstream r;
	stack<Carta> copiaPila = cartasJugador; // Hacemos una copia de la pila
	
	while (!copiaPila.empty()) {
		r << copiaPila.top().toString();
		copiaPila.pop();
	}

	return r.str();
}

int Mazo::puntajeTotal()
{
	int total = 0;
	stack<Carta> copiaPila = cartasJugador; // Hacemos una copia de la pila

	while (!copiaPila.empty()) {
		total += stoi(copiaPila.top().getValor());
		copiaPila.pop();
	}

	return total;
}
