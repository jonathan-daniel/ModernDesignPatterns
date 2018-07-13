#pragma once

#include <iostream>
#include <thread>

class Subject;

class Observer {
public:
	virtual void update(double price) = 0;
};

class IBMObserver : public Observer {
public:
	IBMObserver() {}

	void update(double price) override 
	{

	}
};

class Subject {
public:
	virtual void register() 
	{
	}

	void unregister() 
	{
	}

	void notifyObservers() 
	{
	}
};

class StockGrabber : public Subject {

};