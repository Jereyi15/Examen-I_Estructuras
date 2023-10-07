
#include "Juego.h"

Jugador* player;
menusJuego* menu = new menusJuego();

Juego::Juego()
{

    int option = 0;
principal:
    cjnJugadores.agregar(player = new Jugador("Felipe"));
    cjnJugadores.agregar(player = new Jugador("Jeremy"));
    cjnJugadores.agregar(player = new Jugador("Irina"));
    cjnJugadores.agregar(player = new Jugador("Gabriel"));
    cjnJugadores.agregar(player = new Jugador("Pablo"));

    cartas.crearBaraja();
    cout << "Baraja creada con exito." << endl;
    system("pause");
    system("cls");

    do {
        system("cls");
     option = menusJuego::mainMenu();

      system("cls");

        switch (option) {
        case 1: {
            instruccionesYreglas();
            system("pause");
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

    do {
      opt1 = menusJuego::jugadores();

        system("cls");

        switch (opt1) {
        case 1: 

           menu->agregarJugadores();


           if (!cjnJugadores.contadorJugadores()) {
               cout << "Nombre del jugador: ";
               cin.ignore(); // Limpia el búfer de entrada
               getline(cin, nombre);
               cjnJugadores.agregar(player = new Jugador(nombre));
           }
           else {
               cout << "Haz alcanzado el maximo de 7 jugadores para la partida.\n";
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
            system("cls");
            break;

        }
        system("cls");
    } while (opt2 != 4);

}
void Juego::instruccionesYreglas() {
    menusJuego::instrucciones();
}