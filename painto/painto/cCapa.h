#pragma once
#include "cSeleccionable.h"
#include <list>

#include "cRectangulo.h"
#include "cRectanguloRedondeado.h"
#include "cElipse.h"
#include "cTriangulo.h"
#include "cPoligonos.h"
#include "cCurvaBezier.h"
#include "cLinea.h"
#include "cTiraDeLinea.h"
#include "cTexto.h"

class cCapa:public cSeleccionable
{
public:
	list<cFiguras*> Figuras;
	wchar_t figuraActual;
public:
	cCapa();
	~cCapa();

	void Insertar();
	void Eliminar();
	void Subir();
	void Bajar();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar();
};