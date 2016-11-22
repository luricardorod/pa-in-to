#pragma once
#include <fstream>
using namespace std;

class CDibujable
{
public:
	virtual void Guardar(ofstream &salida) = 0;
	virtual void Cargar(ifstream &entrada) = 0;
	virtual int GetClsId() = 0;
	virtual void Dibujar() = 0;
};