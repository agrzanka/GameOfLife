#include "Cell.h"
#include "Board.h"

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
		this->cells.push_back(Cell(i));
	//cout << "cell no: " << cells[i].id << "\t";
}

void Board::update()
{
	cout << "updating" << endl;
	for (int i = 0; i < (a*b); i++)
	{

		cout << i << "\t" << cells[i].id << "\t" << cells[i].isAlive() << "\t";
		int nA = this->countNeighborsAlive(cells[i]);
		cout << nA << endl;

		if (cells[i].isAlive() == 0 && nA >= 3) {
			cells[i].setLife(true);
			cout << "\njust found someone to resurection!\t" << i << "\tnow cell id: " << cells[i].id << " is: " << cells[i].isAlive();
		}

		else if (cells[i].isAlive() && (nA > 3 || nA < 2))
			cells[i].setLife(false);
	}
}

void Board::show()
{
	cout << "\nBOARD:\n";
	for (int i = a - 1; i > -1; i--)
	{
		for (int j = 0; j < b; j++)
			cout << cells[i + j * a].isAlive() << "\t";
		//cout << i + j * a << "\t";		
		cout << endl;
	}
}

void Board::init(vector<int>alive)
{
	for (auto&i : alive)
		cells[i].setLife(true);
}

int Board::countNeighborsAlive(Cell c)
{
	cout << endl << "counting neighbors of: " << c.id << "\t";
	int nA = 0;
	//vector <int> neighbors = c.getNeighbors();
	//for (auto&n : c.neighborsIDs)
	//	cout << n << "\t";

	//tutaj poni¿ej coœ nie dzia³czy :(
	// NIE MA DOJŒCIA DO C.NEIGHBORSIDS!!! NIE ODCZYTUJ¥ SIÊ WARTOŒCI AT ALL!!! NIE MO¯NA WYJ¥Æ PO INDEXACH Z TEGO WEKTORA
	//OMG OMG OMG O NIE O NIE O NIEEEEEHEEEEHEEEEE :'(
	for (auto&i : c.neighborsIDs) {
		cout << "\nmy neighbors' lifes: " << i << ": " << cells[i].isAlive() << "\t";
		if (this->cells[i].isAlive() == 1)
			nA++;
	}

	cout << nA << endl;
	return nA;
}