#include "stdafx.h"
#include "cMouse.h"

cMouse::cMouse()
{

}

cMouse::~cMouse()
{

}
void cMouse::actualizarDatos(bool leftClic, bool rightClic, sf::Vector2i pos)
{
	mouseCords = pos;

	if (leftClic && !mouseLeftFlag)
	{
		mouseLeftFlag = true;
		mouseLeftState = "Pressed";
	}
	else if (leftClic && mouseLeftFlag)
	{
		mouseLeftFlag = true;
		mouseLeftState = "Down";
	}
	else if (!leftClic && mouseLeftFlag)
	{
		mouseLeftFlag = false;
		mouseLeftState = "Released";
	}
	else if (!leftClic && !mouseLeftFlag)
	{
		mouseLeftFlag = false;
		mouseLeftState = "Up";
	}

	if (rightClic && !mouseRightFlag)
	{
		mouseRightFlag = true;
		mouseRightState = "Pressed";
	}
	else if (rightClic && mouseRightFlag)
	{
		mouseRightFlag = true;
		mouseRightState = "Down";
	}
	else if (!rightClic && mouseRightFlag)
	{
		mouseRightFlag = false;
		mouseRightState = "Released";
	}
	else if (!rightClic && !mouseRightFlag)
	{
		mouseRightFlag = false;
		mouseRightState = "Up";
	}
}

string cMouse::getLeftState()
{
	return mouseLeftState;
}

string cMouse::getRightState()
{
	return mouseRightState;
}

sf::Vector2i cMouse::getPosition()
{
	return mouseCords;
}

int cMouse::getAction()
{
	return action;
}

void cMouse::setAction(int ActionManVsMaxSteel)
{
	action = ActionManVsMaxSteel;
}
