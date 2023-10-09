#include "Utiles.h"

#include <sstream>

Utiles::Utiles() {
}

Utiles::~Utiles() {
}

//Este m�todo valida si la opci�n es un entero
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