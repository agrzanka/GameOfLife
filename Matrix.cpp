#include "Cell.h"
#include "Matrix.h"

#include <iostream>

Matrix::Matrix()
{
	this->a = 10;
	this->b = 10;
	//bool initialArgs[10][10];
	//this.setUpMatrix(initialArgs);
	//this.setUpMatrix();
	for (int i = 0; i<a; i++)
	{
		for (int j = 0; j<b; j++)
			cells[i][j] = Cell(i, j);
	}
	this->showMatrix();
}

void Matrix::setUpMatrix(bool initialArgs[][10])
{
	for (int i = 0; i<this->a; i++)
	{
		for (int j = 0; j<this->b; j++)
		{
			cells[i][j].updateCell(initialArgs[i][j]);
		}
	}

	for (int i = 0; i<this->a; i++)
	{
		for (int j = 0; j<this->b; j++)
		{
			this->getNumOfAliveN(cells[i][j]);
		}
	}

}

void Matrix::updateMatrix()
{
	for (int i = 0; i<this->a; i++)
	{
		for (int j = 0; j<this->b; j++)
		{
			if (!cells[i][j].isAlive() && cells[i][j].getNeighborsAlive() >= 3)
				cells[i][j].updateCell(true);
			else if (cells[i][j].isAlive() && (cells[i][j].getNeighborsAlive()>3 || cells[i][j].getNeighborsAlive()<2))
				cells[i][j].updateCell(false);
		}
	}
	for (int i = 0; i<this->a; i++)
	{
		for (int j = 0; j<this->b; j++)
		{
			this->getNumOfAliveN(cells[i][j]);
		}
	}
}

int Matrix::getNumOfAliveN(Cell c)
{
	int x = c.x;
	int y = c.y;
	int neighbors = 0;
	for (int i = x - 1; i<x + 2; i++)
	{
		for (int j = y - 1; y<y + 2; y++)
		{
			if (i<0 || i>a || j<0 || j>b)
				break;
			else if (cells[i][j].isAlive())
				neighbors++;
		}
	}
	c.setNeighborsAlive(neighbors);
	return neighbors;
}

void Matrix::showMatrix()
{
	std::cout << "\nmatrix: \n";
	for (int i = 0; i<this->a; i++)
	{
		for (int j = 0; j<this->b; j++)
		{
			std::cout << cells[i][j].isAlive() << "\t";
		}
		std::cout << "\n";
	}

}
