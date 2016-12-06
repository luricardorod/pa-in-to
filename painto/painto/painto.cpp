#include "stdafx.h"
#include "cDocumento.h"
#include <iostream>
#include "cExplorador.h"
#include "cMouse.h"
#include "cInformacion.h"
#include "Modificadores.h"
#include "canvasSelect.h"
using namespace std;

int main()
{
	cDocumento canvas1;

	cCapa *CapaInicial;
	canvas1.Insertar();
	ifstream fIn;

	fIn.open("loquesea.txt");
	if (fIn.is_open())
	{
		canvas1.Cargar(fIn);
		fIn.close();
	}
	
	//---------------Esto es una ventana------------------//
	sf::RenderWindow window(sf::VideoMode(1024, 720), "Painto!", sf::Style::Close);
	//----------------------------------------------------//


	//--------------------Inicio de-----------------------//
	//---------------Cargado de texturas------------------//
	sf::Texture patoTextura;
	patoTextura.loadFromFile("Assets/pato8bit.png");

	sf::Texture textures[10];
	textures[0].loadFromFile("Assets/pointer.png");
	textures[1].loadFromFile("Assets/rectangle.png");
	textures[2].loadFromFile("Assets/roundedRectangle.png");
	textures[3].loadFromFile("Assets/elipse.png");
	textures[4].loadFromFile("Assets/triangle.png");
	textures[5].loadFromFile("Assets/polygon.png");
	textures[6].loadFromFile("Assets/bezierCurve.png");
	textures[7].loadFromFile("Assets/line.png");
	textures[8].loadFromFile("Assets/multilines.png");
	textures[9].loadFromFile("Assets/text.png");

	sf::Texture texturesModificadores[24];
	texturesModificadores[0].loadFromFile("Assets/arriba.png");
	texturesModificadores[1].loadFromFile("Assets/abajo.png");
	texturesModificadores[2].loadFromFile("Assets/derecha.png");
	texturesModificadores[3].loadFromFile("Assets/izquierda.png");
	texturesModificadores[4].loadFromFile("Assets/ExpandX.png");
	texturesModificadores[5].loadFromFile("Assets/ReduceX.png");
	texturesModificadores[6].loadFromFile("Assets/ExpandY.png");
	texturesModificadores[7].loadFromFile("Assets/ReduceY.png");
	texturesModificadores[8].loadFromFile("Assets/OutlineColor.png");
	texturesModificadores[9].loadFromFile("Assets/RGB1.png");
	texturesModificadores[10].loadFromFile("Assets/RGBabajo.png");
	texturesModificadores[11].loadFromFile("Assets/RGB3.png");
	texturesModificadores[12] = texturesModificadores[10];
	texturesModificadores[13].loadFromFile("Assets/RGB2.png");
	texturesModificadores[14] = texturesModificadores[10];
	texturesModificadores[15].loadFromFile("Assets/FillColor.png");
	texturesModificadores[16] = texturesModificadores[9];
	texturesModificadores[17] = texturesModificadores[10];
	texturesModificadores[18] = texturesModificadores[11];
	texturesModificadores[19] = texturesModificadores[10];
	texturesModificadores[20] = texturesModificadores[13];
	texturesModificadores[21] = texturesModificadores[10];
	texturesModificadores[22].loadFromFile("Assets/RGBarriba.png");
	texturesModificadores[23].loadFromFile("Assets/Save.png");
	
	//----------------------Fin de------------------------//
	//---------------Cargado de texturas------------------//


	//--------------------Inicio de-----------------------//
	//---------------Creacion y asignacion-----------------//
	//--------------------Sprites-------------------------//
	sf::Sprite patoSprite;
	patoSprite.setTexture(patoTextura);
	patoSprite.setPosition(0, 0);
	patoSprite.setScale((float)40 / 13, (float)40 / 12);
	sf::Sprite spriteBotones[10];
	for (int i = 0; i < 10; i++)
	{
		spriteBotones[i].setTexture(textures[i]);
		spriteBotones[i].setPosition(0, (20 * (i + 1)) + (i + 1) * 40);
		spriteBotones[i].setScale((float)40 / 200, (float)40 / 200);
	}

	sf::Sprite spriteBotonesModificadores[29];
	int counterButons = 22;
	for (int i = 0; i < 22; i++)
	{
		spriteBotonesModificadores[i].setTexture(texturesModificadores[i]);
		spriteBotonesModificadores[i].setPosition(40*(i+1), 0);
		spriteBotonesModificadores[i].setScale((float)40 / 200, (float)40 / 200);
		if (i == 10 || i == 12 || i == 14 || i == 17 || i == 19 || i == 21)
		{
			spriteBotonesModificadores[i].setPosition(40 * (i + 1) + 10, 0);
			spriteBotonesModificadores[counterButons].setTexture(texturesModificadores[22]);
			spriteBotonesModificadores[counterButons].setPosition(40 * (i + 1) +10, 20);
			spriteBotonesModificadores[counterButons].setScale((float)40 / 200, (float)40 / 200);
			counterButons++;
		}
	}
	spriteBotonesModificadores[28].setTexture(texturesModificadores[23]);
	spriteBotonesModificadores[28].setPosition(980, 0);
	spriteBotonesModificadores[28].setScale((float)40 / 200, (float)40 / 200);
	
	//----------------------Fin de------------------------//
	//---------------Creacion y aginacion-----------------//
	//--------------------Sprites-------------------------//


	//--------------------Inicio de-----------------------//
	//--------------------fondos UI-----------------------//
	//----------------------------------------------------//

	//Color de fondo de la app
	sf::Color UIBground = sf::Color(60, 60, 60, 255);
	//Color de fondo de las areas
	sf::Color colorBgroundUI = sf::Color(190, 190, 190, 255);
	//Color del borde de las areas
	sf::Color colorOutlineUI = sf::Color(50, 50, 50, 255);
	//Grosor del borde de las areas
	float lineThick = 2;

	sf::RectangleShape logoBground;
	logoBground.setSize(sf::Vector2f(40, 40));
	logoBground.setFillColor(sf::Color::Red);
	logoBground.setPosition(sf::Vector2f(0, 0));
	logoBground.setOutlineColor(colorOutlineUI);
	logoBground.setOutlineThickness(lineThick);

	sf::RectangleShape bground;
	bground.setSize(sf::Vector2f(1024, 720));
	bground.setFillColor(UIBground);
	bground.setPosition(sf::Vector2f(0, 0));

	sf::RectangleShape canvasBground;
	canvasBground.setSize(sf::Vector2f(720, 480	));
	canvasBground.setFillColor(sf::Color::White);
	canvasBground.setPosition(sf::Vector2f(97, 110));

	sf::RectangleShape modifiers;
	modifiers.setSize(sf::Vector2f(984, 40));
	modifiers.setFillColor(colorBgroundUI);
	modifiers.setPosition(sf::Vector2f(40, 0));
	modifiers.setOutlineColor(colorOutlineUI);
	modifiers.setOutlineThickness(lineThick);

	sf::RectangleShape tools;
	tools.setSize(sf::Vector2f(40, 620));
	tools.setFillColor(colorBgroundUI);
	tools.setPosition(sf::Vector2f(0, 40));
	tools.setOutlineColor(colorOutlineUI);
	tools.setOutlineThickness(lineThick);

	sf::RectangleShape layers;
	layers.setSize(sf::Vector2f(150, 620));
	layers.setFillColor(colorBgroundUI);
	layers.setPosition(sf::Vector2f(874, 40));
	layers.setOutlineColor(colorOutlineUI);
	layers.setOutlineThickness(lineThick);

	sf::RectangleShape data;
	data.setSize(sf::Vector2f(1024, 60));
	data.setFillColor(colorBgroundUI);
	data.setPosition(sf::Vector2f(0, 660));
	data.setOutlineColor(colorOutlineUI);
	data.setOutlineThickness(lineThick);
	//----------------------Fin de------------------------//
	//--------------------fondos UI-----------------------//
	//----------------------------------------------------//

	cMouse mousePointer; //La clase mas inutil de todas, no es para nada importante, el uso de esta clase requiere un terabyte de RAM
	//Esto es un mouse, tiene funciones que te dan la posicion del mouse respecto a la ventana
	//Tiene funciones que te devuelven el estado del clic izquierdo y derecho en forma de string
	//"Pressed"		El mouse acaba de ser presionado (dura un frame/instante)
	//"Down"		El mouse esta presionado
	//"Released";	El mouese acaba de dejar de ser presionado (dura un frame/instante)
	//"Up";			El mouse no esta siendo presionado


	window.setFramerateLimit(60); //Los usuarios de consola no podran creer que esta app tiene mas fps que sus juegos en consola.
	cExplorador chemonky(&canvas1, &window);
	cInformacion showInfo(&canvas1, &window);

	cFiguras *FiguraFlotante = NULL;

	Point pos1, pos2;

	bool falg1 = false;
	bool txtFlag = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::TextEntered && mousePointer.getAction() == 9 && txtFlag)
			{
				// Handle ASCII characters only
				if (event.text.unicode <= 31)
				{
					canvas1.capaActual->Insertar(FiguraFlotante);
					FiguraFlotante = NULL;
					txtFlag = false;
				}
				else if (event.text.unicode < 128)
				{
					((cTexto*)(FiguraFlotante))->texto += static_cast<char>(event.text.unicode);
				}
			}
		}

		//Actualizar informacion del mouse
		mousePointer.actualizarDatos(sf::Mouse::isButtonPressed(sf::Mouse::Left), sf::Mouse::isButtonPressed(sf::Mouse::Right), sf::Mouse::getPosition(window));

		//Si el mouse esta dentro del canvas
		if (canvasBground.getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
		{
			if (mousePointer.getLeftState() == "Pressed") //Si hizo clic izquierdo
			{
				if (mousePointer.getAction() == 0)
				{
					selectFigureCanvas(&canvas1, &window, mousePointer.getPosition().x, mousePointer.getPosition().y);
				}
				if (mousePointer.getAction() >= 1 && mousePointer.getAction() <= 5)
				{
					pos1.x = mousePointer.getPosition().x;
					pos1.y = mousePointer.getPosition().y;
				}
				if (mousePointer.getAction() == 6)
				{
					pos1.x = mousePointer.getPosition().x;
					pos1.y = mousePointer.getPosition().y;

					if (FiguraFlotante == NULL)
					{
						FiguraFlotante = new cCurvaBezier;
						((cCurvaBezier*)(FiguraFlotante))->adCosa(pos1);
					}
					else if (((cCurvaBezier*)(FiguraFlotante))->adCosa(pos1))
					{
						canvas1.capaActual->Insertar(FiguraFlotante);
						FiguraFlotante = NULL;
					}
				}
				if (mousePointer.getAction() == 7)
				{
					if (!falg1)
					{
						pos1.x = mousePointer.getPosition().x;
						pos1.y = mousePointer.getPosition().y;
						falg1 = true;
					}
					else
					{
						pos2.x = mousePointer.getPosition().x;
						pos2.y = mousePointer.getPosition().y;
						FiguraFlotante = new cLinea(pos1, pos2);
						canvas1.capaActual->Insertar(FiguraFlotante);
						FiguraFlotante = NULL;
						falg1 = false;
					}
				}
				if (mousePointer.getAction() == 8)
				{
					if (FiguraFlotante == NULL)
					{
						pos1.x = mousePointer.getPosition().x;
						pos1.y = mousePointer.getPosition().y;
						pos2.x = pos1.x;
						pos2.y = pos1.y;
						FiguraFlotante = new cTiraDeLinea;
						((cTiraDeLinea*)(FiguraFlotante))->addPointu(pos1);
					}
					else
					{
						pos1.x = mousePointer.getPosition().x;
						pos1.y = mousePointer.getPosition().y;
						if (sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2)) > 10)
						{
							((cTiraDeLinea*)(FiguraFlotante))->addPointu(pos1);
							pos2.x = pos1.x;
							pos2.y = pos1.y;
						}
						else
						{
							canvas1.capaActual->Insertar(FiguraFlotante);
							FiguraFlotante = NULL;
						}
					}
				}
				if (mousePointer.getAction() == 9)
				{
					pos1.x = mousePointer.getPosition().x;
					pos1.y = mousePointer.getPosition().y;
					txtFlag = true;
					FiguraFlotante = new cTexto(pos1, "");
				}
			}
			else if (mousePointer.getLeftState() == "Down") //Si el esta apretado
			{
				if (mousePointer.getAction() == 1)
				{
					pos2.x = mousePointer.getPosition().x;
					pos2.y = mousePointer.getPosition().y;

					FiguraFlotante = new cRectangulo(pos1, pos2);
				}
				else if (mousePointer.getAction() == 2)
				{
					pos2.x = mousePointer.getPosition().x;
					pos2.y = mousePointer.getPosition().y;

					FiguraFlotante = new cRectanguloRedondeado(pos1, pos2);
				}
				else if (mousePointer.getAction() == 3)
				{
					pos2.x = mousePointer.getPosition().x;
					pos2.y = mousePointer.getPosition().y;

					FiguraFlotante = new cElipse(pos1, pos2);
				}
				else if (mousePointer.getAction() == 4)
				{
					pos2.x = mousePointer.getPosition().x;
					pos2.y = mousePointer.getPosition().y;

					FiguraFlotante = new cTriangulo(pos1, pos2);
				}
				else if (mousePointer.getAction() == 5)
				{
					pos2.x = mousePointer.getPosition().x;
					pos2.y = mousePointer.getPosition().y;

					FiguraFlotante = new cPoligonos(pos1, pos2, 5);
				}
			}
			else if (mousePointer.getLeftState() == "Released") //Si el esta apretado
			{
				if (mousePointer.getAction() >= 1 && mousePointer.getAction() <= 5)
				{
					canvas1.capaActual->Insertar(FiguraFlotante);
					FiguraFlotante = NULL;
				}
			}
		}
		//Si el mouse esta dentro del area de layers
		else if (layers.getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
		{
			if (mousePointer.getLeftState() == "Pressed") //Si hizo clic izquierdo
			{
				//Codigo
				Point cordenadas;
				cordenadas.x = mousePointer.getPosition().x;
				cordenadas.y = mousePointer.getPosition().y;
				chemonky.checarClick(cordenadas);

			}
		}
		//Si el mouse esta dentro de la seccion de Tools
		else if (tools.getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
		{
			if (canvas1.capaActual != NULL)
			{
				if (mousePointer.getLeftState() == "Pressed") //Si hizo clic izquierdo
				{
					for (int i = 0; i < 10; i++) //Buscar a que "boton" le dio clic
					{
						if (spriteBotones[i].getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y)) {
							if (mousePointer.getAction() == 9)
							{
								if (txtFlag && ((cTexto*)(FiguraFlotante))->texto != "" )
								{
									canvas1.capaActual->Insertar(FiguraFlotante);
									FiguraFlotante = NULL;
									txtFlag = false;
								}
							}
							if (mousePointer.getAction() == 8)
							{
								if (FiguraFlotante != NULL && ((cTiraDeLinea*)(FiguraFlotante))->tamano > 1)
								{
									canvas1.capaActual->Insertar(FiguraFlotante);
									FiguraFlotante = NULL;
								}
							}
							mousePointer.setAction(i);
						}
					}
				}
			}
		}
		//Si el mouse esta dentro de el area de modificadores
		else if (modifiers.getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
		{
			if (mousePointer.getLeftState() == "Down") //Si hizo clic izquierdo
			{
				for (int i = 0; i < 28; i++)
				{
					if (spriteBotonesModificadores[i].getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
					{
						BotonActivado(i,&canvas1);
					}
				}
			}
			if (mousePointer.getLeftState() == "Released")
			{
				if (spriteBotonesModificadores[28].getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
				{
					BotonActivado(28, &canvas1);
				}
			}
		}

		window.clear();

		window.draw(bground);

		window.draw(canvasBground);
		/*Dibujar aqui todas las figuras*/
		canvas1.Dibujar(window);
		if (FiguraFlotante != NULL)
			FiguraFlotante->Dibujar(window);

		window.draw(layers);
		/*Dibujar aqui las capas*/
		chemonky.update();
		

		window.draw(tools);
		/*Dibujar aqui los botones de herramientas*/
		for(int i = 0; i < 10; i++)
			window.draw(spriteBotones[i]);

		window.draw(modifiers);
		/*Dibujar aqui los botones modificadores*/
		for (int i = 0; i < 29; i++)
			window.draw(spriteBotonesModificadores[i]);

		window.draw(data);
		/*Dibujar aqui los datos de la figura seleccionada*/
		showInfo.update();

		/*<No tocar esta parte del codigo>*/
		window.draw(logoBground);
		window.draw(patoSprite);
		/*</No tocar esta parte del codigo>*/

		window.display();
	}
    return 0;
}