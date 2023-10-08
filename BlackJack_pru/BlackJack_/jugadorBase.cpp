#include "jugadorBase.h"
#include <sstream>
using std::stringstream; 

jugadorBase::jugadorBase(string _nombre, Mazo* mazo) : nombre(_nombre), mazo(mazo)
{
}

jugadorBase::~jugadorBase()
{

}

string jugadorBase::toString()
{
    stringstream r;

    r << "Nombre: " << nombre << endl;
    //r << "Mazo: " << mazo->mostrarCartas() << endl;

    return r.str();
}
