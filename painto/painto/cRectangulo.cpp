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
	Rectangulo.setOrigin(Rectangulo.getSize().x / 2, Rectangulo.getSize().y / 2);

	Point fixedPosition;
	fixedPosition.x = (p1.x + p2.x) / 2.0f;
	fixedPosition.y = (p1.y + p2.y) / 2.0f;
	setPosicion(fixedPosition);

	Rectangulo.setPosition((p1.x + p2.x) / 2.0f, (p1.y + p2.y) / 2.0f);

	getColorLinea();
	sf::Color colorin;
	colorin.r = getColorLinea().x;
	colorin.g = getColorLinea().y;
	colorin.b = getColorLinea().z;
	colorin.a = 255;

	Rectangulo.setOutlineThickness(2);
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
	salida << to_string(Rectangulo.getSize().x) << endl;
	salida << to_string(Rectangulo.getSize().y) << endl;
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
};

void cRectangulo::Cargar(ifstream &entrada)
{
	string str;
	Rectangulo.setOutlineThickness(2);
	infoFig = &Rectangulo;
	sf::Color colortemp;
	sf::Vector2f posTemp;

	getline(entrada, str);
	base = stof(str);
	getline(entrada, str);
	altura = stof(str);
	Rectangulo.setSize(sf::Vector2f(base, altura));
	Rectangulo.setOrigin(Rectangulo.getSize().x / 2, Rectangulo.getSize().y / 2);

	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	Rectangulo.setOutlineColor(colortemp);

	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	Rectangulo.setFillColor(colortemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	Rectangulo.setPosition(posTemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	Rectangulo.setScale(posTemp);

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
