#include "stdafx.h"
#include "cRectanguloRedondeado.h"
#include <string>
#include <iostream>

#define pi 3.14159265

#define POINTS 10

sf::ConvexShape RoundedRectangle(float x, float y, float rectWidth, float rectHeight, float radius)
{
	sf::ConvexShape rrect;
	float X = 0, Y = 0;
	int index = 0;

	rrect.setPointCount(POINTS*4);
	for (int i = 0; i < POINTS; i++)
	{
		X += radius / POINTS;
		Y = sqrt(radius*radius - X*X);
		rrect.setPoint(index, sf::Vector2f(X + x + rectWidth - radius, y - Y + radius));
		index++;
	}
	Y = 0;
	for (int i = 0; i<POINTS; i++)
	{
		Y += radius / POINTS;
		X = sqrt(radius*radius - Y*Y);
		rrect.setPoint(index, sf::Vector2f(x + rectWidth + X - radius, y + rectHeight - radius + Y));
		index++;
	}
	X = 0;
	for (int i = 0; i<POINTS; i++)
	{
		X += radius / POINTS;
		Y = sqrt(radius*radius - X*X);
		rrect.setPoint(index, sf::Vector2f(x + radius - X, y + rectHeight - radius + Y));
		index++;
	}
	Y = 0;
	for (int i = 0; i<POINTS; i++)
	{
		Y += radius / POINTS;
		X = sqrt(radius*radius - Y*Y);
		rrect.setPoint(index, sf::Vector2f(x - X + radius, y + radius - Y));
		index++;
	}
	return rrect;

}

cRectanguloRedondeado::cRectanguloRedondeado()
{
}

cRectanguloRedondeado::cRectanguloRedondeado(Point p1, Point p2)
{
	float anch = p2.x - p1.x;
	float alto = p2.y - p1.y;

	rectanguloC.setPointCount(21);

	for (int i = 0; i <= 20; i++)
	{
		rectanguloC.setPoint(i, sf::Vector2f(p1.x + anch*cos((i*pi*18) / 180), p1.x + alto*sin((i*pi*18) / 180)));
	}

	rectanguloC.setFillColor(sf::Color::Blue);

	rectanguloC.setPosition(sf::Vector2f(p1.x, p1.y));
}

cRectanguloRedondeado::~cRectanguloRedondeado()
{

}

void cRectanguloRedondeado::setColorLinea(Vector3f nuevoColor)
{

}

void cRectanguloRedondeado::setColorRelleno(Vector3f nuevoColor)
{

}

int cRectanguloRedondeado::GetClsId()
{
	return ClsId_RectanguloRedondeado;
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
	-----------------------
	entrada >> base;
	entrada >> altura;
	entrada >> radio;
	*/

	string str;
	getline(entrada, str);
	base = stof(str);
	getline(entrada, str);
	altura = stof(str);

	getline(entrada, str);
	radio = stof(str);
}

string cRectanguloRedondeado::info() {
	return "lu";
}

void cRectanguloRedondeado::Dibujar(sf::RenderWindow & Ventana)
{
	Ventana.draw(rectanguloC);
}