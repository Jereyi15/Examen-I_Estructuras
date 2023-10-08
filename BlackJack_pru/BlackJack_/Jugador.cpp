#include "Jugador.h"
#include <sstream>
using std::stringstream;

Jugador::Jugador(string _nombre) : jugadorBase(_nombre, new Mazo()), monedas(500)
{
}

Jugador::~Jugador()
{
}

void Jugador::ganador(int _cant)
{
    monedas = monedas + _cant;
}

bool Jugador::hacerApuesta(int _cant)
{ //quité el invalid_argument porque me tiraba error al compilar
    if (_cant <= 50) {
        throw "La apuesta debe ser mayor que 50.";
        return false;
    }
    if (monedas >= _cant) {
        monedas -= _cant;
        return true;
    }
    else {
        throw "No tienes dinero suficiente para seguir apostando.";
        return false;
    }
}

string Jugador::getNombre()
{
    return _nombre;
}

string Jugador::toString()
{
    stringstream s;
    s << "Nombre: " << jugadorBase::getNombre() << "\n";
    s << " Cantidad de monedas disponibles: " << monedas << "\n";
    return s.str();
}
//son 2 toString porque a la hora de enseñar los jugadores cuando no tienen mazos, da un error
//asi que uno es para usarlo en el juego como tal y el otro en la opcion de enseñar jugadores
string Jugador::toStringMazo() {

    stringstream s;
    s << jugadorBase::toString() << "\n";
    s << " Cantidad de monedas disponibles: " << monedas << "\n";
    return s.str();

}

void Jugador::solicitarCard(ConjuntoCartas* cards)
{
    Carta carta = cards->tomarCarta();
    mazo->agregarCarta(carta);
    cout << "Carta tomada: " << carta.toString() << endl;

}

bool Jugador::pasarTurno(jugadorBase*)
{
    return false;
}
