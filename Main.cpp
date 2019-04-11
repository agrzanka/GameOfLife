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
	blinker.push_back(2);
	blinker.push_back(7);
	blinker.push_back(12);

	cout << "==================================BLINKER==================================" << endl;

	b.init(blinker);
	b.show();

	for (int i = 0; i < 5; i++)
	{
		b.update();
		b.show();
	}

	Board b2(8, 8);
	b2.show();
	vector<int>glider = { 2,8,10,17,18 };
	cout << "\n==================================GLIDER==================================\n";
	b2.init(glider);
	b2.show();

	for (int i = 0; i < 8; i++)
	{
		b2.update();
		b2.show();
	}

	Board b3(50, 25);
	b3.show();
	vector<int>glider2 = { 2,25,27,51,52 };
	cout << "\n==================================GLIDER==================================\n";
	b3.init(glider2);
	b3.show();

	for (int i = 0; i < 200; i++)
	{
		b3.update();
		b3.show();
	}


	system("PAUSE");
}
