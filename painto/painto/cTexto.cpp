#include "stdafx.h"
#include "cTexto.h"
#include <string>
#include<iostream>


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
	salida << texto << endl;
	salida << to_string(cajaTexto.getFillColor().r) << endl;
	salida << to_string(cajaTexto.getFillColor().g) << endl;
	salida << to_string(cajaTexto.getFillColor().b) << endl;
	salida << to_string(cajaTexto.getPosition().x) << endl;
	salida << to_string(cajaTexto.getPosition().y) << endl;
	salida << to_string(cajaTexto.getScale().x) << endl;
	salida << to_string(cajaTexto.getScale().y) << endl;
}

void cTexto::Cargar(ifstream &entrada)
{
	string str;
	sf::Color colortemp;
	sf::Vector2f posTemp;

	getline(entrada, str);
	texto = str;

	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	cajaTexto.setFillColor(colortemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	cajaTexto.setPosition(posTemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	cajaTexto.setScale(posTemp);
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

void cTexto::setScale(float scaleX, float scaleY) {
	cajaTexto.setScale(cajaTexto.getScale() + sf::Vector2f(scaleX, scaleY));
}

sf::Color cTexto::getColor()
{
	return cajaTexto.getFillColor();
}
