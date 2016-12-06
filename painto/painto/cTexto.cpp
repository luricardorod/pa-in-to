#include "stdafx.h"
#include "cTexto.h"
#include <string>


int cTexto::GetClsId()
{
	return ClsId_Texto;
}
cTexto::cTexto(Point position, string tex)
{
	fuente;
	fuente.loadFromFile("comic.ttf");
	cajaTexto.setFont(fuente);
	cajaTexto.setCharacterSize(15);
	cajaTexto.setPosition(position.x, position.y);
	cajaTexto.setFillColor(sf::Color::Black);
	texto = tex;
}

cTexto::cTexto()
{
	fuente;
	fuente.loadFromFile("comic.ttf");
	cajaTexto.setFont(fuente);
	cajaTexto.setCharacterSize(15);
	cajaTexto.setPosition(640, 325);
	cajaTexto.setFillColor(sf::Color::Black);
	texto = "";
}


cTexto::~cTexto()
{

}

void cTexto::Dibujar(sf::RenderWindow &Ventana)
{
	
	cajaTexto.setString(texto);
	Ventana.draw(cajaTexto);
}

bool cTexto::hitTest(Point mouseCoords)
{
	return false;
}

void cTexto::Guardar(ofstream &salida)
{
	salida << p1.x << endl;
	salida << p1.y << endl;

	salida << p2.x << endl;
	salida << p2.y << endl;

	salida << p3.x << endl;
	salida << p3.y << endl;

	salida << p4.x << endl;
	salida << p4.y << endl;
}

void cTexto::Cargar(ifstream &entrada)
{
	/*
	entrada >> p1.x;
	entrada >> p1.y;

	entrada >> p2.x;
	entrada >> p2.y;

	entrada >> p3.x;
	entrada >> p3.y;

	entrada >> p4.x;
	entrada >> p4.y;
	*/

	string str;
	getline(entrada, str);
	p1.x = stof(str);
	getline(entrada, str);
	p1.y = stof(str);

	getline(entrada, str);
	p2.x = stof(str);
	getline(entrada, str);
	p2.y = stof(str);

	getline(entrada, str);
	p3.x = stof(str);
	getline(entrada, str);
	p3.y = stof(str);

	getline(entrada, str);
	p4.x = stof(str);
	getline(entrada, str);
	p4.y = stof(str);
}

string cTexto::info() {
	return "lu";
}

void cTexto::setMove(float x, float y)
{
	cajaTexto.setPosition(cajaTexto.getPosition() + sf::Vector2f(x, y));
}

void cTexto::setColor(sf::Color newColor)
{
	cajaTexto.setFillColor(newColor);
}

sf::Color cTexto::getColor()
{
	return cajaTexto.getFillColor();
}
