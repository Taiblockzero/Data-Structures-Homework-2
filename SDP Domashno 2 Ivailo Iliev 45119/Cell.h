#pragma once
#include "LinkedList.h"
#include "queue.h"
#include <iostream>
using namespace std;
struct Cell
{
	int x;
	int y;
	bool visited;

	/* I know that 8 pointers take up a lot of space but I can afford it and it's worth 
	   the extra space because it helps make the code more readable */
	/*int xUp; DONT FORGET TO ADD THEM TO THE CONSTRUCTORS IF YOU USE THEM
	int yUp;
	int xRight;
	int yRight;
	int xDown;
	int yDown;
	int xLeft;
	int yLeft;*/

public:
	Cell();
	Cell(int x, int y, char inputChar);
	Cell(Cell const &);
	Cell& operator=(Cell const &);
	bool operator==(Cell const &);
	void setCell(int x, int y, char inputChar);
	
	//Looks at adjacent cells(up,down,left,right), if any of them are not visited and are also inside
	//the array bounds the function checks if they are already in the "reachable" list, if they aren't puts 
	//them in the "reachable" list, and adds them to the queue(putting in the queue happens regardless of 
	//whether the cells have been met in the "reachable" list)
	void workWithAdjacentCells(LinkedList<Cell>& reachable, Cell** arr, int n, int m, queue<Cell>& que);

};