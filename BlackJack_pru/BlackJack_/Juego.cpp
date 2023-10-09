#include "Juego.h"
#include <sstream>
using std::stringstream;

Jugador* player;
menusJuego* menu = new menusJuego();

Juego::Juego() : crupier(new Crupier("Crupier mesa 1")), apuestaRonda(0)
{
    int option = 0;

    cartas.crearBaraja();


    do {
        system("cls");
        option = menusJuego::mainMenu();

        system("cls");

        switch (option) {
            case 1: {
                if (cjnJugadores.cantidadJugadores() == 0) {
                    cout << "Antes de comenzar el juego debe crear un jugador!" << endl;
                    system("pause");
                    break;
                }
                else {
                    instruccionesYreglas();
                    system("pause");
                    system("cls");

                    juego();
                    system("pause");
                }
                break;
            }
            case 2:
                jugadoresM();
                break;

            case 3: {
                cartasM();
                break;
            }

        }
    } while (option != 4);

}

void Juego::jugadoresM()
{
    int opt1 = 0, b=1;
    string nombre = " ";
    int cantJugadores = 0;

    do {
        opt1 = menusJuego::jugadores();

        system("cls");

        switch (opt1) {
        case 1:

           // menu->agregarJugadores();
           
            cout << "Cuantos jugadores desea agregar?\n";
            cin >> cantJugadores;
            if (cantJugadores + cjnJugadores.cantidadJugadores() <= 7) {
                cin.ignore(); // Limpia el b�fer de entrada
                for(int i = 0; i < cantJugadores; i++){ 
                    cout << "Nombre del jugador " << b << ": ";
                    
                    getline(cin, nombre);
                    
                    cjnJugadores.agregar(new Jugador(nombre));

                    b++;
                    cout << "--------------------------------\n";
                }
            }
            else {
                cout << "El limite de jugadores por partida es 7.\n";
            }

            system("pause");
            break;

        case 2:
            system("cls");
            cout << cjnJugadores.toString() << endl;
            system("pause");
            break;
        case 3:
            //Salir del menu de jugadores
            break;
        default:
            menusJuego::porDefecto();
            cout << "-----Error: Codigo no valido" << endl << endl;
            system("pause");
            system("cls");
            break;

        }
        system("cls");
    } while (opt1 != 3);
}

void Juego::cartasM()
{

    int opt2 = 0;
    do {
        opt2 = menusJuego::menuCartas();

        switch (opt2) {
        case 1:
            cout << cartas.toString();
            system("pause");
            break;

        case 2:
            system("cls");
            cartas.barajarCartas();
            cout << "Baraja recien barajada con exito." << endl;
            system("pause");
            break;

        case 3:
            system("cls");
            cartas.ordenarCartas();
            cout << "Baraja ordenada con exito." << endl;
            system("pause");
            break;
        case 4: 
            //Salir del menu de cartas
            break;
        default:
            menusJuego::porDefecto();
            cout << "-----Error: Codigo no valido" << endl << endl;
            system("pause");
            system("cls");
            break;

        }
        system("cls");
    } while (opt2 != 4);

}

void Juego::instruccionesYreglas() {
    menusJuego::instrucciones();
}

void Juego::juego()
{
    cout << " --------------BlackJack-------------- \n\n";
    cout << " Crupier: " << crupier->getNombre() << "\n" << "--------------------\n";
    cout << " Participantes: \n" << cjnJugadores.toString() << "--------------------\n";
    cout << " Empezamos el juego, mostrandole a los participantes que la baraja esta completa y ordenada.\n\n\n";
    cartas.ordenarCartas();
    cout << cartas.toString();

    system("pause");
    system("cls");
    
    cout << "             *************************************\n\n";
    cout << "Ahora, participantes, hagan sus apuestas antes de iniciar la ronda.\n\n";
    cout << "             *************************************\n\n";

    apuestas();

    cout << "           *************************************\n\n";
    cout << "Ahora barajamos y les damos a todos los jugadores 2 cartas.\n\n";
    cartas.barajarCartas();
    repartirCartas(cartas);
    crupier->solicitarCard(&cartas);
    iniciarAJugar();
    juegaCasa();
    cout << verificarGanadores();
    resetJugadores();

}

void Juego::repartirCartas(ConjuntoCartas cartas)
{
    cjnJugadores.repartirCartas(cartas);
}

void Juego::opcionesJugador()
{
    apuestas();
}

void Juego::apuestas() {
    list<Jugador> *jugadores = cjnJugadores.getJugadores();
    list<Jugador>::iterator it = cjnJugadores.getIterator();
    int opc = 0;
    int apuesta = 0;

    for (it = jugadores->begin(); it != jugadores->end(); it++) {
        cout << "--------------------------\n";
        cout << "APUESTAS A PARTIR DE 50 MONEDAS.\n";
        cout << "--------------------------\n\n";

        cout << "Jugador: " << it->toString() << endl;
        cout << "Desea realizar apuesta para esta ronda? 1. Si / 2. No: ";
        cin >> opc;

        if (opc == 1) {
            cout << "Cuanto desea apostar? ";
            cin >> apuesta;
            if (apuesta >= 50) {
                if (!it->hacerApuesta(apuesta)) {
                    cout << "\n Apuesta no valida, no cuenta con fondos suficientes \n";
                }
            }
            else {
                cout << "\n Apuesta no valida, debe ser mayor a 50 monedas \n";
            }
        }
        else if (opc == 2) {
            it->resetCards();
        }
        else {
            throw "Opcion invalida";
        }
        system("pause");
        system("cls");
    }
}
void Juego::iniciarAJugar()
{
    list<Jugador> jugadores = *cjnJugadores.getJugadores();
    list<Jugador>::iterator it = cjnJugadores.getIterator();
    int opc;
    for (it = jugadores.begin(); it != jugadores.end(); it++) {
        if (it->getCanApuesta() != 0) {
            do {
                system("cls");
                cout << "           *************************************\n\n";
                cout << cjnJugadores.toStringMazo() << "\n" << crupier->toStringMazo() << endl;
                cout << "           *************************************\n\n";
                cout << "Jugador: " << it->toString() << endl;
                cout << "Desea pedir otra carta? 1. Si / 2. No: ";
                cin >> opc;
                if (opc == 1) {
                    it->solicitarCard(&cartas);
                }
            } while (opc != 2);
        }
    }
}

string Juego::verificarGanadores()
{
    stringstream s;
    list<Jugador> jugadores = *cjnJugadores.getJugadores();
    list<Jugador>::iterator it = cjnJugadores.getIterator();
    system("cls");
    cout << "           *************************************\n\n";
    cout << cjnJugadores.toStringMazo() << "\n" << crupier->toStringMazo() << endl;
    cout << "           *************************************\n\n";
    s << "           *************************************\n\n";
    s << "Ganadores: " << endl;
    for (it = jugadores.begin(); it != jugadores.end(); it++) {
        if (!derrota(&*it)) {
            it->ganador(it->getCanApuesta() * 2);
            s << it->toString() << "\n";
        }
    }
    s << "           *************************************\n\n";
    return s.str();
}

void Juego::resetJugadores()
{
    list<Jugador> jugadores = *cjnJugadores.getJugadores();
    list<Jugador>::iterator it = cjnJugadores.getIterator();
    for (it = jugadores.begin(); it != jugadores.end(); it++) {
        it->resetCanApuesta();
        it->resetCards();
    }
    crupier->resetCards();
}

bool Juego::derrota(Jugador* sePasa)//nuevo
{
    if (crupier->mas21(sePasa) == true ) {
        return true;
    }
    return false;
}

void Juego::juegaCasa()
{
    bool bandera = true;
    int ganandoACrupier = 0;
    int cantidadJugadores = 0;
    list<Jugador> jugadores = *cjnJugadores.getJugadores();
    list<Jugador>::iterator it = cjnJugadores.getIterator();
    do
    {
        for (it = jugadores.begin(); it != jugadores.end(); it++) {
            cantidadJugadores++;
            if (!derrota(&*it)) ganandoACrupier++;
        }
        if ((cantidadJugadores / 2) < ganandoACrupier) crupier->solicitarCard(&cartas);
        else bandera = false;
    } while (bandera);
}
