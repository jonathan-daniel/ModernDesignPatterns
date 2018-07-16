#pragma once

#include <iostream>
#include <memory>

#include <iostream>

class SortAlgorithm {
public:
	virtual void sort() = 0;
	virtual ~SortAlgorithm() = default; 
	
	auto clone() const
	{
		return std::unique_ptr<SortAlgorithm>(clone_derived()) ;
	}
protected:
	virtual SortAlgorithm* clone_derived() const = 0;
};

class QuickSort : public SortAlgorithm {
public:
	void sort() override { std::cout << "QuickSort" << std::endl; }
protected:
	virtual QuickSort* clone_derived() const override 
	{
		return new QuickSort(*this);
	}
};

class MergeSort : public SortAlgorithm {
public:
	void sort() override { std::cout << "MergeSort" << std::endl; }
protected:
	virtual MergeSort* clone_derived() const override 
	{
		return new MergeSort(*this);
	}
};