#include <iostream>

#include "Factory.hpp"
#include "Animals.hpp"

using namespace std;

int main()
{
	Factory<Animal> animalFactory;

	animalFactory.registerObject<Dog>("dog");

	auto dog = animalFactory.create<Dog>("dog");

	dog->doSomething();

	return 0;
}