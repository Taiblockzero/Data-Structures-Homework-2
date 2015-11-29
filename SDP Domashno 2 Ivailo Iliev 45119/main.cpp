#include "Cell.h"
#include "LinkedList.h"
#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	Cell** arr = new Cell*[n]; //2D array
	for (int i = 0; i < n; ++i)
		arr[i] = new Cell[m];

	char c;
	for (int i = 0; i < n; ++i) //Set the cells based on input
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> c;
			arr[i][j].setCell(i, j, c);
		}
	}

	int start[2]; //Position of starting cell, if starting cell is "not-passable" don't act different
	for (int i = 0; i < 2; ++i)
	{
		cin >> start[i];
	}

	LinkedList<Cell> reachable; //List consisting of all reachable cells
	queue<Cell> que;
	
	Cell* curr = &arr[start[0]][start[1]]; //Current cell pointer
	curr->visited = true;
	arr[curr->x][curr->y].visited = true;
	
	curr->workWithAdjacentCells(reachable, arr, n, m, que);
	if (que.isEmpty() == true)
	{
		cout << "No reachable cells from the starting cell." << endl;
		return 0;
	}
	Cell currCell = que.pop();
	curr = &currCell;

	for (;;) //Execute BFS
	{
		curr->visited = true;
		arr[curr->x][curr->y].visited = true;
		curr->workWithAdjacentCells(reachable, arr, n, m, que);
		if (que.isEmpty() == true)
		{
			break;
		}
		currCell = que.pop();
		curr = &currCell;
	}

	Iterator<Cell> it = reachable.GetIterator();
	for (; !(it.EndReached()); it.MoveNext())
	{
		cout << "(" << it.GetCurrent().x << "," << it.GetCurrent().y << ") ";
	}

	



	for (int i = 0; i < n; ++i) //2D array cleanup
		delete[] arr[i];
	delete[] arr;
	return 0;
}