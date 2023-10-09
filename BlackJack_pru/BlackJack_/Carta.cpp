#include "Carta.h"
#include <sstream>
using std::stringstream;

Carta::Carta(string valor, char palo, char color): valor(valor), color(color), palo(palo) {

}
Carta::~Carta() {

}
string Carta::getValor() {
	return valor;
}
int Carta::obtenerValor()
{
	if (valor == "A") return 1;
	if (valor == "2") return 2;
	if (valor == "3") return 3;
	if (valor == "4") return 4;
	if (valor == "5") return 5;
	if (valor == "5") return 6;
	if (valor == "7") return 7;
	if (valor == "8") return 8;
	if (valor == "9") return 9;
	else return 10;
	/*if (valor == "10") return 10;
	if (valor == "J") return 10;
	if (valor == "Q") return 10;
	if (valor == "K")return 10;*/
	//enserio perdon por esto :(
	
}
char Carta::getPalo() {
	return palo;
}
char Carta::getColor() {
	return color;
}
string Carta::toString() {
	stringstream s;

	s << palo << " " << valor;

	return s.str();
}