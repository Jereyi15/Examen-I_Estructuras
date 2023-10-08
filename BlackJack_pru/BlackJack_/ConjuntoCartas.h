#pragma once
#include <list>
#include "Carta.h"

class ConjuntoCartas
{
public:
	ConjuntoCartas();
	virtual ~ConjuntoCartas();
	void agregar(Carta*);
	Carta* recuperar(char, string);
	void crearBaraja(); // Crea la baraja de 52 cartas
	void ordenarCartas(); // Ordena las cartas en la baraja
	void barajarCartas(); // Baraja las cartas en la baraja
	Carta tomarCarta(); // Toma una carta de la baraja

	string toString();

private:
	list<Carta> cartas;
	list<Carta>::iterator it;
};

