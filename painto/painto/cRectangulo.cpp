#include "stdafx.h"
#include "cRectangulo.h"
#include <string>

cRectangulo::cRectangulo()
{

}

cRectangulo::~cRectangulo()
{

}


bool cRectangulo::hitTest(Point mouseCoords)
{
	Point posicion = getPosition();
	return (((mouseCoords.x >= posicion.x - base/2) && (mouseCoords.x <= posicion.x + base / 2)) && ((mouseCoords.y >= posicion.y - altura / 2) && (mouseCoords.y <= posicion.y + altura / 2)));
}

void cRectangulo::Guardar(ofstream &salida)
{

	salida << base << endl;
	salida << altura << endl;
};

void cRectangulo::Cargar(ifstream &entrada)
{
	/*
	int i = 0;
	while (!entrada.eof())
	{
		if (i == 1)
		{
			float n;
			entrada >> n;
			base = n;
		}
		if (i == 2)
		{
			float n;
			entrada >> n;
			altura = n;
			break;
		}
		i++;
	}
	*/
	string str;
	getline(entrada, str);
	base = stof(str);
	getline(entrada, str);
	altura = stof(str);
};

int cRectangulo::GetClsId()
{
	return ClsId_Rectangulo;
};

void cRectangulo::Dibujar()
{

};