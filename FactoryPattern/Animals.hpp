#pragma once

#include <iostream>
using namespace std;

class Animal {
private:
	int animalInt;
public:
	Animal(int animalInt) : animalInt(animalInt) {}
	virtual ~Animal(){} // the base class must have a virtual method.

	virtual void doSomething()
	{
		cout << "animal stuff" << endl;
	}
};

class Dog : public Animal {
private:
	int dogInt;
public:
	Dog() : Animal(10), dogInt(10) {}

	Dog(bool extraprint) : Animal(10), dogInt(10)
	{
		if(extraprint)
			cout << "Dog stuff with extra stuff" << endl;
	}

	void doSomething() override
	{
		cout << "dog stuff" << endl;
	}
};

class Duck : public Animal {
private:
	int duckInt;
public:
	Duck() : Animal(1337), duckInt(1337) {}

	void doSomething() override
	{
		cout << "duck stuff" << endl;
	}
};