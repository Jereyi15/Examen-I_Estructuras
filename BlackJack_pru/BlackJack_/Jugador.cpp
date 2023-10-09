#include "Jugador.h"
#include <sstream>
using std::stringstream;

Jugador::Jugador(string _nombre) : jugadorBase(_nombre, new Mazo()), monedas(500), canApuesta(0)
{
}

Jugador::~Jugador()
{
}

void Jugador::ganador(int _cant)
{
    monedas += _cant;
}

bool Jugador::hacerApuesta(int _cant)
{ //quit� el invalid_argument porque me tiraba error al compilar
    if (monedas >= _cant) {
        monedas -= _cant;
        canApuesta = _cant;
        return true;
    }
    else {
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
//son 2 toString porque a la hora de ense�ar los jugadores cuando no tienen mazos, da un error
//asi que uno es para usarlo en el juego como tal y el otro en la opcion de ense�ar jugadores
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

int Jugador::getCanApuesta()
{
    return canApuesta;
}

void Jugador::resetCanApuesta()
{
    canApuesta = 0;
}

void Jugador::resetCards()
{
    jugadorBase::resetCards();
}

Mazo* Jugador::getCartasP()
{
    return mazo;
}

bool Jugador::mas21(jugadorBase* mano)//metodo que evalua si se pasa de 21 puntos
{
    if (mano->getCartasP()->puntajeTotal() > 21) {
        return true;
    }
    return false;
}
