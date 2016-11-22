#include "stdafx.h"
#include "cElipse.h"


int cElipse::GetClsId()
{
	return ClsId_Elipse;
}

void cElipse::Dibujar()
{
}

cElipse::cElipse()
{

}


cElipse::~cElipse()
{
}

void cElipse::setColorLinea(Vector3f nuevoColor)
{
	colorLinea = nuevoColor;
}

Vector3f cElipse::getColorLinea()
{
	return colorLinea;
}

bool cElipse::hitTest(Point mouseCoords)
{
	return false;
}

void cElipse::Guardar(ofstream & salida)
{
	salida << radio1 << endl;
	salida << radio2 << endl;
}

void cElipse::Cargar(ifstream & entrada)
{
	entrada >> radio1;
	entrada >> radio2;
}