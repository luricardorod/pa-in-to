#include "stdafx.h"
#include "cElipse.h"


int cElipse::GetClsId()
{
	return ClsId_Elipse;
}
cElipse::cElipse()
{
}


cElipse::~cElipse()
{
}

void cElipse::Guardar(ofstream & salida)
{
	salida << radio1 << endl;
	salida << radio2 << endl;
}

void cElipse::Cargar(ifstream & entrada)
{
	entrada >> radio1;
	entrada >> radio2;
}