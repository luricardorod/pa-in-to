#pragma once
#include "cDocumento.h"
#include "cSeleccionable.h"
#include "cFiguras.h"

class cCapa:cSeleccionable
{
public:
	std::list<cFiguras> Figuras;
	wchar_t figuraActual;
	bool bloqueado;
	bool visible;
	bool hitTest();
	void Insertar();
	void Eliminar();
	void Subir();
	void Bajar();
	cCapa();
	~cCapa();
};