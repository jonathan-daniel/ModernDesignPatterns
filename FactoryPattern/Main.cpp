#include <iostream>

#include "Factory.hpp"
#include "Animals.hpp"

using namespace std;

int main()
{
	Factory<Animal> animalFactory;
	
	// Associate "dog_extra" with Dog(bool) constructor
	animalFactory.registerObject<Dog>("dog_extra", true);

	auto dog = animalFactory.get<Dog>("dog_extra");
	dog->doSomething();
	cout << dog->getExtraInt() << endl;

	return 0;
}