#include "Animals.hpp"
#include "AnimalFactory.hpp"

#include <iostream>
#include <memory>
#include <string>

int main()
{
	// Create factories to use later
	auto animalFactory = animalfactory::animalFactory();
	auto specialDogFactory = animalfactory::animalFactory("special_dog");
	auto mediumFarmFactory = animalfactory::farmFactory(20);

	// Create one duck now
	auto duck = animalfactory::animalFactory("duck")();

	// Create base animal object
	auto someAnimal = animalFactory();

	// Create and downcast special dog to access derived members.
	auto specialDog = std::dynamic_pointer_cast<Dog>(
		std::shared_ptr<Animal>(
			specialDogFactory()
		)
	);

	// Test downcast
	std::cout << std::to_string(specialDog->getExtraInt()) << std::endl;

	// Create a farm with 20 animals
	auto animals = mediumFarmFactory();

	animals[0].doSomething();

	return 0;
}