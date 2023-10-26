#include <vector>
#include "Grid.h"
#include "Case.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    Grid grid;

    grid.initializeGrid();

    grid.displayGrid();

    char choice;

    while (true) {
        cout << "Appuyez sur T pour quitter : ";
        cin >> choice;

        if (choice == 'T' || choice == 't') {
            break;
        }
    }

    return 0;
}