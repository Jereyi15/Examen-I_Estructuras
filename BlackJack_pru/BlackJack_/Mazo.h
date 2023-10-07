#pragma once
#include "Carta.h"
#include <stack>

class Mazo
{
public:
	Mazo();
	~Mazo();
	void agregarCarta(Carta*); //Agrega una carta al mazo del jugador
	void sacarCarta(); //Saca una carta de la baraja
	string mostrarCartas();
	int puntajeTotal();

private:
	stack<Carta> cartasJugador;
};

