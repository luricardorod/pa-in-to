#include "stdafx.h"
#include "cRectangulo.h"
#include "cDocumento.h"
#include <string>
#include <iostream>
using namespace std;

cRectangulo::cRectangulo()
{

}

cRectangulo::cRectangulo(Point p1, Point p2)
{
	Rectangulo = sf::RectangleShape(sf::Vector2f(p2.x - p1.x, p2.y - p1.y));
	//Rectangulo.setOrigin(Rectangulo.getSize().x / 2, Rectangulo.getSize().y / 2);

	Point fixedPosition;
	fixedPosition.x = (p1.x + p2.x) / 2.0f;
	fixedPosition.y = (p1.y + p2.y) / 2.0f;

	setPosicion(p1);

	Rectangulo.setPosition(p1.x, p1.y);

	sf::Color colorin;
	colorin.r = 0;
	colorin.g = 0;
	colorin.b = 0;
	colorin.a = 255;

	Rectangulo.setFillColor(colorin);
	Rectangulo.setOutlineColor(colorin);
	infoFig = &Rectangulo;
}

cRectangulo::~cRectangulo()
{

}


bool cRectangulo::hitTest(Point mouseCoords)
{
	Point posicion = getPosition();
	return (((mouseCoords.x >= posicion.x - base/2) && (mouseCoords.x <= posicion.x + base / 2)) && ((mouseCoords.y >= posicion.y - altura / 2) && (mouseCoords.y <= posicion.y + altura / 2)));
}

void cRectangulo::Guardar(ofstream &salida)
{

	salida << base << endl;
	salida << altura << endl;
};

void cRectangulo::Cargar(ifstream &entrada)
{
	string str;
	getline(entrada, str);
	base = stof(str);
	getline(entrada, str);
	altura = stof(str);
	infoFig = &Rectangulo;

	Rectangulo.setSize(sf::Vector2f (base, altura));
};

int cRectangulo::GetClsId()
{
	return ClsId_Rectangulo;
};

void cRectangulo::Dibujar(sf::RenderWindow &Ventana)
{
	Ventana.draw(Rectangulo);
}

void cRectangulo::setPosicion(Point coordenadas)
{
	Rectangulo.setPosition(coordenadas.x, coordenadas.y);
}

void cRectangulo::setColorLinea(Vector3f nuevoColor)
{
	Rectangulo.setOutlineColor(sf::Color(nuevoColor.x, nuevoColor.y, nuevoColor.z));
}

void cRectangulo::setColorRelleno(Vector3f nuevoColor)
{
	Rectangulo.setFillColor(sf::Color(nuevoColor.x, nuevoColor.y, nuevoColor.z));
}

string cRectangulo::info()
{
	return "lu";
}
