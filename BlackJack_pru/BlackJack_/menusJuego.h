#pragma once
//clase solo para los menus
#include <iostream>
using namespace std;

class menusJuego
{
public:

	~menusJuego();
	static int mainMenu();
	void agregarJugadores();
	static int jugadores();
	static string porDefecto();
	static int menuCartas();
	static void instrucciones();
	
};
