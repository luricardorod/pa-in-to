#pragma once
#include "cDocumento.h"
#include "cSeleccionable.h"

class cCapa:cSeleccionable
{
public:
	//list lista;
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

