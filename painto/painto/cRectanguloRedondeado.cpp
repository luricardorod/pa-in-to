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

bool cRectanguloRedondeado::hitTest(Point mouseCoords)
{
	return false;
}

void cRectanguloRedondeado::Guardar(ofstream &salida)
{
	salida << base << endl;
	salida << altura << endl;

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
	entrada >> base;
	entrada >> altura;
	entrada >> radio;
}