#include "stdafx.h"
#include "canvasSelect.h"



void selectFigureCanvas(cDocumento* documento, sf::RenderWindow* win,float mousex, float mousey) {
	for (list<cCapa*>::iterator it = documento->Capas.begin(); it != documento->Capas.end(); it++)
	{
		if ((*it)->visible &&  (*it)->desbloqueado)
		{
			for (list<cFiguras*>::iterator figit = (*it)->Figuras.begin(); figit != (*it)->Figuras.end(); figit++)
			{
				if ((*figit)->visible && (*figit)->desbloqueado)
				{
					if ((*figit)->GetClsId() == 3)
					{
						Point mousese;
						mousese.x = mousex;
						mousese.y = mousey;
						if ((*figit)->hitTest(mousese))
						{
							documento->cambiarSeleccionado((*figit));
							return;
						}
					}
					else if ((*figit)->GetClsId() < 6)
					{
						if ((*figit)->infoFig->getGlobalBounds().contains(sf::Vector2f(mousex, mousey)))
						{
							documento->cambiarSeleccionado((*figit));
							return;
						}
					}
					else if ((*figit)->GetClsId() == 6)
					{

						sf::RectangleShape select;
						float pMayor = 0, pMenor = 720, pDer = 0, pIzq = 1080;
						for (int i = 0; i < ((cCurvaBezier*)((*figit)))->tamano; i++)
						{
							pMenor = ((cCurvaBezier*)((*figit)))->vertices[i].position.y < pMenor ? ((cCurvaBezier*)((*figit)))->vertices[i].position.y : pMenor;
							pMayor = ((cCurvaBezier*)((*figit)))->vertices[i].position.y > pMayor ? ((cCurvaBezier*)((*figit)))->vertices[i].position.y : pMayor;
							pDer = ((cCurvaBezier*)((*figit)))->vertices[i].position.x > pDer ? ((cCurvaBezier*)((*figit)))->vertices[i].position.x : pDer;
							pIzq = ((cCurvaBezier*)((*figit)))->vertices[i].position.x < pIzq ? ((cCurvaBezier*)((*figit)))->vertices[i].position.x : pIzq;
						}
						select.setSize(sf::Vector2f(pDer - pIzq, pMayor - pMenor));
						select.setPosition(sf::Vector2f(((pDer + pIzq) / 2) - ((pDer - pIzq) / 2), ((pMayor + pMenor) / 2) - ((pMayor - pMenor) / 2)));
						if (select.getGlobalBounds().contains(sf::Vector2f(mousex, mousey))) {
							documento->cambiarSeleccionado((*figit));
							return;
						}
					}
					else if ((*figit)->GetClsId() == 7)
					{
						sf::RectangleShape select;
						float pMayor = 0, pMenor = 720, pDer = 0, pIzq = 1080;
						for (int i = 0; i < ((cLinea*)((*figit)))->tamano; i++)
						{
							pMenor = ((cLinea*)((*figit)))->vertices[i].position.y < pMenor ? ((cLinea*)((*figit)))->vertices[i].position.y : pMenor;
							pMayor = ((cLinea*)((*figit)))->vertices[i].position.y > pMayor ? ((cLinea*)((*figit)))->vertices[i].position.y : pMayor;
							pDer = ((cLinea*)((*figit)))->vertices[i].position.x > pDer ? ((cLinea*)((*figit)))->vertices[i].position.x : pDer;
							pIzq = ((cLinea*)((*figit)))->vertices[i].position.x < pIzq ? ((cLinea*)((*figit)))->vertices[i].position.x : pIzq;
						}
						select.setSize(sf::Vector2f(pDer - pIzq, pMayor - pMenor));
						select.setPosition(sf::Vector2f(((pDer + pIzq) / 2) - ((pDer - pIzq) / 2), ((pMayor + pMenor) / 2) - ((pMayor - pMenor) / 2)));
						if (select.getGlobalBounds().contains(sf::Vector2f(mousex, mousey))) {
							documento->cambiarSeleccionado((*figit));
							return;
						}
					}
					else if ((*figit)->GetClsId() == 8)
					{

						sf::RectangleShape select;
						float pMayor = 0, pMenor = 720, pDer = 0, pIzq = 1080;
						for (int i = 0; i < ((cTiraDeLinea*)((*figit)))->tamano; i++)
						{
							pMenor = ((cTiraDeLinea*)((*figit)))->vertices[i].position.y < pMenor ? ((cTiraDeLinea*)((*figit)))->vertices[i].position.y : pMenor;
							pMayor = ((cTiraDeLinea*)((*figit)))->vertices[i].position.y > pMayor ? ((cTiraDeLinea*)((*figit)))->vertices[i].position.y : pMayor;
							pDer = ((cTiraDeLinea*)((*figit)))->vertices[i].position.x > pDer ? ((cTiraDeLinea*)((*figit)))->vertices[i].position.x : pDer;
							pIzq = ((cTiraDeLinea*)((*figit)))->vertices[i].position.x < pIzq ? ((cTiraDeLinea*)((*figit)))->vertices[i].position.x : pIzq;
						}
						select.setSize(sf::Vector2f(pDer - pIzq, pMayor - pMenor));
						select.setPosition(sf::Vector2f(((pDer + pIzq) / 2) - ((pDer - pIzq) / 2), ((pMayor + pMenor) / 2) - ((pMayor - pMenor) / 2)));
						if (select.getGlobalBounds().contains(sf::Vector2f(mousex, mousey))) {
							documento->cambiarSeleccionado((*figit));
							return;
						}
					}
					else if ((*figit)->GetClsId() == 9)
					{
						sf::RectangleShape select;
						select.setSize(sf::Vector2f(((cTexto*)((*figit)))->cajaTexto.getGlobalBounds().width, ((cTexto*)((*figit)))->cajaTexto.getGlobalBounds().height));
						select.setPosition(sf::Vector2f(((cTexto*)((*figit)))->cajaTexto.getGlobalBounds().left, ((cTexto*)((*figit)))->cajaTexto.getGlobalBounds().top));
						if (select.getGlobalBounds().contains(sf::Vector2f(mousex, mousey))) {
							documento->cambiarSeleccionado((*figit));
							return;
						}
					}					
				}
			}
		}
	}
}