#include "stdafx.h"
#include "cElipse.h"
#include <string>
#define pi 3.14159265359

int cElipse::GetClsId()
{
	return ClsId_Elipse;
}

void cElipse::Dibujar(sf::RenderWindow &Ventana)
{
	Ventana.draw(Elipse);
}

cElipse::cElipse()
{

}

cElipse::cElipse(Point p1, Point p2)
{
	float anch = (p2.x - p1.x)/1.0f;
	float alto = (p2.y - p1.y)/1.0f;
	radio1 = anch;
	radio2 = alto;
	Elipse.setPointCount(21);

	for (int i = 0; i <= 20; i++)
	{
		Elipse.setPoint(i, sf::Vector2f(anch*cos((i*pi * 18) / 180), alto*sin((i*pi * 18) / 180)));
	}
	Elipse.setOutlineThickness(2);
	Elipse.setOutlineColor(sf::Color::Black);
	Elipse.setPosition(sf::Vector2f(p1.x, p1.y));

	infoFig = &Elipse;
}

cElipse::~cElipse()
{
}

bool cElipse::hitTest(Point mouseCoords)
{
	return false;
}

void cElipse::Guardar(ofstream &salida)
{
	salida << to_string(radio1) << endl;
	salida << to_string(radio2) << endl;
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

void cElipse::Cargar(ifstream &entrada)
{
	string str;
	Elipse.setOutlineThickness(2);
	infoFig = &Elipse;
	sf::Color colortemp;
	sf::Vector2f posTemp;

	getline(entrada, str);
	radio1 = stof(str);
	getline(entrada, str);
	radio2 = stof(str);
	Elipse.setPointCount(21);
	for (int i = 0; i <= 20; i++)
	{
		Elipse.setPoint(i, sf::Vector2f(radio1*cos((i*pi * 18) / 180), radio2*sin((i*pi * 18) / 180)));
	}

	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	Elipse.setOutlineColor(colortemp);

	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	Elipse.setFillColor(colortemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	Elipse.setPosition(posTemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	Elipse.setScale(posTemp);
}

string cElipse::info() {
	return "lu";
}