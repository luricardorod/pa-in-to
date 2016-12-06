#include "stdafx.h"
#include "Modificadores.h"

void BotonActivado(int boton, cDocumento* Documento)
{
	sf::Color ColorTemporal;
	sf::Vector2f PosicionTemporal;
	sf::Vector2f EscalaTemporal;
	ofstream fOut;
	if (boton == 28)
	{
		fOut.open("loquesea.txt", ios_base::out);
		if (fOut.is_open())
		{
			Documento->Guardar(fOut);
			fOut.close();
		}
		return;
	}
	
	if (Documento->figuraActual == NULL || !Documento->figuraActual->desbloqueado)
		return;
	bool linea = (Documento->figuraActual->GetClsId() >= 6 && Documento->figuraActual->GetClsId() <= 8);
	bool txt = (Documento->figuraActual->GetClsId() == 9);
	
	switch (boton)
	{
	case 0:
		if (!linea && !txt && !txt)
		{
			PosicionTemporal = Documento->figuraActual->infoFig->getPosition();

			PosicionTemporal.y -= 5;
			Documento->figuraActual->infoFig->setPosition(PosicionTemporal);
		}
		else
		{
			Documento->figuraActual->setMove(0, -5);
		}
		break;
	case 1:
		if (!linea && !txt && !txt)
		{
			PosicionTemporal = Documento->figuraActual->infoFig->getPosition();

			PosicionTemporal.y += 5;
			Documento->figuraActual->infoFig->setPosition(PosicionTemporal);
		}
		else
		{
			Documento->figuraActual->setMove(0, 5);
		}
		break;
	case 2:
		if (!linea && !txt && !txt)
		{
			PosicionTemporal = Documento->figuraActual->infoFig->getPosition();
			
			PosicionTemporal.x += 5;
			Documento->figuraActual->infoFig->setPosition(PosicionTemporal);
		}
		else
		{
			Documento->figuraActual->setMove(5, 0);
		}
		break;
	case 3:
		if (!linea && !txt)
		{
			PosicionTemporal = Documento->figuraActual->infoFig->getPosition();

			PosicionTemporal.x -= 5;
			Documento->figuraActual->infoFig->setPosition(PosicionTemporal);
		}
		else
		{
			Documento->figuraActual->setMove(-5, 0);
		}
		break;
	case 4:
		if (!linea && !txt)
		{
			EscalaTemporal = Documento->figuraActual->infoFig->getScale();
		
			EscalaTemporal.x += 0.02f;
			Documento->figuraActual->infoFig->setScale(EscalaTemporal);
		}
		else if (txt)
		{
			Documento->figuraActual->setScale(0.02f,0);
		}
		break;
	case 5:
		if (!linea && !txt)
		{
			EscalaTemporal = Documento->figuraActual->infoFig->getScale();

			EscalaTemporal.x -= 0.02f;
			Documento->figuraActual->infoFig->setScale(EscalaTemporal);
		}
		else if (txt)
		{
			Documento->figuraActual->setScale(-0.02f, 0);
		}
		break;
	case 6:
		if (!linea && !txt)
		{
			EscalaTemporal = Documento->figuraActual->infoFig->getScale();

			EscalaTemporal.y += 0.02f;
			Documento->figuraActual->infoFig->setScale(EscalaTemporal);
		}
		else if (txt)
		{
			Documento->figuraActual->setScale(0, 0.02f);
		}
		break;
	case 7:
		if (!linea && !txt)
		{
			EscalaTemporal = Documento->figuraActual->infoFig->getScale();

			EscalaTemporal.y -= 0.02f;
			Documento->figuraActual->infoFig->setScale(EscalaTemporal);
		}
		else if (txt)
		{
			Documento->figuraActual->setScale(0, -0.02f);
		}
		break;
	case 10:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
			if (ColorTemporal.r >= 255)
				ColorTemporal.r = 255;
			else
				ColorTemporal.r += 5;
			Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		}
		else
		{
			ColorTemporal = Documento->figuraActual->getColor();
			if (ColorTemporal.r >= 255)
				ColorTemporal.r = 255;
			else
				ColorTemporal.r += 5;
			Documento->figuraActual->setColor(ColorTemporal);
		}
		break;
	case 12:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
			if (ColorTemporal.b >= 255)
				ColorTemporal.b = 255;
			else
				ColorTemporal.b += 5;
			Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		}
		else
		{
			ColorTemporal = Documento->figuraActual->getColor();
			if (ColorTemporal.b >= 255)
				ColorTemporal.b = 255;
			else
				ColorTemporal.b += 5;
			Documento->figuraActual->setColor(ColorTemporal);
		}
		break;
	case 14:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
			if (ColorTemporal.g >= 255)
				ColorTemporal.g = 255;
			else
				ColorTemporal.g += 5;
			Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		}
		else
		{
			ColorTemporal = Documento->figuraActual->getColor();
			if (ColorTemporal.g >= 255)
				ColorTemporal.g = 255;
			else
				ColorTemporal.g += 5;
			Documento->figuraActual->setColor(ColorTemporal);
		}
		break;
	case 17:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
			if (ColorTemporal.r >= 255)
				ColorTemporal.r = 255;
			else
				ColorTemporal.r += 5;
			Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		}
		break;
	case 19:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
			if (ColorTemporal.b >= 255)
				ColorTemporal.b = 255;
			else
				ColorTemporal.b += 5;
			Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		}
		break;
	case 21:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
			if (ColorTemporal.g >= 255)
				ColorTemporal.g = 255;
			else
				ColorTemporal.g += 5;
			Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		}
		break;
	case 22:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
			if (ColorTemporal.r <= 0)
				ColorTemporal.r = 0;
			else
				ColorTemporal.r -= 5;
			Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		}
		else
		{
			ColorTemporal = Documento->figuraActual->getColor();
			if (ColorTemporal.r <= 0)
				ColorTemporal.r = 0;
			else
				ColorTemporal.r -= 5;
			Documento->figuraActual->setColor(ColorTemporal);
		}
		break;
	case 23:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
			if (ColorTemporal.b <= 0)
				ColorTemporal.b = 0;
			else
				ColorTemporal.b -= 5;
			Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		}
		else
		{
			ColorTemporal = Documento->figuraActual->getColor();
			if (ColorTemporal.b <= 0)
				ColorTemporal.b = 0;
			else
				ColorTemporal.b -= 5;
			Documento->figuraActual->setColor(ColorTemporal);
		}
		break;
	case 24:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getOutlineColor();
			if (ColorTemporal.g <= 0)
				ColorTemporal.g = 0;
			else
				ColorTemporal.g -= 5;
			Documento->figuraActual->infoFig->setOutlineColor(ColorTemporal);
		}
		else
		{
			ColorTemporal = Documento->figuraActual->getColor();
			if (ColorTemporal.g <= 0)
				ColorTemporal.g = 0;
			else
				ColorTemporal.g -= 5;
			Documento->figuraActual->setColor(ColorTemporal);
		}
		break;
	case 25:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
			if (ColorTemporal.r <= 0)
				ColorTemporal.r = 0;
			else
				ColorTemporal.r -= 5;
			Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		}
		break;
	case 26:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
			if (ColorTemporal.b <= 0)
				ColorTemporal.b = 0;
			else
				ColorTemporal.b -= 5;
			Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		}
		break;
	case 27:
		if (!linea && !txt)
		{
			ColorTemporal = Documento->figuraActual->infoFig->getFillColor();
			if (ColorTemporal.g <= 0)
				ColorTemporal.g = 0;
			else
				ColorTemporal.g -= 5;
			Documento->figuraActual->infoFig->setFillColor(ColorTemporal);
		}
		break;
	default:
		break;
	}
}