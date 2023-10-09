#pragma once
#include "Jugador.h"
#include <list>

class ConjuntoJugadores
{
public:
	ConjuntoJugadores();
	virtual ~ConjuntoJugadores();
	void agregar(Jugador*);
	void eliminarJugador(Jugador*); //Una vez el jugador se queda sin dinero se eliminara de la lista de jugadores
	Jugador* recuperar(string);
	string toString();
	string toStringMazo();
	int cantidadJugadores();
	list<Jugador>::iterator getIterator();
	list<Jugador>* getJugadores();

	void repartirCartas(ConjuntoCartas);
	


private:
	list<Jugador> jugadores;
	list<Jugador>::iterator it;
};

