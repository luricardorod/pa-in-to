#include "stdafx.h"
#include "cRectangulo.h"

cRectangulo::cRectangulo()
{

}

cRectangulo::~cRectangulo()
{

}

void cRectangulo::setColorLinea(Vector3f nuevoColor)
{
	colorLinea = nuevoColor;
}

Vector3f cRectangulo::getColorLinea()
{
	return colorLinea;
}

bool cRectangulo::hitTest(Point mouseCoords)
{
	return (((mouseCoords.x >= p1.x) && (mouseCoords.x <= p2.x)) && ((mouseCoords.y >= p1.y) && (mouseCoords.y <= p4.x)));
}

void cRectangulo::Guardar(ofstream &salida)
{
	salida << p1.x << endl;
	salida << p1.y << endl;

	salida << p2.x << endl;
	salida << p2.y << endl;

	salida << p3.x << endl;
	salida << p3.y << endl;

	salida << p4.x << endl;
	salida << p4.y << endl;
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
	entrada >> p1.x;
	entrada >> p1.y;

	entrada >> p2.x;
	entrada >> p2.y;

	entrada >> p3.x;
	entrada >> p3.y;

	entrada >> p4.x;
	entrada >> p4.y;
};

int cRectangulo::GetClsId()
{
	return ClsId_Rectangulo;
};

void cRectangulo::Dibujar()
{

};