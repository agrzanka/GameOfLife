#include "Cell.h"
#include "Board.h"
#include <iostream> 

int main()
{
	/*Cell c17(17);
	c17.setNeighbors(8, 5);
	c17.showNeighbors();

	Cell c1(1);
	c1.setLife(true);
	c1.setNeighbors(8, 5);
	c1.showNeighbors();

	Cell c32(32);
	c32.setLife(true);
	c32.setNeighbors(8, 5);
	c32.showNeighbors();*/

	Board b(8, 5);
	b.show();

	vector<int>blinker;
	blinker.push_back(13);
	blinker.push_back(21);
	blinker.push_back(29);

	cout << "==================================BLINKER==================================" << endl;

	b.init(blinker);
	b.show();

	for (int i = 0; i < 5; i++)
	{
		b.update();
		b.show();
	}

	Board b2(8, 5);
	b2.show();
	vector<int>glider = { 2,9,17,18,19 };
	cout << "\n==================================GLIDER==================================\n";
	b2.init(glider);
	b2.show();

	for (int i = 0; i < 8; i++)
	{
		b2.update();
		b2.show();
	}


	system("PAUSE");
}
