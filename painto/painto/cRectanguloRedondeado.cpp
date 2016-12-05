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
	base = anch;
	altura = alto;
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
	salida << to_string(base) << endl;
	salida << to_string(altura) << endl;
	salida << to_string(infoFig->getOutlineColor().r) << endl;
	salida << to_string(infoFig->getOutlineColor().g) << endl;
	salida << to_string(infoFig->getOutlineColor().b) << endl;
	salida << to_string(infoFig->getFillColor().r) << endl;
	salida << to_string(infoFig->getFillColor().g) << endl;
	salida << to_string(infoFig->getFillColor().b) << endl;
	salida << to_string(infoFig->getPosition().x) << endl;
	salida << to_string(infoFig->getPosition().y) << endl;
	salida << to_string(infoFig->getScale().x) << endl;
	salida << to_string(infoFig->getScale().y) << endl;
}

void cRectanguloRedondeado::Cargar(ifstream &entrada)
{
	string str;
	rectanguloC.setOutlineThickness(2);
	infoFig = &rectanguloC;
	sf::Color colortemp;
	sf::Vector2f posTemp;

	getline(entrada, str);
	base = stof(str);
	getline(entrada, str);
	altura = stof(str);

	rectanguloC.setPointCount(121);

	for (int i = 0; i <= 120; i++)
	{
		if (i <= 30)
			rectanguloC.setPoint(i, sf::Vector2f(base*sin((i*pi * 3) / 180) + base, altura*-cos((i*pi * 3) / 180) - altura));
		else if (i <= 60)
			rectanguloC.setPoint(i, sf::Vector2f(base*sin((i*pi * 3) / 180) + base, altura*-cos((i*pi * 3) / 180) + altura));
		else if (i <= 90)
			rectanguloC.setPoint(i, sf::Vector2f(base*sin((i*pi * 3) / 180) - base, altura*-cos((i*pi * 3) / 180) + altura));
		else
			rectanguloC.setPoint(i, sf::Vector2f(base*sin((i*pi * 3) / 180) - base, altura*-cos((i*pi * 3) / 180) - altura));
	}


	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	rectanguloC.setOutlineColor(colortemp);

	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	rectanguloC.setFillColor(colortemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	rectanguloC.setPosition(posTemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	rectanguloC.setScale(posTemp);
}

string cRectanguloRedondeado::info() {
	return "lu";
}

void cRectanguloRedondeado::Dibujar(sf::RenderWindow & Ventana)
{
	Ventana.draw(rectanguloC);
}