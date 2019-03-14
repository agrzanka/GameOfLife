#include "Cell.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

Cell::Cell(int x, int y)
{
	this->x = x;
	this->y = y;
	this->updateCell(0);
	// this.life=false;
}

Cell::Cell()
{
	this->x = NULL;
	this->y = NULL;
	this->updateCell(0);
	// this.life=false;
}

//void Cell::getNumOfNeighbors()
bool Cell :: isAlive()
{
	return this->life;
}

void Cell::updateCell(bool l)
{
	this->life = l;
}
int Cell::getNeighborsAlive()
{
	return this->neighborsAlive;
}

void Cell::setNeighborsAlive(int n)
{
	this->neighborsAlive = n;
}
