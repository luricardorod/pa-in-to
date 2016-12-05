#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
using namespace std;

class cMouse
{
private:
	sf::Vector2i mouseCords;

	bool mouseLeftFlag = false;
	bool mouseRightFlag = false;
	string mouseLeftState = "Up";
	string mouseRightState = "Up";

	int action = 1;
public:
	cMouse();
	~cMouse();
	void actualizarDatos(bool leftClic, bool rightClic, sf::Vector2i pos);
	string getLeftState();
	string getRightState();
	sf::Vector2i getPosition();
	int getAction();
	void setAction(int ActionManVsMaxSteel);
};