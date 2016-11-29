#include "stdafx.h"
#include "cCurvaBezier.h"
#include <string>


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

void cCurvaBezier::Dibujar(sf::RenderWindow &Ventana)
{

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
	/*
	entrada >> pInicio.x;
	entrada >> pInicio.y;

	entrada >> pFinal.x;
	entrada >> pFinal.y;

	entrada >> pAnclaje1.x;
	entrada >> pAnclaje1.y;

	entrada >> pAnclaje2.x;
	entrada >> pAnclaje2.y;
	*/
	string str;
	getline(entrada, str);
	pInicio.x = stof(str);
	getline(entrada, str);
	pInicio.y = stof(str);

	getline(entrada, str);
	pFinal.x = stof(str);
	getline(entrada, str);
	pFinal.y = stof(str);

	getline(entrada, str);
	pAnclaje1.x = stof(str);
	getline(entrada, str);
	pAnclaje1.y = stof(str);

	getline(entrada, str);
	pAnclaje2.x = stof(str);
	getline(entrada, str);
	pAnclaje2.y = stof(str);
}

string cCurvaBezier::info() {
	return "lu";
}