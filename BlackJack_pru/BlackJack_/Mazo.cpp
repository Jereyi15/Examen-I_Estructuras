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
		int contadorAces = 0;
		stack<Carta> copiaPila = cartasJugador; // Hacemos una copia de la pila

		while (!copiaPila.empty()) {
			string valor = copiaPila.top().getValor();
			if (valor == "A") {
				if (contadorAces == 0) {
					total += 11;
				}
				else {
					total += 1;
				}
				copiaPila.pop();
			}
			else if (valor == "J" || valor == "Q" || valor == "K") {
				copiaPila.pop();
				total += 10;
			}
			else {
				int num = std::stoi(valor);
				copiaPila.pop();
				total += num;
			}
		}
		
		if (contadorAces != 0) {
			contadorAces = 0;
		}
		return total;
}
