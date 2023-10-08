#pragma once
#include "jugadorBase.h"
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

	//	Carta* darVuelta();
private:
	
};

