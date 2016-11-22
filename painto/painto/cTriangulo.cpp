#include "stdafx.h"
#include "cTriangulo.h"


int cTriangulo::GetClsId()
{
	return ClsId_Triangulo;
}
cTriangulo::cTriangulo()
{
}


cTriangulo::~cTriangulo()
{
}

void cTriangulo::Guardar(ofstream & salida)
{
	salida << p1.x << endl;
	salida << p1.y << endl;

	salida << p2.x << endl;
	salida << p2.y << endl;

	salida << p3.x << endl;
	salida << p3.y << endl;
}

void cTriangulo::Cargar(ifstream & entrada)
{
	entrada >> p1.x;
	entrada >> p1.y;

	entrada >> p2.x;
	entrada >> p2.y;

	entrada >> p3.x;
	entrada >> p3.y;
}