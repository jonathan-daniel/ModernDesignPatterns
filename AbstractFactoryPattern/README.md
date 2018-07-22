# Abstract Factory Pattern

This is an abstract factory pattern.

It uses `std::is_same` with `if constexpr` (C++17) to deduct the return type of `abstractfactory::factoryProducer` at compile-time.

## Example usage

```C++
#include "AbstractFactory.hpp"
#include "ShapeFactory.hpp"

int main()
{
	using namespace abstractfactory;
	using namespace shapefactory;

	auto rectFactory = factoryProducer(FactoryTag::shape)(ShapeTag::rectangle);

	auto shape = rectFactory();

	shape->draw();

	return 0;
}
```

## Sequence Diagram

![alternative text](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/jonathan-daniel/ModernDesignPatterns/master/AbstractFactoryPattern/doc/abstract_factory_diagram.txt&fmt=svg)

In this diagram you can see that the AbstractFactory module (`AbstractFactory.hpp`) returns a function (in this case `shapeFactoryProducer`) that can produce a factory based on a parameter (a tag). This factory (`RectangleFactory`) can later be called to generate objects when needed.

The behaviour and tags can be customised to generate anything at any time, by using `unique_ptr` no data is copied which is best for performance.