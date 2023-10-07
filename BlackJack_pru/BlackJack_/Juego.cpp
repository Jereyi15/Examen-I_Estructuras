
#include "Juego.h"

Jugador* player;
menusJuego* menu = new menusJuego();

Juego::Juego()
{

    int option = 0;
principal:
    do {
        system("cls");
     option = menusJuego::mainMenu();

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
      opt1 = menusJuego::jugadores();

        system("cls");

        switch (opt1) {
        case 1: 

           menu->agregarJugadores();


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
            menusJuego::porDefecto();
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
      opt2 = menusJuego::menuCartas();

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
            menusJuego::porDefecto();
            cout << "-----Error: Codigo no valido" << endl << endl;
            system("cls");
            break;

        }
        system("cls");
    } while (opt2 != 5);

}
