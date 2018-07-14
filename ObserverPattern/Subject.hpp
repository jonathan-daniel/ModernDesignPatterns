#pragma once

#include <list>
#include <utility>
#include <functional>

using namespace std;

template <typename StateType>
class Subject {
private:
	list<function<void(const StateType&)>> observers = {};
	StateType state;

	void notifyObservers() const
	{
		for (const auto& observer : observers) observer(state);
	}
public:
	Subject() : state() {}

	void setState(const StateType& state)
	{
		this->state = state;
		notifyObservers();
	}

	StateType getState() { return state; }

	template <typename Observer>
	void attach(Observer&& observer)
	{
		observers.push_back(forward<Observer>(observer));
	}
};