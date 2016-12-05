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
	float apotema;

	if (p2.x - p1.x > p2.y - p1.y)
		apotema = p2.x - p1.x;
	else
		apotema = p2.y - p1.y;

	figura.setPointCount(lados);

	for (int i = 0; i < lados; i++)
	{
		figura.setPoint(i, sf::Vector2f(apotema*sin((i*(360 / lados))*(Pi / 180)), apotema*-cos((i*(360 / lados))*(Pi / 180))));
	}

	figura.setPosition(p1.x, p1.y);
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
	salida << listaPuntos.size() << endl;
	for (int i = 0; i < listaPuntos.size(); i++)
	{
		salida << listaPuntos[i].x << endl;
		salida << listaPuntos[i].y << endl;
	}
}

void cPoligonos::Cargar(ifstream &entrada)
{
	listaPuntos.clear();
	int sz;
	entrada >> sz;
	listaPuntos.resize(sz);
	for (int i = 0; i < listaPuntos.size(); i++)
	{
		string str;
		getline(entrada, str);
		listaPuntos[i].x = stof(str);
		getline(entrada, str);
		listaPuntos[i].y = stof(str);
	}
}

string cPoligonos::info()
{
	return "lu";
}