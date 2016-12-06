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
	apotema;

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

Point Cross2(Point p1, Point p2)
{
	Point result;
	result.x = p1.x*p2.x;
	result.y = p1.y*p2.y;
	return result;
}

float Dot2(sf::Vector2f p1, sf::Vector2f p2)
{
	return ((p1.x*p2.x)+(p1.y*p2.y));
}

bool cTriangulo::hitTest(Point mouseCoords)
{
	sf::Vector2f vector1, vector2, vector3;
	sf::Vector2f mousese;
	mousese.x = mousese.x;
	mousese.y = mousese.y;
	float cross1, cross2;

	vector1 = Triangulo.getPoint(1) - Triangulo.getPoint(0);
	vector2 = mousese - Triangulo.getPoint(0);

	cross1 = vector2.x*vector1.y - vector1.x*vector2.y;

	vector1 = Triangulo.getPoint(2) - Triangulo.getPoint(1);
	vector2 = mousese - Triangulo.getPoint(1);

	cross2 = vector2.x*vector1.y - vector1.x*vector2.y;

	cross1 = cross1*cross2;

	return (cross1 > 0);
}

void cTriangulo::Guardar(ofstream &salida)
{
	salida << to_string(apotema) << endl;
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

void cTriangulo::Cargar(ifstream &entrada)
{
	string str;
	Triangulo.setOutlineThickness(2);
	infoFig = &Triangulo;
	sf::Color colortemp;
	sf::Vector2f posTemp;

	getline(entrada, str);
	apotema = stof(str);
	Triangulo.setPointCount(3);

	for (int i = 0; i < 3; i++)
	{
		Triangulo.setPoint(i, sf::Vector2f(apotema*sin((i*(360 / 3))*(pi / 180)), apotema*-cos((i*(360 / 3))*(pi / 180))));
	}

	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	Triangulo.setOutlineColor(colortemp);

	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	Triangulo.setFillColor(colortemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	Triangulo.setPosition(posTemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	Triangulo.setScale(posTemp);
}

string cTriangulo::info() {
	return "lu";
}