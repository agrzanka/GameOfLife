#pragma once

#include "Cell.h";

class Matrix
{
public:
	int a;
	int b;
	Cell cells[10][10];

	Matrix();

	void updateMatrix();
	int getNumOfAliveN(Cell c);
	
	void setUpMatrix(bool initialArgs[][10]);
	void showMatrix();
};
