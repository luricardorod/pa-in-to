#include "stdafx.h"
#include "cRectanguloRedondeado.h"
#include <string>
#include <iostream>

#define pi 3.14159265


cRectanguloRedondeado::cRectanguloRedondeado()
{
}

cRectanguloRedondeado::cRectanguloRedondeado(Point p1, Point p2)
{
	float anch = (p2.x - p1.x) / 2.0f;
	float alto = (p2.y - p1.y) / 2.0f;

	rectanguloC.setPointCount(121);

	for (int i = 0; i <= 120; i++)
	{
		if (i <= 30)
			rectanguloC.setPoint(i, sf::Vector2f(anch*sin((i*pi * 3) / 180) + anch, alto*-cos((i*pi * 3) / 180) - alto));
		else if (i <= 60)
			rectanguloC.setPoint(i, sf::Vector2f(anch*sin((i*pi * 3) / 180) + anch, alto*-cos((i*pi * 3) / 180) + alto));
		else if (i <= 90)
			rectanguloC.setPoint(i, sf::Vector2f(anch*sin((i*pi * 3) / 180) - anch, alto*-cos((i*pi * 3) / 180) + alto));
		else
			rectanguloC.setPoint(i, sf::Vector2f(anch*sin((i*pi * 3) / 180) - anch, alto*-cos((i*pi * 3) / 180) - alto));
	}
	rectanguloC.setOutlineThickness(2);
	rectanguloC.setOutlineColor(sf::Color::Black);
	rectanguloC.setPosition(sf::Vector2f(p1.x, p1.y));

	infoFig = &rectanguloC;
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