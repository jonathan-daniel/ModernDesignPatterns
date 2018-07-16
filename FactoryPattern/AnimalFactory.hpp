#pragma once

#include "Factory.hpp"
#include "Animals.hpp"

#include <memory>
#include <vector>

namespace animalfactory
{

using AnimalFactory = factory::Factory<std::unique_ptr<Animal>>;

// This function returns a std::function that generates an object based on the tag.
// the returned function can be executed with the () operator.
// The tag can be replaced with any parameter as seen in farmFactory.
AnimalFactory animalFactory(const std::string& tag = {})
{
	return [=]
	{
		if (tag == "dog")
			return std::unique_ptr<Animal>(new Dog());
		else if (tag == "duck")
			return std::unique_ptr<Animal>(new Duck());
		else if (tag == "special_dog")
			return std::unique_ptr<Animal>(new Dog(true));
		else 
			return std::unique_ptr<Animal>(new Animal());
	};
}

using FarmFactory = factory::Factory<std::vector<Animal>>;

FarmFactory farmFactory(int animalcount)
{
	return [=]
	{
		std::vector<Animal> ret;
		for (std::size_t i = 0; i < animalcount; i++)
			ret.push_back(Animal());

		return ret;
	};
}

}