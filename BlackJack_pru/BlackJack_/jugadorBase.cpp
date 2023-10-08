#include "jugadorBase.h"
#include <sstream>
using std::stringstream; 

jugadorBase::jugadorBase(string _nombre, Mazo* mazo) : nombre(_nombre), mazo(mazo)
{
}

jugadorBase::~jugadorBase()
{

}

string jugadorBase::getNombre()
{
    return nombre;
}

string jugadorBase::toString()
{
    stringstream r;

    r << nombre << endl;
    r << "Mazo: " << mazo->mostrarCartas() << endl;

    return r.str();
}
