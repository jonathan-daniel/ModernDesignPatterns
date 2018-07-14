# Observer Design Pattern

The observer pattern allows objects to listen for state changes in a certain `Subject`.

This implementation makes no assumptions and is completely decoupled from the observers. This is done by setting the state as a template typename of the class and attaching only the function that handles the changes.

This function must be of format `void f(const StateType&)` where StateType is the same as the one specified to the `Subject` class.

An example:

```C++
struct State { int data; };

void handleStateChange(const State& newState)
{
	cout << "State changed to: " << newState.data << endl;
}

int main() 
{
	// Create a new subject with a certain state.
	Subject<State> someSubject;

	// Attach the observer, this can be any function.
	someSubject.attach(handleStateChange);

	// Get the state and change it.
	State state = someSubject.getState();
	state.data = 1337;
	someSubject.setState(state);
	return 0;
}
```

## UML

![alternative text](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/jonathan-daniel/ModernDesignPatterns/master/ObserverPattern/doc/observer_diagram.txt&fmt=svg)