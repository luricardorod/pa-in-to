#pragma once
#include "cSeleccionable.h"
#include "cFiguras.h"
#include <list>

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