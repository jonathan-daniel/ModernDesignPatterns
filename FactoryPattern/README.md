# Factory Pattern

This is a factory pattern written in just a few lines of code.

```C++
template <class ReturnType, class ...Args>
using Factory = std::function<ReturnType(Args...)>;
```
Basically a `Factory` is a std::function that has a target callable that's based on parameters/arguments you define. This target callable will return an object of type `ReturnType` defined for the `Factory`.

An example of how to create a factory for a vector of _N_ Animals:

```C++
/**
 * This factory type must return a vector of Animal objects.
 */
using FarmFactory = factory::Factory<std::vector<Animal>>;

FarmFactory farmFactory(int N)
{
	return [=]
	{
		std::vector<Animal> ret;
		for (std::size_t i = 0; i < N; i++)
			ret.push_back(Animal());

		return ret;
	};
}

// Create a farm with 20 animals
auto mediumFarmFactory = animalfactory::farmFactory(20); // Set the target based on parameters.
auto animals = mediumFarmFactory(); // Call the target of the std::function

```
## Sequence Diagram

![alternative text](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/jonathan-daniel/ModernDesignPatterns/factory/FactoryPattern/doc/factory_diagram.txt&fmt=svg)