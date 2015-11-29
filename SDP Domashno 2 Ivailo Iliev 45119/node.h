#pragma once

template<class T>
struct node
{
	T data;
	node<T>* previous;
};