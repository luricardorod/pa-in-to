#include "stdafx.h"
#include "cDocumento.h"

void cDocumento::Bajar()
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

void cDocumento::Dibujar()
{

}
void cDocumento::Eliminar()
{

}
int cDocumento::GetClsId()
{
	return 0;
}

void cDocumento::Insertar()
{

}
void cDocumento::Subir()
{

}
cDocumento::cDocumento()
{
}


cDocumento::~cDocumento()
{
}
