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
	s << "-------------------------------" << endl;
	s << "Crupier: " << nombre << endl;
	s << "-------------------------------" << endl;
	return s.str();
}

void Crupier::solicitarCard(ConjuntoCartas* cards)
{
	Carta carta = cards->tomarCarta();
	mazo->agregarCarta(carta);
	cout << "Carta tomada: " << carta.toString() << endl;
}


/*Carta* Crupier::darVuelta()
{aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	return nullptr;
}*/
