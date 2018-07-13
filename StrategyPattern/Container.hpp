#pragma once

#include "Algorithms.hpp"

#include <iostream>
#include <memory>

using namespace std;

class Container {
private:
	unique_ptr<SortAlgorithm> algo = make_unique<QuickSort>();
public:
	Container(unique_ptr<SortAlgorithm> algo) : algo(move(algo)) {}

	void sort() 
	{
		if(algo)
			algo->sort();
		else
			cout << "Sort algorithm not set." << endl;
	}

	Container(const Container& other) : algo(other.algo->clone()) {}

	Container& operator=(const Container& other)
	{
		Container tmp(other); // Re-use copy-constructor.
		*this = move(tmp);
		return *this;
	}

	// Set the rvalue constructor and move assignment.
	// It is deleted because the copy constructor of unique_ptr is deleted.
	Container(Container&& other) = default;
	Container& operator=(Container&& other) = default;

	void setAlgo(unique_ptr<SortAlgorithm> algo) 
	{
		this->algo.swap(algo);
	}
};