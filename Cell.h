#pragma once
class Cell
{
private:
	bool life;
	int neighborsAlive;
public:
	Cell(int x, int y);
	Cell();
	int x;
	int y;

	// int getNumOfNeighbors();
	bool isAlive();
	int getNeighborsAlive();
	void setNeighborsAlive(int n);
	void updateCell(bool l);
};
