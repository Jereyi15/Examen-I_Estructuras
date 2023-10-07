#include "menusJuego.h"

menusJuego::~menusJuego() {

}

int menusJuego::mainMenu() {
	int opt = 0;
	char simbolo1 = 5;
	char simbolo2 = 3;
	char simbolo3 = 6;
	char simbolo4 = 4;

	cout << "                           ****************************" << endl;
	cout << "                         "<< simbolo1 << "  "  << simbolo2 << "  "  << simbolo3 << "  "  << simbolo4 << "  BlackJack  " << simbolo1 <<  "  " << simbolo2 << "  " << simbolo3 << "  " << simbolo4 << endl;
	cout << "                           ****************************" << endl << endl << endl;
	cout << "*******************" << endl;
	cout << "1- Juego" << endl;
	cout << "2- Jugadores" << endl;
	cout << "3- Cartas" << endl;
	cout << "4- Salir" << endl;
	cout << "*******************" << endl;
	cin >> opt;

	system("cls");
	return opt;

}

void menusJuego::agregarJugadores() {

	cout << "------Jugadores-------" << endl << endl;
	cout << "*Ingrese su nombre* " << endl << endl;

}


int menusJuego::jugadores()
{
	int opt = 0;

	cout << "*******************" << endl;
	cout << "1- Agregar Jugador" << endl;
	cout << "2- Ver jugadores" << endl;
	cout << "3- Volver" << endl;
	cout << "*******************" << endl;
	cin >> opt;

	system("cls");
	return opt;
}

void menusJuego::porDefecto()
{
	cout << "-----Error: Codigo no valido" << endl << endl;
	system("cls");
}

int menusJuego::menuCartas()
{
	int opt = 0;

	cout << "*******************" << endl;
	cout << "1- Ver cartas" << endl;
	cout << "2- Barajar" << endl;
	cout << "3- Ordenar" << endl;
	cout << "4- Salir" << endl;
	cout << "*******************" << endl;
	cin >> opt;

	system("cls");
	return opt;

}

void menusJuego::instrucciones() {
	char sim1 = 5;
	char sim2 = 3;
	char sim3 = 6;
	char sim4 = 4;
	cout <<  "                   *******************" << endl<< endl;
	cout  << "             Reglas e instrucciones del juego" << endl;
	cout << " Al inicio de cada ronda cada jugador debera de hacer sus apuestas." << endl;
	cout << " La apuesta minima por turno es de 50 monedas. " << endl;
	cout << " Cada jugador iniciara con 500 monedas a su disposicion." << endl;
	cout << " Se les repartira dos cartas descubiertas a cada jugador y a el crupier" << endl;
	cout << " Una vez repartidas las dos cartas cada jugador puede decidir si plantarse, o pedir mas cartas." << endl << endl;
	cout << " Si el jugador obtiene el mismo valor que el crupier, recupera su apuesta." << endl;
	cout << " Si el jugador saca un Black Jack, o supera al crupier su pago sera doble. " << endl;
	cout << " De lo contrario el jugador pierde su apuesta y la ronda." << endl;
	cout << endl << endl;
	cout << "                      ¡Buena suerte!" << endl;
	cout << "                   *******************" << endl;
}