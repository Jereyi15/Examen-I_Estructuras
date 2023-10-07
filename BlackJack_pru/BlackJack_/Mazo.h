#pragma once
#include "Carta.h"
#include <stack>

class Mazo
{
public:
	Mazo();
	~Mazo();
	void agregarCarta(Carta*);
	void sacarCarta();
	string mostrarCartas();
	int puntajeTotal();

private:
	stack<Carta> cartasJugador;
};

