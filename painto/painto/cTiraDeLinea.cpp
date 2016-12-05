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
}

void cTiraDeLinea::Cargar(ifstream &entrada)
{
	int sz;
	entrada >> sz;
	vertices.clear();
	vertices.resize(sz);
	tamano = sz;
	for (int i = 0; i < tamano; i++)
	{
		string str;
		getline(entrada, str);
		vertices[i].position.x = stof(str);
		getline(entrada, str);
		vertices[i].position.y = stof(str);
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