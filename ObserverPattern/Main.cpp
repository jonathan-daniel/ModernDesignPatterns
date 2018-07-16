#include "Subject.hpp"

#include <iostream>

using namespace std;

struct State {
	int data;
};

void handleStateChange(const State& newState)
{
	cout << "State changed to: " << newState.data << endl;
}

int main() 
{
	// Create a new subject with a certain state.
	Subject<State> someSubject;

	// Attach the observer, this can be any function.
	// Multiple observers can have the same key.
	// Or no key at all.
	someSubject.attach(handleStateChange, "stateHandle");

	// Get the state and change it.
	State state = someSubject.getState();
	state.data = 1337;
	someSubject.setState(state);

	// Detach the observer
	someSubject.detach("stateHandle");

	state.data = 12;
	someSubject.setState(state);

	return 0;
}