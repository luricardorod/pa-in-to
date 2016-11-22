#include "stdafx.h"
#include "cRectanguloRedondeado.h"


cRectanguloRedondeado::cRectanguloRedondeado()
{

}

cRectanguloRedondeado::~cRectanguloRedondeado()
{

}

int cRectanguloRedondeado::GetClsId()
{
	return ClsId_RectanguloRedondeado;
}

void cRectanguloRedondeado::Dibujar()
{

}

void cRectanguloRedondeado::setColorLinea(Vector3f nuevoColor)
{
	colorLinea = nuevoColor;
}

Vector3f cRectanguloRedondeado::getColorLinea()
{
	return colorLinea;
}

bool cRectanguloRedondeado::hitTest(Point mouseCoords)
{
	return false;
}

void cRectanguloRedondeado::Guardar(ofstream &salida)
{
	salida << p1.x << endl;
	salida << p1.y << endl;

	salida << p2.x << endl;
	salida << p2.y << endl;

	salida << p3.x << endl;
	salida << p3.y << endl;

	salida << p4.x << endl;
	salida << p4.y << endl;

	salida << radio << endl;
}

void cRectanguloRedondeado::Cargar(ifstream &entrada)
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

	entrada >> radio;
}