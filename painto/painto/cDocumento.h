#pragma once
#include "CDibujable.h"

class cDocumento:CDibujable
{
public:
	//list Capas;
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

