#include "stdafx.h"
#include "cLinea.h"
#include <string>


int cLinea::GetClsId()
{
	return ClsId_Linea;
}

cLinea::cLinea()
{
}

cLinea::cLinea(Point p1, Point p2)
{
	vertices.setPrimitiveType(sf::Lines);
	vertices.clear();
	vertices.resize(2);
	tamano = 2;

	vertices[0].position = sf::Vector2f(p1.x, p1.y);
	vertices[1].position = sf::Vector2f(p2.x, p2.y);
	vertices[0].color = sf::Color::Black;
	vertices[1].color = sf::Color::Black;
}

cLinea::~cLinea()
{
}

void cLinea::Dibujar(sf::RenderWindow &Ventana)
{
	Ventana.draw(vertices);
}

bool cLinea::hitTest(Point mouseCoords)
{
	return false;
}

void cLinea::Guardar(ofstream &salida)
{
	salida << (vertices[0].position).x << endl;
	salida << (vertices[0].position).y << endl;

	salida << (vertices[1].position).x << endl;
	salida << (vertices[1].position).y << endl;

	salida << (vertices[1].color).r << endl;
	salida << (vertices[1].color).g << endl;
	salida << (vertices[1].color).b << endl;
	salida << (vertices[1].color).a << endl;
}

void cLinea::Cargar(ifstream &entrada)
{
	vertices.setPrimitiveType(sf::Lines);
	vertices.clear();
	vertices.resize(2);
	tamano = 2;

	string str;
	getline(entrada, str);
	(vertices[0].position).x = stof(str);
	getline(entrada, str);
	(vertices[0].position).y = stof(str);

	getline(entrada, str);
	(vertices[1].position).x = stof(str);
	getline(entrada, str);
	(vertices[1].position).y = stof(str);

	sf::Color Colorin;

	getline(entrada, str);
	Colorin.r = stof(str);

	getline(entrada, str);
	Colorin.g = stof(str);

	getline(entrada, str);
	Colorin.b = stof(str);

	getline(entrada, str);
	Colorin.a = stof(str);

	vertices[0].color = Colorin;
	vertices[1].color = Colorin;
}

string cLinea::info()
{
	return "lu";
}

void cLinea::setMove(float x, float y)
{
	for (int i = 0; i < tamano; i++)
	{
		vertices[i].position = vertices[i].position + sf::Vector2f(x, y);
	}
}

void cLinea::setColor(sf::Color newColor)
{
	for (int i = 0; i < tamano; i++)
	{
		vertices[i].color = newColor;
	}
}

sf::Color cLinea::getColor()
{
	return vertices[0].color;
}