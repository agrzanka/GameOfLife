#include "Cell.h"
#include "Matrix.h"

Cell::Cell(int x, int y)
{
  this.x=x;
  this.y=y;
  this.life=false;
}

//void Cell::getNumOfNeighbors()
bool Cell:isAlive()
{
  return this.life;
}

void Cell::updateCell(bool l)
{
  this.life=l;
}
