#include "stdafx.h"
#include "Modificadores.h"
#include <iostream>

void BotonActivado(int boton, cDocumento* Documento)
{
	if (Documento->figuraActual == NULL || !Documento->figuraActual->desbloqueado)
		return;
	sf::Color ColorTemporal;
	sf::Vector2f PosicionTemporal;
	sf::Vector2f EscalaTemporal;
	ofstream fOut;
	switch (boton)
	{
	case 0:
		PosicionTemporal = Documento->figuraActual->infoFig->getPosition();

		if (PosicionTemporal.y <= 40)
		{
			return;
		}
		else
		{
			PosicionTemporal.y -= 5;
		}
		Documento->figuraActual->infoFig->setPosition(PosicionTemporal);
		break;
	case 1:
		PosicionTemporal = Documento->figuraActual->infoFig->getPosition();

		if (PosicionTemporal.y >= 660)
		{
			return;
		}
		else
		{
			PosicionTemporal.y += 5;
		}
		Documento->figuraActual->infoFig->setPosition(PosicionTemporal);
		break;
	case 2:
		PosicionTemporal = Documento->figuraActual->infoFig->getPosition();

		if (PosicionTemporal.x >= 615)
		{
			return;
		}
		else
		{
			PosicionTemporal.x += 5;
		}
		Documento->figuraActual->infoFig->setPosition(PosicionTemporal);
		break;
	case 3:
		PosicionTemporal = Documento->figuraActual->infoFig->getPosition();

		if (PosicionTemporal.x <= 97)
		{
			return;
		}
		else
		{
			PosicionTemporal.x -= 5;
		}
		Documento->figuraActual->infoFig->setPosition(PosicionTemporal);
		break;
	case 4:
		EscalaTemporal = Documento->figuraActual->infoFig->getScale();
		
		EscalaTemporal.x += 0.02f;
		Documento->figuraActual->infoFig->setScale(EscalaTemporal);
		break;
	case 5:
		EscalaTemporal = Documento->figuraActual->infoFig->getScale();

		EscalaTemporal.x -= 0.02f;
		Documento->figuraActual->infoFig->setScale(EscalaTemporal);
		break;
	case 6:
		EscalaTemporal = Documento->figuraActual->infoFig->getScale();

		EscalaTemporal.y += 0.02f;
		Documento->figuraActual->infoFig->setScale(EscalaTemporal);
		break;
	case 7:
		EscalaTemporal = Documento->figuraActual->infoFig->getScale();

		EscalaTemporal.y -= 0.02f;
		Documento->figuraActual->infoFig->setScale(EscalaTemporal);
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
		Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
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
	case 28:
		cout << "guardar" << endl;
		fOut.open("loquesea.txt", ios_base::out);
		if (fOut.is_open())
		{
			Documento->Guardar(fOut);
			fOut.close();
		}
		break;
	default:
		break;
	}
}