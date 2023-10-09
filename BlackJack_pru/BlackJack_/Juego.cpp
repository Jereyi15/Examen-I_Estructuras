#include "Juego.h"

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
                cin.ignore(); // Limpia el búfer de entrada
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
    cout << " Participantes: " << cjnJugadores.toString() << "--------------------\n";
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
    cout << "           *************************************\n\n";
    cout << cjnJugadores.toStringMazo() << "\n" << crupier->toStringMazo()<<endl;



}

void Juego::repartirCartas(ConjuntoCartas cartas)
{
    cjnJugadores.repartirCartas(cartas);
}

void Juego::opcionesJugador()
{
    cjnJugadores.apuestas();
  
}

void Juego::apuestas() {
    apuestaRonda = cjnJugadores.apuestas();
}
/*void Juego::iniciarJuego()
{

    int opc;
    for (it = jugadores.begin(); it != jugadores.end(); it++) {
        cout << "Jugador: " << it->toString() << endl;
        do {
            cout << "Desea pedir una carta? 1. Si / 2. No: ";
            cin >> opc;
            it->solicitarCard();
        } while (opc != 2);

    }
}*/