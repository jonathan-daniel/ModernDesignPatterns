#pragma once

#include <iostream>

class Animal {
private:
	int animalInt;
public:
	Animal(int animalInt) : animalInt(animalInt) {}
	Animal() : animalInt(12) {}
	virtual ~Animal(){} // the base class must have a virtual method.

	virtual void doSomething()
	{
		std::cout << "animal stuff" << std::endl;
	}
};

class Dog : public Animal {
private:
	int dogInt;
	int dogIntExtra = {-1};
public:
	Dog() : Animal(10), dogInt(10) {}

	Dog(bool extraprint) : Animal(10), dogInt(10), dogIntExtra(999)
	{
		if(extraprint)
			std::cout << "Dog stuff with extra stuff" << std::endl;
	}

	void doSomething() override
	{
		std::cout << "dog stuff" << std::endl;
	}

	int getExtraInt()
	{
		return dogIntExtra;
	}
};

class Duck : public Animal {
private:
	int duckInt;
public:
	Duck() : Animal(1337), duckInt(1337) {}

	void doSomething() override
	{
		std::cout << "duck stuff" << std::endl;
	}
};