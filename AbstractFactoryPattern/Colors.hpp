#pragma once

#include <iostream>

class Color {
public:
	virtual void draw() = 0;
	virtual ~Color() {}
};

class Green : public Color {
public:
	void draw() override
	{
		std::cout << "Drawing Green." << std::endl;
	}
};

class Blue : public Color {
public:
	void draw() override
	{
		std::cout << "Drawing Blue." << std::endl;
	}
};

class Red : public Color {
public:
	void draw() override
	{
		std::cout << "Drawing Red." << std::endl;
	}
};