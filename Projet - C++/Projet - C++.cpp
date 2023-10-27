#include <vector>
#include "Grid.h"
#include "Case.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int main() {
    Grid grid;


    bool quitGame = false;
    while (!quitGame) {
        
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
                quitGame = true; 
                validMove = true; 
                break;
            default:
                
                break;
            }
        }

        
        grid.generateRandomTile();

       
    }
    return 0;
}
