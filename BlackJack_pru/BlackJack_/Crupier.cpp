#include "Crupier.h"
#include <sstream>


Crupier::Crupier(string nombre) : jugadorBase(nombre, new Mazo())
{
}

Crupier::~Crupier()
{
}

string Crupier::getNombre()
{
	return nombre;
}

bool Crupier::pasarTurno(jugadorBase* pasa)
{
	
	return true;
}

string Crupier::toString()
{
	stringstream s;
	
	s << "***Crupier: " << jugadorBase::getNombre() << endl;
	
	return s.str();
}

string Crupier::toStringMazo()
{
	stringstream s;

	s << "***Crupier: " << jugadorBase::toString() << endl;

	return s.str();
}

void Crupier::solicitarCard(ConjuntoCartas* cards)
{
	Carta carta = cards->tomarCarta();
	mazo->agregarCarta(carta);
	cout << "Carta tomada: " << carta.toString() << endl;
}

Mazo* Crupier::getCartasP()
{
	return mazo;
}

void Crupier::resetCards()
{
	jugadorBase::resetCards();
}


bool Crupier::mas21(Jugador* mano)//metodo que evalua si se pasa de 21 puntos
{
	if (mano->getCartasP()->puntajeTotal() < 22 && mano->getCartasP()->puntajeTotal() > mazo->puntajeTotal()) {
		return false;
	}
	else
		return false;
}

