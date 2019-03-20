#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Cell
{
private:
	bool life;
	//vector<int> neighborsIDs;
public:
	Cell(int id);
	Cell();
	int id;
	vector<int> neighborsIDs;
	//int numOfNeighbors;

	bool isAlive();
	//void countNeighbors();
	int getNumOfNeighborsAlive(vector<Cell>n);
	void setNeighbors(int a, int b);
	const vector<int> getNeighbors();
	void setLife(bool l);

	void showNeighbors();

};
