#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Cell
{
private:
	bool life;

public:
	Cell(int id);
	Cell();
	int id;
	vector<int> neighborsIDs;

	bool isAlive();
	void setNeighbors(int a, int b);
	const vector<int> getNeighbors();
	void setLife(bool l);

	void showNeighbors();

};
