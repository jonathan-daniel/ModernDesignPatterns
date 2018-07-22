# Modern Design Patterns

## Design Patterns In Modern C++

[![Build Status](https://travis-ci.org/jonathan-daniel/ModernDesignPatterns.svg?branch=master)](https://travis-ci.org/jonathan-daniel/ModernDesignPatterns) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This repository contains samples of common design patterns written in modern C++. 

This is intended for learning purposes of new C++ features and a starting point for implementing a pattern in your system.

Every subfolder contains another *README.md* with detailed explanation.

## Patterns

The patterns included in this repo are:

- [x] [Strategy & Prototype Pattern](StrategyPrototypePattern/)
- [x] [Observer Pattern](ObserverPattern/)
- [x] [Factory Pattern](FactoryPattern/)
- [ ] Abstract Factory Pattern
- [x] [Singleton Pattern](SingletonPattern/)
- [ ] Builder Pattern
- [ ] Decorator Pattern
- [ ] Adapter pattern
- [ ] Iterator pattern

## Building

To build the project (Unix):

```bash
$ mkdir build && cd build/
$ cmake ../
$ make
```

`cmake` and a GCC version that supports C++17 are required for this.

## Contributing

If there are any better alternatives or bugs I would like to hear it.