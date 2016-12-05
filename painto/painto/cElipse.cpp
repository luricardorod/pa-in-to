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
	salida << radio1 << endl;
	salida << radio2 << endl;
}

void cElipse::Cargar(ifstream &entrada)
{
	/*
	entrada >> radio1;
	entrada >> radio2;
	*/
	string str;
	getline(entrada, str);
	radio1 = stof(str);
	getline(entrada, str);
	radio2 = stof(str);
}

string cElipse::info() {
	return "lu";
}