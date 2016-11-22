#include "stdafx.h"
#include "cTexto.h"


int cTexto::GetClsId()
{
	return ClsId_Texto;
}
cTexto::cTexto()
{
}


cTexto::~cTexto()
{
}

void cTexto::Dibujar()
{

}

void cTexto::setColorLinea(Vector3f nuevoColor)
{
	colorLinea = nuevoColor;
}

Vector3f cTexto::getColorLinea()
{
	return colorLinea;
}

bool cTexto::hitTest(Point mouseCoords)
{
	return false;
}

void cTexto::Guardar(ofstream &salida)
{
	salida << p1.x << endl;
	salida << p1.y << endl;

	salida << p2.x << endl;
	salida << p2.y << endl;

	salida << p3.x << endl;
	salida << p3.y << endl;

	salida << p4.x << endl;
	salida << p4.y << endl;
}

void cTexto::Cargar(ifstream &entrada)
{
	entrada >> p1.x;
	entrada >> p1.y;

	entrada >> p2.x;
	entrada >> p2.y;

	entrada >> p3.x;
	entrada >> p3.y;

	entrada >> p4.x;
	entrada >> p4.y;
}