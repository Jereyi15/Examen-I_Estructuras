#include "ConjuntoJugadores.h"
#include <sstream>
using std::stringstream;

ConjuntoJugadores::ConjuntoJugadores()
{
}

ConjuntoJugadores::~ConjuntoJugadores()
{
}

void ConjuntoJugadores::agregar(Jugador* _jugador)
{
    jugadores.push_back(*_jugador);
}

Jugador* ConjuntoJugadores::recuperar(string _nombre)
{
    for (it = jugadores.begin(); it != jugadores.end(); it++) {
        if (it->getNombre() == _nombre) {
            return &*it; // Devuelve el puntero al jugador encontrado
        }
    }
    return nullptr; // Si no se encuentra el jugador, devuelve un puntero nulo
}
void ConjuntoJugadores::eliminarJugador(Jugador* jugador) {
    for (it = jugadores.begin(); it != jugadores.end(); ++it) {
        if (&(*it) == jugador) {
            jugadores.erase(it);
            return;
        }
    }
}

string ConjuntoJugadores::toString()
{
    stringstream s;
    for (it = jugadores.begin(); it != jugadores.end(); it++) {
        s << it->toString() << "\n";
    }
    return s.str();
}


string ConjuntoJugadores::toStringMazo()
{
    stringstream s;
    for (it = jugadores.begin(); it != jugadores.end(); it++) {
        s << it->toStringMazo() << "\n";
    }
    return s.str();
}

int ConjuntoJugadores::cantidadJugadores() {
    return jugadores.size();
}

list<Jugador>::iterator ConjuntoJugadores::getIterator()
{
    return it;
}

list<Jugador>* ConjuntoJugadores::getJugadores()
{
    return &jugadores;
}

void ConjuntoJugadores::repartirCartas(ConjuntoCartas cartas)
{
    for (it = jugadores.begin(); it != jugadores.end(); it++) {
        if (it->getCanApuesta() != 0) {
            it->solicitarCard(&cartas);
            it->solicitarCard(&cartas);
        }
    }
}



