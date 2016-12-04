#include "stdafx.h"
#include "cDocumento.h"
#include <string>

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
	Capas.push_back(new cCapa());
	capaActual = Capas.back();
	capaActual->nombre = "Capa " + to_string(contador);
	figuraActual = NULL;
	contador++;
}

void cDocumento::Eliminar()
{
	capaActual->Figuras.clear();
	Capas.remove(capaActual);

}

void cDocumento::Guardar(ofstream &salida)
{
	salida << Capas.size() << endl;
	for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
	{
		(*it)->Guardar(salida);
	}
}

void cDocumento::Cargar(ifstream &entrada)
{
	int sz;
	string str;
	getline(entrada, str);
	
	sz = stoi(str);
	
	Capas.clear();
	while (Capas.size() < sz)
	{
		Insertar();
		Capas.back()->Cargar(entrada);
	}
	capaActual = Capas.back();
	figuraActual = capaActual->Figuras.front();
}

int cDocumento::GetClsId()
{
	return 0;
}

void cDocumento::Dibujar(sf::RenderWindow &Ventana)
{
	for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
		(*it)->Dibujar(Ventana);
}

void cDocumento::cambiarSeleccionado(cSeleccionable * nuevaSeleccion)
{
	int tipo = nuevaSeleccion->GetClsId();
	if (tipo == 0)
	{
		capaActual = ((cCapa*)(nuevaSeleccion));
		figuraActual = NULL;
	}
	else {
		figuraActual = ((cFiguras*)(nuevaSeleccion));
		for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); it++)
		{
			for (list<cFiguras*>::iterator figit = (*it)->Figuras.begin(); figit != (*it)->Figuras.end(); figit++)
			{
				if ((*figit) == figuraActual)
				{
					capaActual = (*it);
					return;
				}
			}
		}
	}
}
