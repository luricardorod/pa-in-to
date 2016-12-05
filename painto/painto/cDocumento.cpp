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
	int counter = 0;
	if (capaActual == Capas.front())
	{
		return;
	}
	for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
	{
		if ((*it)== capaActual)
		{
			list<cCapa*>::iterator lu = Capas.begin();
			advance(lu, counter-1);
			Capas.splice(lu, Capas, it);
			return;
		}
		counter++;
	}
}
void cDocumento::SubirFigura()
{
	int counter = 0;
	if (figuraActual == capaActual->Figuras.front())
	{
		if (capaActual == Capas.front())
		{
			return;
		}
		else
		{
			for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
			{
				if ((*it) == capaActual)
				{
					list<cCapa*>::iterator lu = Capas.begin();
					advance(lu, counter - 1);
					(*lu)->Figuras.splice((*lu)->Figuras.end(), capaActual->Figuras, capaActual->Figuras.begin());
					capaActual = (*lu);
					return;
				}
				counter++;
			}
		}
	}
	else
	{
		for (list<cFiguras*>::iterator it = capaActual->Figuras.begin(); it != capaActual->Figuras.end(); ++it)
		{
			if ((*it) == figuraActual)
			{
				list<cFiguras*>::iterator lu = capaActual->Figuras.begin();
				advance(lu, counter - 1);
				capaActual->Figuras.splice(lu, capaActual->Figuras, it);
				return;
			}
			counter++;
		}
	}

}

void cDocumento::BajarFigura()
{
	int counter = 0;
	if (figuraActual == capaActual->Figuras.back())
	{
		if (capaActual == Capas.back())
		{
			return;
		}
		else
		{
			for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
			{
				if ((*it) == capaActual)
				{
					list<cCapa*>::iterator lu = Capas.begin();
					advance(lu, counter + 1);
					list<cFiguras*>::iterator lol = capaActual->Figuras.end();
					lol--;
					(*lu)->Figuras.splice((*lu)->Figuras.begin(), capaActual->Figuras, lol);
					capaActual = (*lu);
					return;
				}
				counter++;
			}
		}
	}
	else
	{
		for (list<cFiguras*>::iterator it = capaActual->Figuras.begin(); it != capaActual->Figuras.end(); ++it)
		{
			if ((*it) == figuraActual)
			{
				list<cFiguras*>::iterator lu = capaActual->Figuras.begin();
				advance(lu, counter + 2);
				capaActual->Figuras.splice(lu, capaActual->Figuras, it);
				return;
			}
			counter++;
		}
	}

}

void cDocumento::Bajar()
{
	int counter = 0;
	if (capaActual == Capas.back())
	{
		return;
	}
	for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
	{
		if ((*it) == capaActual)
		{
			list<cCapa*>::iterator lu = Capas.begin();
			advance(lu, counter + 2);
			Capas.splice(lu, Capas, it);
			return;
		}
		counter++;
	}
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
	{
		if((*it)->visible)
			(*it)->Dibujar(Ventana);
	}
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
