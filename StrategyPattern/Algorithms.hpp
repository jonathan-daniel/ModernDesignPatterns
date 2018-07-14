#pragma once

#include <iostream>
#include <memory>

#include <iostream>

using namespace std;

class SortAlgorithm {
public:
	virtual void sort() = 0;
	virtual ~SortAlgorithm() = default; 
	
	auto clone() const
	{
		return unique_ptr<SortAlgorithm>(clone_derived()) ;
	}
protected:
	virtual SortAlgorithm* clone_derived() const = 0;
};

class QuickSort : public SortAlgorithm {
public:
	void sort() override { cout << "QuickSort" << endl; }
protected:
	virtual QuickSort* clone_derived() const override 
	{
		return new QuickSort(*this);
	}
};

class MergeSort : public SortAlgorithm {
public:
	void sort() override { cout << "MergeSort" << endl; }
protected:
	virtual MergeSort* clone_derived() const override 
	{
		return new MergeSort(*this);
	}
};