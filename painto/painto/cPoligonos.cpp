#include "stdafx.h"
#include "cPoligonos.h"


int cPoligonos::GetClsId()
{
	return ClsId_Polignos;
}
cPoligonos::cPoligonos()
{
}


cPoligonos::~cPoligonos()
{
}

void cPoligonos::Guardar(ofstream & salida)
{
	salida << listaPuntos.size() << endl;
	for (int i = 0; i < listaPuntos.size(); i++)
	{
		salida << listaPuntos[i].x << endl;
		salida << listaPuntos[i].y << endl;
	}
}

void cPoligonos::Cargar(ifstream & entrada)
{
	listaPuntos.clear();
	int sz;
	entrada >> sz;
	listaPuntos.resize(sz);
	for (int i = 0; i < listaPuntos.size(); i++)
	{
		entrada >> listaPuntos[i].x;
		entrada >> listaPuntos[i].y;
	}
}