#pragma once

#include <utility>
#include <functional>
#include <unordered_map>
#include <string>

template <typename StateType>
class Subject {
private:
	std::unordered_multimap<
		std::string,
		std::function<void(const StateType&)>
	> observersMap = {};

	StateType state;

protected:
	void notifyObservers() const
	{
		// C++17 only
		for (const auto & [key, observer] : observersMap)
			observer(state);
	}

public:
	Subject() : state() {}

	/**
	 * @brief      Sets the state of the subject and
	 *  notifies all attached observers.
	 *
	 * @param[in]  state  The new state.
	 */
	void setState(const StateType& state)
	{
		this->state = state;
		notifyObservers();
	}

	/**
	 * @brief      Get the current state.
	 *
	 * @return     The state.
	 */
	StateType getState() { return state; }

	/**
	 * @brief      Attaches an observer to the subject.
	 *
	 * @param[in]  observer  The observer
	 *  must be of type std::function<void(const StateType&).
	 * 
	 * @param[in]  key       Optional key to use
	 *  when detaching an observer, multiple observers can
	 *  share the same key.
	 *
	 * @tparam     Observer  Deduced template param.
	 */
	template <typename Observer>
	void attach(Observer observer, const std::string& key = "")
	{
		observersMap.insert(std::make_pair(key, observer));
	}

	/**
	 * @brief      Detaches all observers associated with key.
	 *
	 * @param[in]  key   Optional, the key used to attach the observer.
	 *  If multiple observers are attached to this key they 
	 *  will all be detached. If no key is specified all observers
	 *  that were attached without key will get detached.
	 */
	void detach(const std::string& key = "")
	{
		observersMap.erase(key);
	}

	/**
	 * @brief      Detaches all attached observers.
	 */
	void detachAll()
	{
		observersMap.clear();
	}
};