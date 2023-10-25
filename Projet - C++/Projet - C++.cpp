#include <vector>
#include "Grid.h"
#include "Case.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

struct Player
{
	Point position;
};

class Point 
{
public:
	int x;
	int y;
	int z;

	void Clear() 
	{
		x = 0;
		y = 0;
		z = 0;
	}
};

int main() {

	int a;
	float b;


	Player player;
	player.position.Clear();

};