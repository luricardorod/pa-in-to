#pragma once
#include "cDocumento.h"
#include "cSeleccionable.h"
#include "cFiguras.h"

class cCapa:public cSeleccionable
{
public:
	std::list<cFiguras> Figuras;
	wchar_t figuraActual;
	bool bloqueado;
	bool visible;
	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	bool hitTest();
	void Insertar();
	void Eliminar();
	void Subir();
	void Bajar();

	bool hitTest(Point mouseCoords);
	int GetClsId();
	void Dibujar();

	cCapa();
	~cCapa();
};