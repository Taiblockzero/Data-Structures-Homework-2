#include"Cell.h"


Cell::Cell()
{
	this->x = -1;
	this->y = -1;
	this->visited = false;
}

Cell::Cell(int x, int y, char inputChar)
{
	this->x = x;
	this->y = y;
	if ('#' == inputChar)
		this->visited = true;
	else if ('.' == inputChar)
		this->visited = false;
	else
		cerr << "wtf even dude";
}

Cell::Cell(Cell const & other)
{
	this->x = other.x;
	this->y = other.y;
	this->visited = other.visited;
}

Cell& Cell::operator=(Cell const & other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
		this->visited = other.visited;
	}

	return *this;
}

bool Cell::operator==(Cell const & other)
{
	if (this == &other)
		return true;

	if ((this->x == other.x) && (this->y == other.y) && (this->visited == other.visited))
		return true;

	return false;
}

void Cell::setCell(int x, int y, char inputChar)
{
	this->x = x;
	this->y = y;

	if ('#' == inputChar)
		this->visited = true;
	else if ('.' == inputChar)
		this->visited = false;
	else
		cerr << "wtf even dude";
}

//Looks at adjacent cells(up,down,left,right), if any of them are not visited and are also inside
//the array bounds the function checks if they are already in the "reachable" list, if they aren't puts 
//them in the "reachable" list, and adds them to the queue(putting in the queue happens regardless of 
//whether the cells have been met in the "reachable" list)
void Cell::workWithAdjacentCells(LinkedList<Cell>& reachable, Cell** arr, int n, int m, queue<Cell>& que)
{
	//Up
	if (this->x > 0) //checking to see if there is an "Up" cell 
	{
		Cell* upCell = &(arr[this->x - 1][this->y]);
		if (upCell->visited == false) //if Up cell is not visited
		{
			Iterator<Cell> it = reachable.GetIterator();
			bool up = false;
			for (; !(it.EndReached()); it.MoveNext())
			{
				if (*upCell == it.GetCurrent())//if adress of "Up" cell == iterator current
				{
					up = true;
				}
			}
			if (up == false) //if the "Up" cell wasn't in the "reachable" list
			{
				reachable.AddTail(*upCell); //"Up" cell added to "reachable" list
			}

			que.push(*upCell); //"Up" added to queue
		}
	}

	//Right
	if (this->y < (m - 1)) //checking to see if there is a "Right" cell
	{
		Cell* rightCell = &(arr[this->x][this->y + 1]);
		if (rightCell->visited == false) //if Right cell is not visited
		{
			Iterator<Cell> it = reachable.GetIterator();
			bool right = false;
			for (; !(it.EndReached()); it.MoveNext())
			{
				if (*rightCell == it.GetCurrent())//if adress of "Right" cell == iterator current
				{
					right = true;
				}
			}
			if (right == false) //if the "Right" cell wasn't in the "reachable" list
			{
				reachable.AddTail(*rightCell); //"Right" cell added to "reachable" list
			}

			que.push(*rightCell); //"Right" added to queue
		}
	}

	//Down
	if (this->x < (n - 1)) //checking to see if there is a "Right" cell
	{
		Cell* downCell = &(arr[this->x + 1][this->y]);
		if (downCell->visited == false) //if Down cell is not visited
		{
			Iterator<Cell> it = reachable.GetIterator();
			bool down = false;
			for (; !(it.EndReached()); it.MoveNext())
			{
				if (*downCell == it.GetCurrent())//if adress of "Down" cell == iterator current
				{
					down = true;
				}
			}
			if (down == false) //if the "Down" cell wasn't in the "reachable" list
			{
				reachable.AddTail(*downCell); //"Down" cell added to "reachable" list
			}

			que.push(*downCell); //"Down" added to queue
		}
	}

	//Left
	if (this->y > 0) //checking to see if there is a "Left" cell
	{
		Cell* leftCell = &(arr[this->x][this->y - 1]);
		if (leftCell->visited == false) //if Left cell is not visited
		{
			Iterator<Cell> it = reachable.GetIterator();
			bool left = false;
			for (; !(it.EndReached()); it.MoveNext())
			{
				if (*leftCell == it.GetCurrent())//if adress of "Left" cell == iterator current
				{
					left = true;
				}
			}
			if (left == false) //if the "Left" cell wasn't in the "reachable" list
			{
				reachable.AddTail(*leftCell); //"Left" cell added to "reachable" list
			}

			que.push(*leftCell); //"Left" added to queue
		}
	}
}