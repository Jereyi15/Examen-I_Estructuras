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

void ConjuntoJugadores::repartirCartas(ConjuntoCartas cartas)
{
    for (it = jugadores.begin(); it != jugadores.end(); it++) {
        it->solicitarCard(&cartas);
        it->solicitarCard(&cartas);
    }
}

int ConjuntoJugadores::apuestas() {
    int total = 0;
    int opc = 0;
    int apuesta = 0;

    for (it = jugadores.begin(); it != jugadores.end(); it++) {
        cout << "--------------------------\n";
        cout << "APUESTAS A PARTIR DE 50 DOLARES.\n";
        cout << "--------------------------\n\n";

        cout << "Jugador: " << it->toString() << endl;
        cout << "Desea realizar apuesta para esta ronda? 1. Si / 2. No";
        cin >> opc;

        if (opc == 1) {
            cout << "Cuanto desea apostar? ";
            cin >> apuesta;
            it->hacerApuesta(apuesta);
        } //ese hacerApuesta, no lo hice y la verdad no lo entendí muy bien pido perdon
        else if (opc == 2) {
            //aqui hacer que pase de personaje y quitar al que no apuesta de la ronda
            //quitarle las cartas tambien
        }
        else {
            throw "Opcion invalida";
        }
        total += apuesta;
        system("cls");
    }
    return total;
    //hice que se retornara el total para poder tener el total de todas las apuestas en
    //el jeugo para la hora de pagar
}