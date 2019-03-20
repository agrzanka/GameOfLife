#include "Cell.h"
#include "Matrix.h"
#include <iostream>
#include<vector>
using namespace std;

Cell::Cell(int id)
{
	this->id = id;
	this->life = false;
}

Cell::Cell()
{
	this->id = NULL;
	this->life=false;
}

bool Cell :: isAlive()
{
	return this->life;
}

void Cell::updateCell(bool l)
{
	this->life = l;
}
/*int Cell::getNumOfNeighborsAlive()
{
	int nA = 0;
	for (auto&i : this.neighborsIDs)
	{
		if()
	}
	return nA;
}*/

/*void Cell::setNeighborsAlive(int n)
{
	this->neighborsAlive = n;
}*/
void Cell::setNeighbors(int a, int b)
{
	if (id >= a)
	{
		this->neighborsIDs.push_back(id - a);
		if (id%a != 0)
			this->neighborsIDs.push_back(id - a - 1);
		if ((id + 1) % a != 0)
			this->neighborsIDs.push_back(id - a + 1);
	}

	if (id <= a * (b - 1))
	{
		this->neighborsIDs.push_back(id + a);
		if (id%a != 0)
			this->neighborsIDs.push_back(id + a - 1);
		if ((id + 1) % a != 0)
			this->neighborsIDs.push_back(id + a + 1);
	}

	if (id%a != 0)
		this->neighborsIDs.push_back(id - 1);
	if ((id + 1) % a != 0)
		this->neighborsIDs.push_back(id + 1);

 }