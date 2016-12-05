#include "stdafx.h"
#include "cTriangulo.h"
#include <string>
#define pi 3.14159265359

int cTriangulo::GetClsId()
{
	return ClsId_Triangulo;
}
void cTriangulo::Dibujar(sf::RenderWindow &Ventana)
{
	Ventana.draw(Triangulo);
}

cTriangulo::cTriangulo(Point p1, Point p2)
{
	float apotema;

	if (p2.x - p1.x > p2.y - p1.y)
		apotema = p2.x - p1.x;
	else
		apotema = p2.y - p1.y;

	Triangulo.setPointCount(3);

	for (int i = 0; i < 3; i++)
	{
		Triangulo.setPoint(i, sf::Vector2f(apotema*sin((i*(360 / 3))*(pi / 180)), apotema*-cos((i*(360 / 3))*(pi / 180))));
	}

	Triangulo.setPosition(p1.x, p1.y);
	Triangulo.setOutlineThickness(2);
	Triangulo.setOutlineColor(sf::Color::Black);
	infoFig = &Triangulo;
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
	/*
	entrada >> p1.x;
	entrada >> p1.y;

	entrada >> p2.x;
	entrada >> p2.y;

	entrada >> p3.x;
	entrada >> p3.y;
	*/
	string str;
	getline(entrada, str);
	p1.x = stof(str);
	getline(entrada, str);
	p1.y = stof(str);

	getline(entrada, str);
	p2.x = stof(str);
	getline(entrada, str);
	p2.y = stof(str);

	getline(entrada, str);
	p3.x = stof(str);
	getline(entrada, str);
	p3.y = stof(str);
}

string cTriangulo::info() {
	return "lu";
}