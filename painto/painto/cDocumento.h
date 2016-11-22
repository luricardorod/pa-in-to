#pragma once
#include "CDibujable.h"
#include <list>
#include "cCapa.h"


class cDocumento:CDibujable
{
public:
	std::list<cCapa> Capas;
	long capaActual;
	void Subir();
	void Bajar();
	void Guardar();
	void Cargar();
	int GetClsId();
	void Insertar();
	void Eliminar();
	void Dibujar();
	cDocumento();
	~cDocumento();
};