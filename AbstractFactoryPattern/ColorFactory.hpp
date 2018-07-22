#pragma once

#include "Factory.hpp"
#include "Colors.hpp"

#include <memory>

namespace colorfactory
{
	
using ColorFactory = factory::Factory<std::unique_ptr<Color>>;

enum class ColorTag {green, red, blue};

ColorFactory colorFactoryProducer(ColorTag tag)
{
	return [=]
	{
		if(tag == ColorTag::green)
			return std::unique_ptr<Color>(new Green());
		else if(tag == ColorTag::blue)
			return std::unique_ptr<Color>(new Blue());
		else if(tag == ColorTag::red)
			return std::unique_ptr<Color>(new Red());
		else
			return std::unique_ptr<Color>(nullptr);
	};
}

}