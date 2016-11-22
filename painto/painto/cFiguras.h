#pragma once
#include "cSeleccionable.h"

#define ClsId_Rectangulo 1
#define ClsId_RectanguloRedondeado 2
#define ClsId_Elipse 3
#define ClsId_Triangulo 4
#define ClsId_Polignos 5
#define ClsId_CurvaBezier 6
#define ClsId_Linea 7
#define ClsId_TiraDeLinea 8
#define ClsId_Texto 9

#include "cRectangulo.h"
#include "cRectanguloRedondeado.h"
#include "cElipse.h"
#include "cTriangulo.h"
#include "cPoligonos.h"
#include "cCurvaBezier.h"
#include "cLinea.h"
#include "cTiraDeLinea.h"
#include "cTexto.h"

struct Vector3f
{
	float x; float y; float z;
};

struct Point
{
	float x; float y;
};

class cFiguras:public cSeleccionable
{
public:
	Vector3f colorRelleno;
	Vector3f colorLinea;
	Point posicion;
	long id_Nombre;
public:
	cFiguras();
	~cFiguras();

	virtual void setColorLinea(Vector3f nuevoColor) = 0;
	virtual Vector3f getColorLinea() = 0;

	virtual bool hitTest(Point mouseCoords) = 0;

	virtual void Guardar(ofstream &salida) = 0;
	virtual void Cargar(ifstream &entrada) = 0;
	virtual int GetClsId() = 0;
	virtual void Dibujar() = 0;
};