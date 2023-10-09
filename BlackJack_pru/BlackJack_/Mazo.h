#pragma once
#include "Carta.h"
#include <stack>

class Mazo
{
public:
	Mazo();
	~Mazo();
	void agregarCarta(Carta); //Agrega una carta al mazo del jugador
	void sacarCartas(); //Saca todas las cartas
	string mostrarCartas();
	int puntajeTotal();

private:
	stack<Carta> cartasJugador;
};

