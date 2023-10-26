#include "Grid.h"
#include "Case.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

Grid::Grid() {

}

void Grid::initializeGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = Case();
        }
    }
}

void Grid::displayGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "+-------";
        }
        cout << "+" << endl;

        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].isEmpty()) {
                cout << "| " << setw(3) << "      ";
            }
            else {
                cout << "| " << setw(3) << grid[i][j].getValue();
            }
        }
        cout << "|" << endl;
    }

    for (int j = 0; j < SIZE; j++) {
        cout << "+-------";
    }
    cout << "+" << endl;

    cout << endl;
}

void Grid::generateRandomTile() {
    int randomValue = std::rand() % 2 == 0 ? 2 : 4;

    int emptyRow, emptyCol;
    do {
        emptyRow = std::rand() % SIZE;
        emptyCol = std::rand() % SIZE;
    } while (!grid[emptyRow][emptyCol].isEmpty());

    grid[emptyRow][emptyCol].setValue(randomValue);
}
