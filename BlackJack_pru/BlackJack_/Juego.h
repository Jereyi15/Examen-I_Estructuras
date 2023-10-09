#pragma once
#include "ConjuntoJugadores.h"
#include "ConjuntoCartas.h"
#include "menusJuego.h"
#include "Crupier.h"
#include <iostream>
using namespace std;

class Juego
{
public:
	Juego();
	void jugadoresM();
	void cartasM();
	void instruccionesYreglas();
	void juego();
	void repartirCartas(ConjuntoCartas);
	void opcionesJugador();
	
	void apuestas();
	void iniciarAJugar(); 
	void verificarGanadores();


	void resetJugadores();
	bool derrota(Jugador*);//nuevo

	void juegaCasa();

private:
	ConjuntoJugadores cjnJugadores;
	ConjuntoCartas cartas;
	Crupier* crupier;
	int apuestaRonda;
	list<Jugador>::iterator it;
};

