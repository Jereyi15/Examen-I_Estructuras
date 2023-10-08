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


/*Carta* Crupier::darVuelta()
{
	return nullptr;
}*/
