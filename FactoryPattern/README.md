# Factory Pattern

This is a factory pattern, it allows to associate a name with a certain construction method of an object(specified at `Factory::registerObject`).

The template parameter `template<typename DerivedType>` at the `Factory::get` method could be eliminated using the prototype pattern (see the Strategy & Prototype pattern).

Right now it is used to call the copy constructor of the derived object to make the Factory class completely decoupled from the objects.

## UML

![alternative text](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/jonathan-daniel/ModernDesignPatterns/master/FactoryPattern/doc/factory_diagram.txt&fmt=png)