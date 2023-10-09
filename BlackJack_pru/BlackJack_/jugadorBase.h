#pragma once
#include "Conjuntocartas.h"
#include "Mazo.h"
#include <iostream>
using namespace std;

class jugadorBase {

public:

	jugadorBase(string, Mazo*);
	virtual ~jugadorBase();

	virtual void solicitarCard(ConjuntoCartas*) = 0;//opcion de pedir una carta durante el juego
	virtual bool pasarTurno(jugadorBase*) = 0;//opcion para pasar el turno durante el juego
	virtual Mazo* getCartasP() = 0;//nuevo
	virtual string getNombre();//nuevo
	virtual string toString();
	virtual void resetCards(); // quita las cartas que anteriormente tenia
protected:
	string nombre;
	Mazo* mazo;

};

