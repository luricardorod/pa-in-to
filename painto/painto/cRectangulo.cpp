#include "stdafx.h"
#include "cRectangulo.h"
#include <string>

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

	Rectangulo.setPosition(getPosition().x, getPosition().y);

	getColorLinea();
	sf::Color colorin;
	colorin.r = getColorLinea().x;
	colorin.g = getColorLinea().y;
	colorin.b = getColorLinea().z;
	colorin.a = getColorLinea().z;

	Rectangulo.setOutlineColor(colorin);
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
	/*
	int i = 0;
	while (!entrada.eof())
	{
		if (i == 1)
		{
			float n;
			entrada >> n;
			base = n;
		}
		if (i == 2)
		{
			float n;
			entrada >> n;
			altura = n;
			break;
		}
		i++;
	}
	*/
	string str;
	getline(entrada, str);
	base = stof(str);
	getline(entrada, str);
	altura = stof(str);
};

int cRectangulo::GetClsId()
{
	return ClsId_Rectangulo;
};

void cRectangulo::Dibujar(sf::RenderWindow &Ventana)
{

};