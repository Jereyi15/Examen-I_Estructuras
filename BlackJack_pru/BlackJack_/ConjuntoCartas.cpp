#include "ConjuntoCartas.h"
#include "Carta.h"
#include <sstream>
#include <algorithm> //Librerias utilizada para barajas las cartas de manera aleatoria
#include <random> //Librerias utilizada para barajas las cartas de manera aleatoria
using std::stringstream;

ConjuntoCartas::ConjuntoCartas(){

}
ConjuntoCartas::~ConjuntoCartas() {

}
void ConjuntoCartas::agregar(Carta* cartaNueva) {
	cartas.push_back(*cartaNueva);
}
Carta* ConjuntoCartas::recuperar(char palo, string valor) {
    for (it = cartas.begin(); it != cartas.end(); it++) {
        if (it->getPalo() == palo && it->getValor() == valor) {
            return &*it; // Devuelve el puntero a la carta encontrada
        }
    }
    return nullptr; 
}

void ConjuntoCartas::crearBaraja() {
    const string valores[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const char palosRojos[] = { 4, 3 }; 
    const char palosNegros[] = { 5, 6,};
  
    for (const string& valor : valores) {
            for (const char& palo : palosRojos) {
                // Crea una carta y la agrega a la baraja
                Carta carta(valor, palo, 'R');
                cartas.push_back(carta);
            }
    }
    for (const string& valor : valores) {
        for (const char& palo : palosNegros) {
            // Crea una carta y la agrega a la baraja
            Carta carta(valor, palo, 'N');
            cartas.push_back(carta);
        }
    }
   
}
//Compara las cartas por valor, iniciando de A hasta K
void ConjuntoCartas::ordenarCartas() {
    cartas.sort([](Carta& a, Carta& b) {
        string valores = "A23456789XJQK"; 
        return valores.find(a.getValor()) < valores.find(b.getValor());
        });
}
void ConjuntoCartas::barajarCartas() {
   //Se debe hacer
}
Carta ConjuntoCartas::tomarCarta() {
    if (!cartas.empty()) {
        //Toma la primera carta de la baraja previamente barajada en la clase juego
        Carta cartaTomada = cartas.front();
        cartas.pop_front();
        return cartaTomada;
    }
}
string ConjuntoCartas::toString()
{
    stringstream s;
    for (it = cartas.begin(); it != cartas.end(); it++) {
        s << it->toString() << "  -  ";
    }
    return s.str();
}
