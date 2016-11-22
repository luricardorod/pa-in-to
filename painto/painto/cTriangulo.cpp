#include "stdafx.h"
#include "cTriangulo.h"


int cTriangulo::GetClsId()
{
	return ClsId_Triangulo;
}
void cTriangulo::Dibujar()
{

}

cTriangulo::cTriangulo()
{

}


cTriangulo::~cTriangulo()
{
}


bool cTriangulo::hitTest(Point mouseCoords)
{
	Point vector1, vector2;
	float cross1, cross2;
	vector1.x = p2.x - p1.x;
	vector1.y = p2.y - p1.y;

	vector2.x = mouseCoords.x - p2.x;
	vector2.y = mouseCoords.y - p2.y;

	cross1 = (vector1.x*vector2.y) - (vector2.x*vector1.y);

	vector1.x = p3.x - p2.x;
	vector1.y = p3.y - p2.y;

	vector2.x = mouseCoords.x - p3.x;
	vector2.y = mouseCoords.y - p3.y;
	cross2 = (vector1.x*vector2.y) - (vector2.x*vector1.y);
	if ((cross1 > 0 && cross2 > 0) || (cross1 < 0 && cross2 < 0))
	{
		return true;
	}

	return false;
}

void cTriangulo::Guardar(ofstream &salida)
{
	salida << p1.x << endl;
	salida << p1.y << endl;

	salida << p2.x << endl;
	salida << p2.y << endl;

	salida << p3.x << endl;
	salida << p3.y << endl;
}

void cTriangulo::Cargar(ifstream &entrada)
{
	entrada >> p1.x;
	entrada >> p1.y;

	entrada >> p2.x;
	entrada >> p2.y;

	entrada >> p3.x;
	entrada >> p3.y;
}