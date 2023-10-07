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