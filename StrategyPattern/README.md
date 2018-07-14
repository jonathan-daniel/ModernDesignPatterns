# Strategy design pattern

The strategy design pattern contains an unique pointer to the algorithm to use, which can dynamically be changed and is easy to extend with new algorithms (following the SOLID principles). 

However to prevent inheritance slicing of `SortAlgorithm` subclasses in the `Container` copy constructor the **clone pattern** is also used, so this is actually a combination of two design patterns.

The clone pattern allows the `Container` class to clone a derived `SortAlgorithm` without losing subclass-specific members:

```C++
Container(const Container& other) : algo(other.algo->clone()) {}
```
## UML

![alternative text](http://www.plantuml.com/plantuml/proxy?src=https://raw.github.com/jonathan-daniel/ModernDesignPatterns/master/src/StrategyPattern/doc/strategy_diagram.txt&fmt=svg)