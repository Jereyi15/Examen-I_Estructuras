#pragma once
#include <string>
#include "jugadorBase.h"
#include "Mazo.h"
using namespace std;

class Jugador : public jugadorBase
{
public:
	Jugador(string);
	virtual ~Jugador();
	virtual void ganador(int);
	virtual bool hacerApuesta(int);
	virtual string getNombre();
	virtual string toString();
	virtual string toStringMazo();
	virtual void solicitarCard(ConjuntoCartas*);
	virtual bool pasarTurno(jugadorBase*);

private:
	string _nombre;
	int monedas;

};

