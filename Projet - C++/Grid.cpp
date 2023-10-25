#include "Grid.h"
#include "Case.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void Grid::initializeGrid() {
	for (int i = 0; i < SIZE; i++) 
	{
		for (int j = 0; j < SIZE; j++) 
		{
			grid[i][j] = Case::Case();
		}
	}
}

void Grid::displayGrid()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << "+-------";
        }
        cout << "+" << endl;

        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j].value == 0) // value = case
            {
                cout << "| " << setw(3) << "      ";
            }
            else
            {
                cout << "| " << setw(3) << grid[i][j].Number << "   ";
            }

        }
        cout << "|" << endl;
    }

    for (int j = 0; j < SIZE; j++)
    {
        cout << "+-------";
    }
    cout << "+" << endl;

    cout << endl;
}