#include "stdafx.h"
#include "cPoligonos.h"
#include <string>


int cPoligonos::GetClsId()
{
	return ClsId_Poligono;
}

void cPoligonos::Dibujar(sf::RenderWindow &Ventana)
{

}

cPoligonos::cPoligonos()
{

}


cPoligonos::~cPoligonos()
{
}

bool cPoligonos::hitTest(Point mouseCoords)
{
	return false;
}

void cPoligonos::Guardar(ofstream &salida)
{
	salida << listaPuntos.size() << endl;
	for (int i = 0; i < listaPuntos.size(); i++)
	{
		salida << listaPuntos[i].x << endl;
		salida << listaPuntos[i].y << endl;
	}
}

void cPoligonos::Cargar(ifstream &entrada)
{
	listaPuntos.clear();
	int sz;
	entrada >> sz;
	listaPuntos.resize(sz);
	for (int i = 0; i < listaPuntos.size(); i++)
	{
		/*
		entrada >> listaPuntos[i].x;
		entrada >> listaPuntos[i].y;
		*/
		string str;
		getline(entrada, str);
		listaPuntos[i].x = stof(str);
		getline(entrada, str);
		listaPuntos[i].y = stof(str);
	}
}

string cPoligonos::info() {
	return "lu";
}