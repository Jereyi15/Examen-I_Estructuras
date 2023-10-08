#include "Crupier.h"
#include <sstream>


Crupier::Crupier(string nombre, int monedas) : jugadorBase(nombre), cantMonedas(monedas)
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
	//Aqui hay que agregar el metodo para que la maquina no se pase de los puntos
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

Carta Crupier::solicitarCard(ConjuntoCartas cards)
{
	return cards.tomarCarta();
}

bool Crupier::hacerApuesta(int _cant)
{
	if (cantMonedas >= _cant) {
		cantMonedas = cantMonedas - _cant;
		return true;
	}
	else
		return false;
}

/*Carta* Crupier::darVuelta()
{aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	return nullptr;
}*/
