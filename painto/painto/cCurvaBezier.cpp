#include "stdafx.h"
#include "cCurvaBezier.h"


int cCurvaBezier::GetClsId()
{
	return ClsId_CurvaBezier;
}
cCurvaBezier::cCurvaBezier()
{
}

cCurvaBezier::~cCurvaBezier()
{
}

void cCurvaBezier::Dibujar()
{

}

void cCurvaBezier::setColorLinea(Vector3f nuevoColor)
{
	colorLinea = nuevoColor;
}

Vector3f cCurvaBezier::getColorLinea()
{
	return colorLinea;
}

bool cCurvaBezier::hitTest(Point mouseCoords)
{
	return false;
}

void cCurvaBezier::Guardar(ofstream &salida)
{
	salida << pInicio.x << endl;
	salida << pInicio.y << endl;

	salida << pFinal.x << endl;
	salida << pFinal.y << endl;

	salida << pAnclaje1.x << endl;
	salida << pAnclaje1.y << endl;

	salida << pAnclaje2.x << endl;
	salida << pAnclaje2.y << endl;
}

void cCurvaBezier::Cargar(ifstream &entrada)
{
	entrada >> pInicio.x;
	entrada >> pInicio.y;

	entrada >> pFinal.x;
	entrada >> pFinal.y;

	entrada >> pAnclaje1.x;
	entrada >> pAnclaje1.y;

	entrada >> pAnclaje2.x;
	entrada >> pAnclaje2.y;
}