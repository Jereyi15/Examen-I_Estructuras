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
	virtual int getCanApuesta();
	virtual void resetCanApuesta();
	virtual void resetCards();
	virtual Mazo* getCartasP();//nuevo
	virtual bool mas21(jugadorBase*);//nuevo
	virtual int getMonedas();

private:
	string _nombre;
	int monedas;
	int canApuesta; //por si gana conocer la cantidad exacta que aposto

};

