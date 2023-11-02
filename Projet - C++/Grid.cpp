#include "Grid.h"
#include "Case.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

Grid::Grid() {
    srand(time(0));
}

void Grid::initializeGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = Case(); // on va donner les coordonn�s de chaque case
        }
    }
}

void Grid::displayGrid() {
    system("cls"); // On �fface l'�cran pour n'avoir qu'une seule grille
    for (int i = 0; i < SIZE; i++) { // i = ligne
        for (int j = 0; j < SIZE; j++) {  // j = colonne
            cout << "+-------";
        }
        cout << "+" << endl;

        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].isEmpty()) {
                cout << "|       ";
            }
            else {
                cout << "| " << setw(6) << grid[i][j].getValue(); // on recup la valeur de la case
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
    int randomValue = std::rand() % 2 == 0 ? 2 : 4; // random la tile si elle est = 2 ou 4

    int emptyRow, emptyCol; // stock les coordonn�es d'une case vide
    do {
        emptyRow = std::rand() % SIZE;
        emptyCol = std::rand() % SIZE;
    } while (!grid[emptyRow][emptyCol].isEmpty()); // cherche une case vide 

    grid[emptyRow][emptyCol].setValue(randomValue); // attribu une valeur aleatoire a la nouvelle tile cr�e
}

bool Grid::winCondition() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].getValue() == 2048) { // verif si une case est = 2048
                return true;
            }
        }
    }
    return false;
}

bool Grid::loseCondition() {   
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].isEmpty()) {
                return false;
            }
            // On regarde s'il est encore possible de fusionner des cases
            if ((i > 0 && grid[i][j].getValue() == grid[i - 1][j].getValue()) ||
                (j > 0 && grid[i][j].getValue() == grid[i][j - 1].getValue())) {
                return false;
            }
        }
    }
    return true;
}


void Grid::moveTilesUp() {
    for (int col = 0; col < SIZE; col++) {
        for (int row = 1; row < SIZE; row++) {
            if (!grid[row][col].isEmpty()) {
                int currentRow = row;
                while (currentRow > 0 && grid[currentRow - 1][col].isEmpty()) {
                    //Ici on s'occupe des d�placements
                    grid[currentRow - 1][col].setValue(grid[currentRow][col].getValue());
                    grid[currentRow][col].setValue(0);
                    currentRow--;
                }
                if (currentRow > 0 && grid[currentRow - 1][col].getValue() == grid[currentRow][col].getValue()) {
                    // On s'occupe de la fusion des cases
                    int newValue = grid[currentRow][col].getValue() * 2;
                    grid[currentRow - 1][col].setValue(newValue);
                    grid[currentRow][col].setValue(0);
                }
            }
        }
    }
}

void Grid::moveTilesDown() {
    for (int col = 0; col < SIZE; col++) {
        for (int row = SIZE - 2; row >= 0; row--) {
            if (!grid[row][col].isEmpty()) {
                int currentRow = row;
                while (currentRow < SIZE - 1 && grid[currentRow + 1][col].isEmpty()) {
                    //Ici on s'occupe des d�placements
                    grid[currentRow + 1][col].setValue(grid[currentRow][col].getValue());
                    grid[currentRow][col].setValue(0);
                    currentRow++;
                }
                if (currentRow < SIZE - 1 && grid[currentRow + 1][col].getValue() == grid[currentRow][col].getValue()) {
                    // On s'occupe de la fusion des cases
                    int newValue = grid[currentRow][col].getValue() * 2;
                    grid[currentRow + 1][col].setValue(newValue);
                    grid[currentRow][col].setValue(0);
                }
            }
        }
    }
}


void Grid::moveTilesRight() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = SIZE - 2; col >= 0; col--) {
            if (!grid[row][col].isEmpty()) {
                int currentCol = col;
                while (currentCol < SIZE - 1 && grid[row][currentCol + 1].isEmpty()) {
                    //Ici on s'occupe des d�placements
                    grid[row][currentCol + 1].setValue(grid[row][currentCol].getValue());
                    grid[row][currentCol].setValue(0);
                    currentCol++;
                }
                if (currentCol < SIZE - 1 && grid[row][currentCol + 1].getValue() == grid[row][currentCol].getValue()) {
                    // On s'occupe de la fusion des cases
                    int newValue = grid[row][currentCol].getValue() * 2;
                    grid[row][currentCol + 1].setValue(newValue);
                    grid[row][currentCol].setValue(0);
                }
            }
        }
    }
}

void Grid::moveTilesLeft() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 1; col < SIZE; col++) {
            if (!grid[row][col].isEmpty()) {
                int currentCol = col;
                while (currentCol > 0 && grid[row][currentCol - 1].isEmpty()) {
                    //Ici on s'occupe des d�placements
                    grid[row][currentCol - 1].setValue(grid[row][currentCol].getValue());
                    grid[row][currentCol].setValue(0);
                    currentCol--;
                }
                if (currentCol > 0 && grid[row][currentCol - 1].getValue() == grid[row][currentCol].getValue()) {
                    // Fuuuuu-sion Haa!
                    int newValue = grid[row][currentCol].getValue() * 2;
                    grid[row][currentCol - 1].setValue(newValue);
                    grid[row][currentCol].setValue(0);
                }
            }
        }
    }
}

