#pragma once
class CDibujable
{
public:
	virtual void Guardar() = 0;
	virtual void Cargar() = 0;
	virtual int GetClsId() = 0;
	virtual void Dibujar() = 0;
};

