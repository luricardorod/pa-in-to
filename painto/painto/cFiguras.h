#pragma once
#include "cSeleccionable.h"

#define ClsId_Rectangulo 1
#define ClsId_RectanguloRedondeado 2
#define ClsId_Elipse 3
#define ClsId_Triangulo 4
#define ClsId_Poligono 5
#define ClsId_CurvaBezier 6
#define ClsId_Linea 7
#define ClsId_TiraDeLinea 8
#define ClsId_Texto 9

class cFiguras:public cSeleccionable
{
private:
	Vector3f colorRelleno;
	Vector3f colorLinea;
	Point posicion;
	long id_Nombre; // nombre o id unico de figura?
public:
	sf::Shape* infoFig;
	virtual void setColorLinea(Vector3f nuevoColor);
	Vector3f getColorLinea();
	virtual void setColorRelleno(Vector3f nuevoColor);
	Vector3f getColorRelleno();
	virtual void setPosicion(Point coordenadas);
	virtual Point getPosition();

	virtual string info() = 0;

	virtual void setMove(float x, float y);
	virtual void setColor(sf::Color newColor);
	virtual sf::Color getColor();

	virtual void setScale(float scaleX, float scaleY) {};

};