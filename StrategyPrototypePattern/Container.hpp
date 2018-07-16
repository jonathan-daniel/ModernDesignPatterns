#pragma once

#include "Algorithms.hpp"

#include <iostream>
#include <memory>

class Container {
private:
	std::unique_ptr<SortAlgorithm> algo = std::make_unique<QuickSort>();
public:
	Container(std::unique_ptr<SortAlgorithm> algo) : algo(move(algo)) {}

	void sort() 
	{
		if(algo)
			algo->sort();
		else
			std::cout << "Sort algorithm not set." << std::endl;
	}

	// Use the clone pattern to prevent slicing of derived object. 
	Container(const Container& other) : algo(other.algo->clone()) {}

	Container& operator=(const Container& other)
	{
		Container tmp(other); // Re-use copy-constructor.
		*this = std::move(tmp);
		return *this;
	}

	// Set the rvalue constructor and move assignment.
	// It is deleted because the copy constructor of unique_ptr is deleted.
	Container(Container&& other) = default;
	Container& operator=(Container&& other) = default;

	void setAlgo(std::unique_ptr<SortAlgorithm> algo) 
	{
		this->algo = move(algo);
	}
};