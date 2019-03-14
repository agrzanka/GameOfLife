#pragma once
class Cell
{
  private:
    bool life;
    int neighborsAlive; 
  public:
    Cell(int x, int y);
    int x;
    int y;
 
 // int getNumOfNeighbors();
    bool isAlive();
    int getNeighborsAlive();
    void updateCell(bool l);
};
