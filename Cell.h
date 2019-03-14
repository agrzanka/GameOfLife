#pragma once
class Cell
{
public:
  Cell(int x, int y);
  int x;
  int y;
  bool life;
 // int getNumOfNeighbors();
  bool isAlive();
  void updateCell(bool l);

};
