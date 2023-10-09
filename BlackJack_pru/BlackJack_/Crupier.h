#pragma once
#include "jugadorBase.h"
#include "Jugador.h"
using namespace std;

class Crupier : public jugadorBase
{
public:
	Crupier(string);
	virtual ~Crupier();
	virtual string getNombre();
	virtual bool pasarTurno(jugadorBase*);
	virtual string toString();
	virtual string toStringMazo();
	virtual void solicitarCard(ConjuntoCartas*);
	virtual bool mas21(Jugador*);//nuevo
	virtual Mazo* getCartasP();//nuevo
	virtual void resetCards();

private:
	
};

