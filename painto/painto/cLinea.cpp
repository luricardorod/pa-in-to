#include "stdafx.h"
#include "cLinea.h"
#include <string>


int cLinea::GetClsId()
{
	return ClsId_Linea;
}
cLinea::cLinea()
{
}


cLinea::~cLinea()
{
}

void cLinea::Dibujar(sf::RenderWindow &Ventana)
{

}

bool cLinea::hitTest(Point mouseCoords)
{
	return false;
}

void cLinea::Guardar(ofstream &salida)
{
	salida << p1.x << endl;
	salida << p1.y << endl;

	salida << p2.x << endl;
	salida << p2.y << endl;
}

void cLinea::Cargar(ifstream &entrada)
{
	/*
	entrada >> p1.x;
	entrada >> p1.y;

	entrada >> p2.x;
	entrada >> p2.y;
	*/
	string str;
	getline(entrada, str);
	p1.x = stof(str);
	getline(entrada, str);
	p1.y = stof(str);

	getline(entrada, str);
	p2.x = stof(str);
	getline(entrada, str);
	p2.y = stof(str);
}