#include "Case.h"
#pragma once
const int SIZE = 4;

class Grid
{
private:
	Case grid[SIZE][SIZE];
public:
	Grid();
	void initializeGrid();
	void displayGrid();

	int moveUp;
	int moveDown;
	int moveLeft;
	int moveRight;
};

