#include "Cell.h"
#include "Matrix.h"
#include <iostream> 


//void askUser(bool **initialArgs);

int main()
{/*
	std::cout << "HELLO";
	bool initialArgs[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			initialArgs[i][j] = 0;
	//askUser(initialArgs[10][10]);
	int x, y, d = 0;
	std::cout << "\ncoordinates of the alive cells:\n";
	for (int i = 0; i < 100; i++)
	{
		std::cout << "x: ";
		std::cin >> x;
		std::cout << "\ty: ";
		std::cin >> y;

		initialArgs[x][y] = 1;

		std::cout << "\nAny more alive cells you want to add? press 1 for yes, 0 for no: ";
		std::cin >> d;
		if (d == 0)
			break;
		else if (d > 1 || d < 0)
		{
			std::cout << "error";
			break;
		}

	}
	int r;

	Matrix m;
	m.setUpMatrix(initialArgs);
	m.showMatrix();

	std::cout << "\nnumber of rounds: ";
	std::cin >> r;

	for (int i = 0; i < r; i++)
	{
		std::cout << "\nround number: " << i + 1;
		m.updateMatrix();
		m.showMatrix();
	}*/
	system("PAUSE");
}

/*void askUser(bool **initialArgs)
{
	
	int x, y, d = 0;
	std::cout << "\ncoordinates of the alive cells:\n";
	for (int i = 0; i < 100; i++)
	{
		std::cout << "x: ";
		std::cin >> x;
		std::cout<<"\ty: ";
		std::cin >> y;

		initialArgs[x][y] = 1;

		std::cout << "\nAny more alive cells you want to add? press 1 for yes, 0 for no: ";
		std::cin >> d;
		if (d == 0)
			break;
		else if (d > 1 || d < 0)
		{
			std::cout << "error";
			break;
		}

	}

}*/
