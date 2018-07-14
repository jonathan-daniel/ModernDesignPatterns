# Strategy design pattern

With the strategy design pattern a class (in this case `Container`)contains an unique pointer to another object which provides a certain functionality (in this case `SortAlgorithm`), which can dynamically be changed and is easy to extend with new functionalities/algorithms (following the SOLID principles). 

However to prevent inheritance slicing of `SortAlgorithm` subclasses in the `Container` copy constructor the **clone pattern** is also used, so this is actually a combination of two design patterns.

The clone pattern allows the `Container` class to clone a derived `SortAlgorithm` without losing subclass-specific members:

```C++
Container(const Container& other) : algo(other.algo->clone()) {}
```
## UML

![alternative text](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/jonathan-daniel/ModernDesignPatterns/master/StrategyPattern/doc/strategy_diagram.txt&fmt=svg)