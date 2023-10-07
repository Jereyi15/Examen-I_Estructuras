
#include "Juego.h"

Jugador* player;
menusJuego* menu = new menusJuego();

Juego::Juego()
{

    int option = 0;
principal:
    do {
        system("cls");
    //  option = menusJuego::mainMenu();

      cout << "                                  ****************************" << endl;
      cout << "                                  * * * *//BlackJack//* * * *" << endl;
      cout << "                                  ****************************" << endl << endl << endl;
      cout << "*******************" << endl;
      cout << "1-Juego" << endl;
      cout << "2-Jugadores" << endl;
      cout << "3-Cartas" << endl;
      cout << "4-salir" << endl;
      cout << "*******************" << endl;
      cin >> option;

      system("cls");

        switch (option) {
        case 1: {
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
    int opt1 = 0;
    string nombre;

    cjnJugadores.agregar(player = new Jugador("Felipe"));
    cjnJugadores.agregar(player = new Jugador("Jeremy"));
    cjnJugadores.agregar(player = new Jugador("Irina"));
    cjnJugadores.agregar(player = new Jugador("Gabriel"));
    cjnJugadores.agregar(player = new Jugador("Pablo"));

    do {
     //  opt1 = menusJuego::jugadores();

        cout << "*******************" << endl;
        cout << "1-Agregar Jugador" << endl;
        cout << "2-Ver jugadores" << endl;
        cout << "3-Volver" << endl;
        cout << "*******************" << endl;
        cin >> opt1;

        system("cls");

        switch (opt1) {
        case 1: 

           // menu->agregarJugadores();
            cout << "------Jugadores-------" << endl << endl;
            cout << "*Ingrese su nombre* " << endl << endl;

            for (int i = 0; i < 2; i++) {
                cout << "Nombre del jugador: " << i + 1 << "- ";
                cin >> nombre;
                cout << endl;
                cjnJugadores.agregar(player = new Jugador(nombre));
            }


            system("pause");
            break;

        case 2:
            system("cls");
            cout << cjnJugadores.toString() << endl;
            system("pause");
            break;

        default:
            //menusJuego::porDefecto();
            cout << "-----Error: Codigo no valido" << endl << endl;
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
      //  opt2 = menusJuego::menuCartas();

        cout << "*******************" << endl;
        cout << "1-Crear/ver cartas" << endl;
        cout << "2-Ver cartas" << endl;
        cout << "3-Barajar" << endl;
        cout << "4-Ordenar" << endl;
        cout << "5-salir" << endl;
        cout << "*******************" << endl;
        cin >> opt2;

        system("cls");

        switch (opt2) {
        case 1:
            system("cls");
            // Primero se mostraran las cartas de color rojo y luego las de color negro
            cout << "Baraja recien creada: " << endl;
            cartas.crearBaraja();
            break;

        case 2:
            cout << cartas.toString();
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Baraja recien barajada: " << endl;
            cartas.barajarCartas();
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "Baraja recien ordenada: " << endl;
            cartas.ordenarCartas();
            break;
        default:
           // menusJuego::porDefecto();
            cout << "-----Error: Codigo no valido" << endl << endl;
            system("cls");
            break;

        }
        system("cls");
    } while (opt2 != 5);

}
