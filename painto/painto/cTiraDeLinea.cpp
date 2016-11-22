#include "stdafx.h"
#include "cTiraDeLinea.h"


int cTiraDeLinea::GetClsId()
{
	return ClsId_TiraDeLinea;
}
cTiraDeLinea::cTiraDeLinea()
{
}


cTiraDeLinea::~cTiraDeLinea()
{
}

void cTiraDeLinea::Guardar(ofstream & salida)
{
	salida << listaDePuntos.size() << endl;
	for (int i = 0; i < listaDePuntos.size(); i++)
	{
		salida << listaDePuntos[i].x << endl;
		salida << listaDePuntos[i].y << endl;
	}
}

void cTiraDeLinea::Cargar(ifstream & entrada)
{
	int sz;
	entrada >> sz;
	listaDePuntos.clear();
	listaDePuntos.resize(sz);
	for (int i = 0; i < listaDePuntos.size(); i++)
	{
		entrada >> listaDePuntos[i].x;
		entrada >> listaDePuntos[i].y;
	}
}