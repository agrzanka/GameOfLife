#pragma once
#include "Cell.h";

class Matrix
{
public:
	Cell cells[100];

	Matrix();
	void setUpMatrix(int arg[100]);
	void showMatrix();

};