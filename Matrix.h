#pragma once
#include "Cell.h";

class Matrix
{
public:
	int a;
	int b;
	Cell cells[100];

	Matrix();
	
	void updateMatrix();
	int getNumOfAliveN(Cell c);
	void setUpMatrix(bool initialArgs[100]);
	void showMatrix();
};
