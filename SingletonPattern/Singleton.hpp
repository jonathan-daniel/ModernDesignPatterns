#pragma once

#include <iostream> // for the test print
using namespace std;

class Singleton {
public:
	static Singleton& getInstance() 
	{
		static Singleton instance;
		return instance;
	}

	// A test function
	void print()
	{
		cout << "test" << endl;
	}
private:
	Singleton() = default;
	~Singleton() = default;
public:
	// Delete the copy and move constructors.
	// These should be public as it results in clearer error messages.
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;
};