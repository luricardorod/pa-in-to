#include "stdafx.h"
#include "cTiraDeLinea.h"
#include <string>


int cTiraDeLinea::GetClsId()
{
	return ClsId_TiraDeLinea;
}
cTiraDeLinea::cTiraDeLinea()
{
	lines.clear();
	lines.setPrimitiveType(sf::LineStrip);
}


cTiraDeLinea::~cTiraDeLinea()
{
}

void cTiraDeLinea::addPointu(Point nP)
{
	lines.append(sf::Vertex(sf::Vector2f(nP.x, nP.y), sf::Color::Black));
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
	Ventana.draw(lines);
}

bool cTiraDeLinea::hitTest(Point mouseCoords)
{
	return false;
}

void cTiraDeLinea::Guardar(ofstream &salida)
{
	salida << listaDePuntos.size() << endl;
	for (int i = 0; i < listaDePuntos.size(); i++)
	{
		salida << listaDePuntos[i].x << endl;
		salida << listaDePuntos[i].y << endl;
	}
}

void cTiraDeLinea::Cargar(ifstream &entrada)
{
	int sz;
	entrada >> sz;
	listaDePuntos.clear();
	listaDePuntos.resize(sz);
	for (int i = 0; i < listaDePuntos.size(); i++)
	{
		/*
		entrada >> listaDePuntos[i].x;
		entrada >> listaDePuntos[i].y;
		*/
		string str;
		getline(entrada, str);
		listaDePuntos[i].x = stof(str);
		getline(entrada, str);
		listaDePuntos[i].y = stof(str);
	}
}

string cTiraDeLinea::info()
{
	return "lu";
}