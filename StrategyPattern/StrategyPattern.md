# Strategy design pattern

The strategy design pattern contains an unique pointer to the algorithm to use, which can dynamically be changed and is easy to extend with new algorithms (following the SOLID principles). 

However to prevent inheritance slicing of `Algorithm` subclasses in the `Container` copy constructor the **clone pattern** is also used, so this is actually a combination of two design patterns.

## UML

![alternative text](http://www.plantuml.com/plantuml/proxy?src=https://raw.github.com/plantuml/plantuml-server/master/src/main/webapp/resource/test2diagrams.txt&fmt=svg)