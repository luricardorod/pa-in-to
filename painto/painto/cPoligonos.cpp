#include "stdafx.h"
#include "cPoligonos.h"
#include <string>


int cPoligonos::GetClsId()
{
	return ClsId_Poligono;
}

void cPoligonos::Dibujar(sf::RenderWindow &Ventana)
{
	Ventana.draw(figura);
}

void cPoligonos::setPosicion(Point coordenadas)
{
	figura.setPosition(sf::Vector2f(coordenadas.x, coordenadas.y));
}

void cPoligonos::setColorLinea(Vector3f nuevoColor)
{
	figura.setOutlineColor(sf::Color(nuevoColor.x, nuevoColor.y, nuevoColor.z));
}

void cPoligonos::setColorRelleno(Vector3f nuevoColor)
{
	figura.setFillColor(sf::Color(nuevoColor.x, nuevoColor.y, nuevoColor.z));
}

cPoligonos::cPoligonos()
{

}

cPoligonos::cPoligonos(Point p1, Point p2, int lados)
{
	if (p2.x - p1.x > p2.y - p1.y)
		apotema = p2.x - p1.x;
	else
		apotema = p2.y - p1.y;

	figura.setPointCount(lados);
	numeroCaras = lados;
	for (int i = 0; i < lados; i++)
	{
		figura.setPoint(i, sf::Vector2f(apotema*sin((i*(360 / lados))*(Pi / 180)), apotema*-cos((i*(360 / lados))*(Pi / 180))));
	}

	figura.setPosition(p1.x, p1.y);
	figura.setOutlineThickness(2);
	figura.setOutlineColor(sf::Color::Black);
	infoFig = &figura;
}


cPoligonos::~cPoligonos()
{
}

bool cPoligonos::hitTest(Point mouseCoords)
{
	return false;
}

void cPoligonos::Guardar(ofstream &salida)
{
	salida << to_string(apotema) << endl;
	salida << to_string(numeroCaras) << endl;
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
}

void cPoligonos::Cargar(ifstream &entrada)
{
	string str;
	figura.setOutlineThickness(2);
	infoFig = &figura;
	sf::Color colortemp;
	sf::Vector2f posTemp;

	getline(entrada, str);
	apotema = stof(str);
	getline(entrada, str);
	numeroCaras = stof(str);
	figura.setPointCount(numeroCaras);
	for (int i = 0; i < numeroCaras; i++)
	{
		figura.setPoint(i, sf::Vector2f(apotema*sin((i*(360 / numeroCaras))*(Pi / 180)), apotema*-cos((i*(360 / numeroCaras))*(Pi / 180))));
	}

	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	figura.setOutlineColor(colortemp);

	getline(entrada, str);
	colortemp.r = stoul(str);
	getline(entrada, str);
	colortemp.g = stoul(str);
	getline(entrada, str);
	colortemp.b = stoul(str);
	figura.setFillColor(colortemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	figura.setPosition(posTemp);

	getline(entrada, str);
	posTemp.x = stof(str);
	getline(entrada, str);
	posTemp.y = stof(str);
	figura.setScale(posTemp);
}

string cPoligonos::info()
{
	return "lu";
}