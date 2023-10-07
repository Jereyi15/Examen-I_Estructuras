#include "Jugador.h"
#include <sstream>
using std::stringstream;

Jugador::Jugador(string _nombre) : nombre(_nombre), cantMonedas(500)
{
}

void Jugador::ganador(int _cant)
{
    cantMonedas = cantMonedas + _cant;
}

bool Jugador::hacerApuesta(int _cant)
{
    if (_cant <= 0) {
        throw std::invalid_argument("La apuesta debe ser mayor que cero.");
        return false;
    }
    if (cantMonedas >= _cant) {
        cantMonedas -= _cant;
        return true;
    }
    else {
        throw std::invalid_argument("No tienes dinero suficiente para seguir apostando.");
        return false;
    }
}

string Jugador::getNombre()
{
    return nombre;
}

string Jugador::toString()
{
    stringstream s;
    s << " Nombre: " << nombre << "\n";
    s << " Cantidad de monedas dsiponibles: " << cantMonedas << "\n";
    return s.str();
}
