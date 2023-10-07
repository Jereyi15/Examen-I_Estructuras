#pragma once
#include "Conjuntocartas.h"
#include "Mazo.h"
class jugadorBase {

public:

	jugadorBase(string);
	virtual ~jugadorBase();
	virtual bool hacerApuesta(int) = 0;
	virtual Carta* solicitarCarta(Mazo*) = 0;//opcion de pedir una carta durante el juego
	virtual bool pasarTurno(jugadorBase*) = 0;//opcion para pasar el turno durante el juego
	virtual string getNombre() = 0;
	virtual string toString() = 0;
protected:
	string nombre;

};

