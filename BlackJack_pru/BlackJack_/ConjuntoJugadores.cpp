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

bool ConjuntoJugadores::contadorJugadores()
{
    int j = jugadores.size();
    if (j == 7) {
        return true;
    }
    return false;
}
int ConjuntoJugadores::cantidadJugadores() {
    return jugadores.size();
}