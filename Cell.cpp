#include "Cell.h"
//#include "Matrix.h"
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
	this->life = false;
}

bool Cell::isAlive()
{
	return this->life;
}

void Cell::setLife(bool l)
{
	this->life = l;
}

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

	if (id < a * (b - 1))
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


	//additional constraints regarding cylindric boundary conditions 

	/*if (id < a)
	{
		this->neighborsIDs.push_back(id + (a*(b - 1)));
		if (id%a != 0)
			this->neighborsIDs.push_back(id + (a*(b - 1)) - 1);
		if ((id + 1) % a != 0)
			this->neighborsIDs.push_back(id + (a*(b - 1)) + 1);
	}

	if (id >a*(b-1))
	{
		this->neighborsIDs.push_back(id - (a*(b - 1)));
		if (id%a != 0)
			this->neighborsIDs.push_back(id - (a*(b - 1)) - 1);
		if ((id + 1) % a != 0)
			this->neighborsIDs.push_back(id - (a*(b - 1)) + 1);
	}
	*/
}

const vector<int> Cell::getNeighbors()
{
	return this->neighborsIDs;
}

void Cell::showNeighbors()
{
	cout << endl;
	cout << "cell id: " << id << endl;
	cout << "cell life: " << isAlive() << endl;
	for (auto&i : this->neighborsIDs)
		cout << i << "\t";
	cout << endl;
}

int Cell::getNumOfNeighborsAlive(vector<Cell>n)
{
	int nA = 0;
	for (auto&i : neighborsIDs)
	{
		if (n[i].isAlive() == 1)
			nA++;
	}
	return nA;
}