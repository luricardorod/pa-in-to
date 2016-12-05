#include "stdafx.h"
#include "Modificadores.h"
#include <iostream>

void BotonActivado(int boton, cDocumento* Documento)
{
	if (Documento->figuraActual == NULL || !Documento->figuraActual->desbloqueado)
		return;
	sf::Color ColorTemporal;

	switch (boton)
	{
	case 0:
		cout << "Mover arriba";
		break;
	case 1:
		cout << "Mover abajo";
		break;
	case 2:
		cout << "Mover derecha";
		break;
	case 3:
		cout << "Mover izquierda";
		break;
	case 4:
		cout << "Expandir izquierda";
		break;
	case 5:
		cout << "Expandir derecha";
		break;
	case 6:
		cout << "Expandir arriba";
		break;
	case 7:
		cout << "expandir abajo";
		break;
	case 8:
		cout << "Color Borde";
		break;
	case 9:
		cout << "Color Borde Red";
		break;
	case 10:

		ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
		if (ColorTemporal.r >= 255)
		{
			ColorTemporal.r = 255;
		}
		else
		{
			ColorTemporal.r += 5;
		}
		cout << ColorTemporal.r << endl;

		Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		break;
	case 11:
		cout << "Color borde azul";
		break;
	case 12:
		ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
		if (ColorTemporal.b >= 255)
		{
			ColorTemporal.b = 255;
		}
		else
		{
			ColorTemporal.b += 5;
		}
		Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		break;
	case 13:
		cout << "Color Borde Green";
		break;
	case 14:
		ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
		if (ColorTemporal.g >= 255)
		{
			ColorTemporal.g = 255;
		}
		else
		{
			ColorTemporal.g += 5;
		}
		Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		break;
	case 15:
		cout << "Color relleno";
		break;
	case 16:
		cout << "Color relleno Red";
		break;
	case 17:
		ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
		if (ColorTemporal.r >= 255)
		{
			ColorTemporal.r = 255;
		}
		else
		{
			ColorTemporal.r += 5;
		}
		Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		break;
	case 18:
		cout << "Color relleno azul";
		break;
	case 19:
		ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
		if (ColorTemporal.b >= 255)
		{
			ColorTemporal.b = 255;
		}
		else
		{
			ColorTemporal.b += 5;
		}
		Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		break;
	case 20:
		cout << "Color relleno verde";
		break;
	case 21:
		ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
		if (ColorTemporal.g >= 255)
		{
			ColorTemporal.g = 255;
		}
		else
		{
			ColorTemporal.g += 5;
		}
		Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		break;
	case 22:
		ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
		if (ColorTemporal.r <= 0)
		{
			ColorTemporal.r = 0;
		}
		else
		{
			ColorTemporal.r -= 5;
		}
		Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		break;
	case 23:
		ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
		if (ColorTemporal.b <= 0)
		{
			ColorTemporal.b = 0;
		}
		else
		{
			ColorTemporal.b -= 5;
		}
		Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		break;
	case 24:
		ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
		if (ColorTemporal.g <= 0)
		{
			ColorTemporal.g = 0;
		}
		else
		{
			ColorTemporal.g -= 5;
		}
		Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		break;
	case 25:
		ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
		if (ColorTemporal.r <= 0)
		{
			ColorTemporal.r = 0;
		}
		else
		{
			ColorTemporal.r -= 5;
		}
		Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		break;
	case 26:
		ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
		if (ColorTemporal.b <= 0)
		{
			ColorTemporal.b = 0;
		}
		else
		{
			ColorTemporal.b -= 5;
		}
		Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		break;
	case 27:
		ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
		if (ColorTemporal.g <= 0)
		{
			ColorTemporal.g = 0;
		}
		else
		{
			ColorTemporal.g -= 5;
		}
		Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		break;
	default:
		break;
	}
}