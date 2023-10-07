#pragma once
#include "jugadorBase.h"
using namespace std;

class Crupier : public jugadorBase
{
public:
	Crupier(string, int);
	virtual ~Crupier();
	virtual string getNombre();
	virtual bool pasarTurno(jugadorBase*);
	virtual string toString();
	virtual Carta solicitarCard(ConjuntoCartas);
	virtual bool hacerApuesta(int);
	//	Carta* darVuelta();
private:
	int cantMonedas;
};

