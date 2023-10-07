#include "Juego.h"

Juego::Juego()
{
    // pruebas
    Jugador* player;
    cjnJugadores.agregar(player = new Jugador("Felipe"));
    cjnJugadores.agregar(player = new Jugador("Jeremy"));
    cjnJugadores.agregar(player = new Jugador("Irina"));
    cjnJugadores.agregar(player = new Jugador("Gabriel"));
    cjnJugadores.agregar(player = new Jugador("Pablo"));

    cout << cjnJugadores.toString() << endl;

    // Primero se mostraran las cartas de color rojo y luego las de color negro
    system("pause");
    system("cls");

    cout << "Baraja recien creada: "<< endl;
    cartas.crearBaraja();
    cout << cartas.toString();

    system("pause");
    system("cls");

    cout << "Baraja recien barajada: " << endl;
    cartas.barajarCartas();
    cout << cartas.toString();

    system("pause");
    system("cls");

    Carta cartaTomada = cartas.tomarCarta();
    cout << "Tomada: " << cartaTomada.toString();


    cout << "Baraja recien ordenada: " << endl;
    cartas.ordenarCartas();
    cout << cartas.toString();

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
