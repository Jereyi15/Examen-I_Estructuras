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
	bool contadorJugadores(); //Verifica que se haya alcanzado el limite de jugadores permitidos
	int cantidadJugadores();

	void repartirCartas(ConjuntoCartas);
	int apuestas();

private:
	list<Jugador> jugadores;
	list<Jugador>::iterator it;
};

