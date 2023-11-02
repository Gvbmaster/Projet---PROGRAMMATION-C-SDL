#include <vector>
#include "Grid.h"
#include "Case.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#define KEY_UP 72  //on definit les fleches du clavier comme touches de jeu
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int main() {
    Grid grid;
    bool theGame = true;
    bool gameWon = false;
    bool gameLost = false;

    while (theGame && !gameWon && !gameLost) {
        grid.displayGrid();

        bool validMove = false;
        while (!validMove) {
            int key = _getch();
            switch (key) {
            case KEY_UP:
                grid.moveTilesUp();
                validMove = true;
                break;
            case KEY_DOWN:
                grid.moveTilesDown();
                validMove = true;
                break;
            case KEY_LEFT:
                grid.moveTilesLeft();
                validMove = true;
                break;
            case KEY_RIGHT:
                grid.moveTilesRight();
                validMove = true;
                break;
            case 'q':
            case 'Q':
                theGame = false;
                validMove = true;
                break;
            default:
                break;
            }
        }

        grid.generateRandomTile();
        gameWon = grid.winCondition(); // Vérifie la condition de victoire
        gameLost = grid.loseCondition(); // Vérifie la condition de défaite
    }

    grid.displayGrid(); // Affiche le plateau final
    if (gameWon) {
        cout << "Félicitations ! Vous avez gagné !" << endl;
    }
    else if (gameLost) {
        cout << "Dommage, vous avez perdu." << endl;
    }

    return 0;
}