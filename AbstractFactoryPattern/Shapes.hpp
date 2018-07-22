#pragma once

#include <iostream>

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() {};
};

class Rectangle : public Shape {
public:
	void draw() override 
	{
		std::cout << "Drawing rectangle." << std::endl;
	}
};

class Square : public Shape {
public:
	void draw() override
	{
		std::cout << "Drawing Square." << std::endl;
	}
};

class Circle : public Shape {
public:
	void draw() override
	{
		std::cout << "Drawing Circle." << std::endl;
	}
};