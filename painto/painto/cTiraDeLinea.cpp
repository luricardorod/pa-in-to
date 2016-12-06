#include "stdafx.h"
#include "cTiraDeLinea.h"
#include <string>


int cTiraDeLinea::GetClsId()
{
	return ClsId_TiraDeLinea;
}
cTiraDeLinea::cTiraDeLinea()
{
	vertices.clear();
	vertices.setPrimitiveType(sf::LineStrip);
}


cTiraDeLinea::~cTiraDeLinea()
{
}

void cTiraDeLinea::addPointu(Point nP)
{
	vertices.append(sf::Vertex(sf::Vector2f(nP.x, nP.y), sf::Color::Black));
	tamano++;
}

void cTiraDeLinea::setColorLinea(Vector3f nuevoColor)
{
}

Vector3f cTiraDeLinea::getColorLinea()
{
	return Vector3f();
}

void cTiraDeLinea::Dibujar(sf::RenderWindow &Ventana)
{
	Ventana.draw(vertices);
}

bool cTiraDeLinea::hitTest(Point mouseCoords)
{
	return false;
}

void cTiraDeLinea::Guardar(ofstream &salida)
{
	salida << tamano << endl;
	for (int i = 0; i < tamano; i++)
	{
		salida << (vertices[i].position).x << endl;
		salida << (vertices[i].position).y << endl;
	}
	salida << vertices[0].color.r << endl;
	salida << vertices[0].color.g << endl;
	salida << vertices[0].color.b << endl;
	salida << vertices[0].color.a << endl;
}

void cTiraDeLinea::Cargar(ifstream &entrada)
{
	vertices.clear();
	vertices.setPrimitiveType(sf::LineStrip);

	sf::Vertex nuevo;
	string str;
	getline(entrada, str);

	tamano = stof(str);

	vertices.resize(tamano);

	for (int i = 0; i < tamano; i++)
	{
		getline(entrada, str);
		nuevo.position.x = stof(str);
		getline(entrada, str);
		nuevo.position.y = stof(str);

		vertices.append(nuevo);
	}
	sf::Color colorin;

	getline(entrada, str);
	colorin.r = stof(str);

	getline(entrada, str);
	colorin.g = stof(str);

	getline(entrada, str);
	colorin.b = stof(str);

	getline(entrada, str);
	colorin.a = stof(str);

	for (int i = 0; i < tamano; i++)
	{
		vertices[i].color = colorin;
	}
}

string cTiraDeLinea::info()
{
	return "lu";
}

void cTiraDeLinea::setMove(float x, float y)
{
	for (int i = 0; i < tamano; i++)
	{
		vertices[i].position = vertices[i].position + sf::Vector2f(x, y);
	}
}

void cTiraDeLinea::setColor(sf::Color newColor)
{
	for (int i = 0; i < tamano; i++)
	{
		vertices[i].color = newColor;
	}
}

sf::Color cTiraDeLinea::getColor()
{
	return vertices[0].color;
}