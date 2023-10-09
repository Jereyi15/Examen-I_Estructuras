#include "Utiles.h"

#include <sstream>

Utiles::Utiles() {
}

Utiles::~Utiles() {
}

//Este método valida si la entrada es un entero
int Utiles::validarEntero() {
	int entero = 0;
	bool estado = false;
	while (estado == false) {
		if (!(cin >> entero)) {
			cout << "-------------------------------------";
			cout << "\nLa entrada debe ser un valor entero.\n";
			cout << "-------------------------------------";
			cin.clear();
			cout << "\nDigite nuevamente: ";
		}
		else {
			estado = true;
		}
		cin.ignore(1000, '\n');
	}
	return entero;
}

//Este método valida si la entrada es de un double
double Utiles::validarDecimal() {
	double entrada = 0.0;
	bool estado = false;
	while (estado == false) {
		if (!(cin >> entrada)) {
			cout << "---------------------------------------";
			cout << "\nLa entrada debe ser un valor numerico.\n";
			cout << "---------------------------------------";
			cin.clear();
			cout << "\nDigite nuevamente: ";
		}
		else {
			estado = true;
		}
		cin.ignore(1000, '\n');
	}
	return entrada;
}