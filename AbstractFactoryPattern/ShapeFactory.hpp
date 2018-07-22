#pragma once

#include "Factory.hpp"
#include "Shapes.hpp"

#include <memory>

namespace shapefactory
{

using ShapeFactory = factory::Factory<std::unique_ptr<Shape>>;

enum class ShapeTag {rectangle, circle, square};

ShapeFactory shapeFactoryProducer(ShapeTag tag)
{
	return [=]
	{
		if(tag == ShapeTag::rectangle)
			return std::unique_ptr<Shape>(new Rectangle());
		else if(tag == ShapeTag::circle)
			return std::unique_ptr<Shape>(new Circle());
		else if(tag == ShapeTag::square)
			return std::unique_ptr<Shape>(new Square());
		else
			return std::unique_ptr<Shape>(nullptr);
	};
}

}