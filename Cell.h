#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Cell
{
private:
	bool life;
	vector<int> neighborsIDs;
public:
	Cell(int id);
	Cell();
	int id;
	//vector<int> neighborsIDs; 

	bool isAlive();
	//int getNumOfNeighborsAlive();
	void setNeighbors(int a, int b);
	void updateCell(bool l);

};
