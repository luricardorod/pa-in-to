#include "stdafx.h"
#include "cElipse.h"
#include <string>


int cElipse::GetClsId()
{
	return ClsId_Elipse;
}

void cElipse::Dibujar(sf::RenderWindow &Ventana)
{
}

cElipse::cElipse()
{

}


cElipse::~cElipse()
{
}

bool cElipse::hitTest(Point mouseCoords)
{
	return false;
}

void cElipse::Guardar(ofstream &salida)
{
	salida << radio1 << endl;
	salida << radio2 << endl;
}

void cElipse::Cargar(ifstream &entrada)
{
	/*
	entrada >> radio1;
	entrada >> radio2;
	*/
	string str;
	getline(entrada, str);
	radio1 = stof(str);
	getline(entrada, str);
	radio2 = stof(str);
}