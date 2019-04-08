#include "Cell.h"
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

	int tmp = (a - 1)*b; //to make less calculations 

	// if the cell is on the left boundary of the board
	if (id%b == 0)
	{
		this->neighborsIDs.push_back(id + 1);
		this->neighborsIDs.push_back(id + b - 1);

		if (id != 0) //is not a left-upper corner
		{
			this->neighborsIDs.push_back(id - b);
			this->neighborsIDs.push_back(id - b + 1);
		}

		if (id != tmp) //is not a left-bottom corner
		{
			this->neighborsIDs.push_back(id + b);
			this->neighborsIDs.push_back(id + b + 1);
			this->neighborsIDs.push_back(id + 2 * b - 1);
		}

		if (id != 0 && id != tmp) //is not a left-upper nor left-buttom corner 
		{
			this->neighborsIDs.push_back(id - 1);
		}
	}

	//if the cell is on the right boundary of the board
	else if ((id + 1) % b == 0)
	{
		this->neighborsIDs.push_back(id - 1);
		this->neighborsIDs.push_back(id - b + 1);

		if (id != (b - 1)) //is not a right-upper corner
		{
			this->neighborsIDs.push_back(id - b - 1);
			this->neighborsIDs.push_back(id - b);
			this->neighborsIDs.push_back(id - 2 * b + 1);
		}

		if (id != (a*b - 1)) //is not a right-bottom corner
		{
			this->neighborsIDs.push_back(id + b - 1);
			this->neighborsIDs.push_back(id + b);
			this->neighborsIDs.push_back(id + 1);
		}

		//if (id != (b - 1) && id != (a*b - 1)) //is not a right-upper nor right-bottom corner
		//{
		//	this->neighborsIDs.push_back(id - b + 1);
		//}
	}

	//if the cell is on the upper boundary of the board
	else if (id < b)
	{
		this->neighborsIDs.push_back(id + tmp);

		//if (id != 0) //is not a left-upper corner
		this->neighborsIDs.push_back(id + tmp - 1);

		//if (id != (b - 1)) //is not a right-upper corner
		this->neighborsIDs.push_back(id + tmp + 1);

		//if (id != 0 && id != (b - 1)) //is not a left-upper nor right-upper corner
		//{
		this->neighborsIDs.push_back(id - 1);
		this->neighborsIDs.push_back(id + 1);
		this->neighborsIDs.push_back(id + b - 1);
		this->neighborsIDs.push_back(id + b);
		this->neighborsIDs.push_back(id + b + 1);
		//}
	}

	//if the cell is on the bottom boundary of the board
	else if (id > (tmp - 1))
	{
		this->neighborsIDs.push_back(id - tmp);

		//if (id != tmp) //is not a left-bottom corner
		this->neighborsIDs.push_back(id - tmp - 1);

		//if (id != (a*b - 1)) //is not a right-bottom corner
		this->neighborsIDs.push_back(id - tmp + 1);

		//	if (id != tmp && id != (a*b - 1)) //is not a left-bottom nor right-bottom corner
		//	{
		this->neighborsIDs.push_back(id - 1);
		this->neighborsIDs.push_back(id + 1);
		this->neighborsIDs.push_back(id - b - 1);
		this->neighborsIDs.push_back(id - b);
		this->neighborsIDs.push_back(id - b + 1);
		//	}
	}

	//inner cells of the board
	else
	{
		this->neighborsIDs.push_back(id - 1);
		this->neighborsIDs.push_back(id + 1);
		this->neighborsIDs.push_back(id - b - 1);
		this->neighborsIDs.push_back(id - b);
		this->neighborsIDs.push_back(id - b + 1);
		this->neighborsIDs.push_back(id + b - 1);
		this->neighborsIDs.push_back(id + b);
		this->neighborsIDs.push_back(id + b + 1);
	}

	//if the cell is on the left-upper corner of the board
	if (id == 0)
	{
		this->neighborsIDs.push_back(id + a * b - 1);
		this->neighborsIDs.push_back(id + tmp + 1);

	}

	//if the cell is on the right-upper corner of the board
	if (id == (b - 1))
	{
		this->neighborsIDs.push_back(id + ((a - 2)*b) + 1);
		this->neighborsIDs.push_back(id + tmp - 1);
	}

	//if the cell is on the left-bottom corner of the board
	if (id == tmp)
	{
		this->neighborsIDs.push_back(id - ((a - 2)*b) - 1);
		this->neighborsIDs.push_back(id - tmp + 1);
	}

	//if the cell is on the right-bottom corner of the board
	if (id == (a*b - 1))
	{
		this->neighborsIDs.push_back(id - a * b + 1);
		this->neighborsIDs.push_back(id - tmp - 1);
	}
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