#include "Cell.h"
#include "Matrix.h"

Cell::Cell(int x, int y)
{
  this.x=x;
  this.y=y;
  this.updateCell(0);
 // this.life=false;
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
int Cell::getNeighborsAlive()
{
  return this.neighborsAlive;
}
