#include "Cell.h"
#include "Board.h"
#include <algorithm>

Board::Board()
{
	this->a = 1;
	this->b = 1;
	this->setup();
}

Board::Board(int a, int b)
{
	this->a = a;
	this->b = b;
	this->setup();
}

void Board::setup()
{
	for (int i = 0; i < (a*b); i++)
	{
		this->cells.push_back(Cell(i));
	}

	for (auto&c : cells)
		c.setNeighbors(this->a, this->b);
}

void Board::update()
{
	vector<int>nextRoundAlive;
	vector<int>nextRoundDead;

	for (auto&c : cells)
	{
		vector<int>neighbourhood;
		int nA = 0;

		neighbourhood = c.getNeighbors();

		for (auto&i : neighbourhood)
			if (cells[i].isAlive() == 1)
				nA++;

		if (c.isAlive() == 0 && nA == 3)
			nextRoundAlive.push_back(c.id);

		else if (c.isAlive() && (nA > 3 || nA < 2))
			nextRoundDead.push_back(c.id);
	}

	for (auto&c : cells)
	{
		if (find(nextRoundAlive.begin(), nextRoundAlive.end(), c.id) != nextRoundAlive.end())
			c.setLife(true);
		else if (find(nextRoundDead.begin(), nextRoundDead.end(), c.id) != nextRoundDead.end())
			c.setLife(false);
	}
}

void Board::show()
{
	cout << "\nBOARD:\n";
	/*for (int i = 0; i < a ; i++)
	{
		for (int j = 0; j < b; j++)
			cout << cells[j + i * b].id << "\t";
		cout << endl;
	}*/
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			cout << cells[j + i * b].isAlive();
		cout << endl;
	}
	/*cout << "\n0:\n";
	this->cells[0].showNeighbors();
	cout << "\n2:\n";
	this->cells[2].showNeighbors();
	cout << "\n3:\n";
	this->cells[3].showNeighbors();
	cout << "\n4:\n";
	this->cells[4].showNeighbors();
	cout << "\n14:\n";
	this->cells[14].showNeighbors();
	cout << "\n39:\n";
	this->cells[39].showNeighbors();
	cout << "\n38:\n";
	this->cells[38].showNeighbors();
	cout << "\n35:\n";
	this->cells[35].showNeighbors();
	cout << "\n15:\n";
	this->cells[15].showNeighbors();*/

}

void Board::init(vector<int>alive)
{
	for (auto&i : alive)
		cells[i].setLife(true);
}