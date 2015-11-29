#pragma once
#include <iostream>

class queueEmptyException
{
public:
	queueEmptyException()
	{
		std::cout << "Queue Empty\n";
	}
};