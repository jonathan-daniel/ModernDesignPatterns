#include <iostream>
#include <memory>

#include "Container.hpp"
#include "Algorithms.hpp"

using namespace std;

int main() 
{
	Container someContainer = Container(make_unique<QuickSort>());
	someContainer.sort();
	someContainer.setAlgo(make_unique<MergeSort>());
	someContainer.sort();

	Container secondContainer = someContainer;

	secondContainer.sort();
	someContainer.sort();

	Container thirdContainer = Container(make_unique<QuickSort>());
	thirdContainer = secondContainer;
	thirdContainer.setAlgo(make_unique<QuickSort>());
	thirdContainer.sort();
	return 0;
}