#pragma once
#include "Cell.h"
#include<iostream>

using namespace std;

class Board {
private:
	//vector<Cell>cells;

public:
	vector<Cell>cells;
	Board();
	Board(int a, int b);
	int a;
	int b;
	int numOfIterations;
	void update();
	void show();
	void init(vector<int>alive);
	void setup();
	int countNeighborsAlive(Cell c);
};
