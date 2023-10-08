#include "Juego.h"

Jugador* player;
menusJuego* menu = new menusJuego();

Juego::Juego()
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
                //Aqu� comenzaria el juego

                system("pause");
                system("cls");
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

              Carta cartaTomada = cartas.tomarCarta();
              cout << "Tomada: " << cartaTomada.toString();

              system("pause");
              system("cls");


              if (cjnJugadores.recuperar("Pablo") != nullptr) {
                  player = cjnJugadores.recuperar("Pablo");

                  if (player->hacerApuesta(200)) {
                      cout << "Se realizo la apuesta \n";
                  }
                  else {
                      cout << "Esta pobre por que no le alcanzo para la apuesta \n";
                  }
              }
              cout << cjnJugadores.toString();
              system("pause");
        }
    } while (option != 4);

}

void Juego::jugadoresM()
{
    int opt1 = 0, b=1;
    string nombre;
    int cantJugadores = 0;

    do {
        opt1 = menusJuego::jugadores();

        system("cls");

        switch (opt1) {
        case 1:

            menu->agregarJugadores();

            cout << "Cuantos jugadores desea agregar?\n";
            cin >> cantJugadores;
            if (cantJugadores + cjnJugadores.cantidadJugadores() <= 7) {

                for(int i = 0; i < cantJugadores; i++){ 
                    cout << "Nombre del jugador " << b << ": ";
                    cin.ignore(); // Limpia el b�fer de entrada
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