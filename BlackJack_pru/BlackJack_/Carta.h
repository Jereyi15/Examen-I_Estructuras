#pragma once
#include <string>
using namespace std;

class Carta
{
public:
	Carta(string, char, char);
	virtual ~Carta();
	string getValor();
	char getPalo();
	char getColor();

	string toString();

private:
	string valor;
	char palo;
	char color;

};

