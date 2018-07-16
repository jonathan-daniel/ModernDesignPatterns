# Singleton Pattern

For when you for some reason need a singleton. **I don't recommend using this but added it for completeness.**
This is thread-safe due to [Magic Statics](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2660.htm).

Supported from VC++2015 and GCC C++11.

One suggested alternative to a singleton is to throw an exception when trying to instantiate x objects.

## UML

![alternative text](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/jonathan-daniel/ModernDesignPatterns/master/SingletonPattern/doc/singleton_diagram.txt&fmt=svg)