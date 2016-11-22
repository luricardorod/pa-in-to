#include "stdafx.h"
#include "cDocumento.h"

cDocumento::cDocumento()
{

}

cDocumento::~cDocumento()
{

}

void cDocumento::Subir()
{

}

void cDocumento::Bajar()
{

}

void cDocumento::Insertar()
{

}

void cDocumento::Eliminar()
{

}

void cDocumento::Guardar(ofstream &salida)
{
	salida << Capas.size() << endl;
	for (std::list<cCapa>::iterator it = Capas.begin(); it != Capas.end(); ++it)
	{
		(*it).Guardar(salida);
	}
}

void cDocumento::Cargar(ifstream &entrada)
{
	int sz;
	entrada >> sz;

	Capas.clear();

	Capas.resize(sz);
	while (Capas.size() < sz)
	{
		Capas.push_back(cCapa());
		Capas.back().Cargar(entrada);
	}
}

int cDocumento::GetClsId()
{
	return 0;
}

void cDocumento::Dibujar()
{

}