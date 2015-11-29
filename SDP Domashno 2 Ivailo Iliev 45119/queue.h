#pragma once
#include "node.h"
#include "queueEmptyException.h"


template <class T>
class queue
{
private:
	node<T>* front;
	node<T>* rear;
	int count;

public:
	queue();
	void push(T data);
	T pop();
	T getFront() const;
	T getRear() const;
	int size() const;
	bool isEmpty() const;
};

template<class T>
queue<T>::queue()
{
	front = NULL;
	rear = NULL;
	count = 0;
}

template<class T>
void queue<T>::push(T data)
{
	node<T>* temp = new node<T>;
	temp->previous = NULL;
	temp->data = data;


	if (0 == count) //Empty queue
	{
		rear = temp;
		front = temp;
	}
	else
	{
		rear->previous = temp;
		rear = temp;
	}

	count++;
}

template<class T>
T queue<T>::pop()
{
	if (0 == count) //Empty queue
		throw new queueEmptyException;

	T returnValue;
	returnValue = front->data;
	node<T>* temp = front->previous;

	delete front;
	front = temp;
	count--;
	return returnValue;
}

template<class T>
T queue<T>::getFront() const
{
	if (0 == count) //Empty Queue
		throw new queueEmptyException;

	return front->data;
}

template<class T>
T queue<T>::getRear() const
{
	if (0 == count) //Empty Queue
		throw new queueEmptyException;

	return rear->data;
}

template<class T>
int queue<T>::size() const
{
	return count;
}

template<class T>
bool queue<T>::isEmpty() const
{
	if (0 == count)
		return true;
	return false;
}