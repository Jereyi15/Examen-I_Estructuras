#include "ConjuntoCartas.h"
#include "Carta.h"
#include <sstream>
#include <algorithm> //Librerias utilizada para barajas las cartas de manera aleatoria
#include <random> //Librerias utilizada para barajas las cartas de manera aleatoria
#include <queue>
using std::stringstream;

ConjuntoCartas::ConjuntoCartas(){

}
ConjuntoCartas::~ConjuntoCartas() {

}
void ConjuntoCartas::agregar(Carta* cartaNueva) {
	cartas.push_back(*cartaNueva);
}
Carta* ConjuntoCartas::recuperar(char palo, string valor) {
    for (it = cartas.begin(); it != cartas.end(); it++) {
        if (it->getPalo() == palo && it->getValor() == valor) {
            return &*it; // Devuelve el puntero a la carta encontrada
        }
    }
    return nullptr; 
}

void ConjuntoCartas::crearBaraja() {
    const string valores[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const char palosRojos[] = { 4, 3 }; 
    const char palosNegros[] = { 5, 6,};
  
    for (const string& valor : valores) {
            for (const char& palo : palosRojos) {
                // Crea una carta y la agrega a la baraja
                Carta carta(valor, palo, 'R');
                cartas.push_back(carta);
            }
    }
    for (const string& valor : valores) {
        for (const char& palo : palosNegros) {
            // Crea una carta y la agrega a la baraja
            Carta carta(valor, palo, 'N');
            cartas.push_back(carta);
        }
    }
   
}
//Compara las cartas por valor, iniciando de A hasta K
void ConjuntoCartas::ordenarCartas() {
    cartas.sort([](Carta& a, Carta& b) {
        string valores = "A23456789XJQK"; 
        return valores.find(a.getValor()) < valores.find(b.getValor());
        });
}
/* Referencia del método barajarCartas():
Techie Delight. (2023). Shuffle an array using Fisher–Yates shuffle algorithm.
Recuoperado el 6 de octubre de 2023 de https://www.techiedelight.com/shuffle-given-array-elements-fisher-yates-shuffle/
*/
void ConjuntoCartas::barajarCartas() {
    int n = cartas.size();
    queue<Carta> colaCartas;

    // Si la lista no está vacía, se mete todo lo que tiene la cola
    while (!cartas.empty()) {
        colaCartas.push(cartas.front());
        cartas.pop_front();
    }

    // Aleatoriedad conectada al tiempo actual, para asegurar que se baraje bien
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Carta> cartasBarajadas;

    for (int indiceCarta = n; indiceCarta > 0; indiceCarta--) {
        // Genera un índice aleatorio entre 0 e indiceCarta -1
        int indiceAleatorio = rand() % indiceCarta;

        // Mueve las cartas de la cola hasta el índice aleatorio
        for (int i = 0; i < indiceAleatorio; i++) {
            Carta carta = colaCartas.front();
            colaCartas.pop();
            colaCartas.push(carta);
        }

        // Agrega la carta en el índice aleatorio al vector de cartas barajadas
        cartasBarajadas.push_back(colaCartas.front());
        colaCartas.pop();
    }

    // Copia las cartas barajadas a la cola original
    for (const Carta& carta : cartasBarajadas) {
        colaCartas.push(carta);
    }

    // Las cartas barajadas de la cola, las manda de vuelta a la lista original
    while (!colaCartas.empty()) {
        cartas.push_back(colaCartas.front());
        colaCartas.pop();
    }
}
Carta ConjuntoCartas::tomarCarta() {
    if (!cartas.empty()) {
        //Toma la primera carta de la baraja previamente barajada en la clase juego
        Carta cartaTomada = cartas.front();
        cartas.pop_front();
        return cartaTomada;
    }
}
string ConjuntoCartas::toString()
{
    stringstream s;
    for (it = cartas.begin(); it != cartas.end(); it++) {
        s << it->toString() << "  -  ";
    }
    return s.str();
}
