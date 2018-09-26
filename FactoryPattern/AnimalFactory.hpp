#pragma once

#include "Factory.hpp"
#include "Animals.hpp"

#include <memory>
#include <vector>

namespace animalfactory
{

/**
 * This is using declaration for an AnimalFactory which is infact a Factory
 * that must return a std::unique_ptr<Animal>.
 */
using AnimalFactory = factory::Factory<std::unique_ptr<Animal>>;


/**
 * @brief      This functions returns an AnimalFactory which can be used to
 *  generate a std::unique_ptr<Animal> as defined for AnimalFactory.
 *  What derived (or base) object the returned factory makes depends on
 *  the given _tag_.
 *
 * @param[in]  tag   The tag that defines what object the returned 
 * AnimalFactory makes.
 *
 * @return     returns a callable that generates an object.
 */
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

/**
 * This factory type must return a vector of Animal objects.
 */
using FarmFactory = factory::Factory<std::vector<Animal>>;

FarmFactory farmFactory(std::size_t animalcount)
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