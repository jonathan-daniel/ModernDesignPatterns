#pragma once

#include <list>
#include <utility>
#include <functional>

template <typename StateType>
class Subject {
private:
	std::list<std::function<void(const StateType&)>> observers = {};
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
	void attach(Observer observer)
	{
		observers.push_back(std::forward<Observer>(observer));
	}
};