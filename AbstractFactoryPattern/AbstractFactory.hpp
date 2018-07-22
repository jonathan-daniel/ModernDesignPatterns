#pragma once

#include "ShapeFactory.hpp"
#include "ColorFactory.hpp"

namespace abstractfactory 
{

struct FactoryTag 
{
	static struct Shape{} shape;
	static struct Color{} color;
};

template <class TFactory>
auto factoryProducer(TFactory tag)
{   
    if constexpr (std::is_same<TFactory, FactoryTag::Shape>::value)
        return shapefactory::shapeFactoryProducer;
    else if constexpr (std::is_same<TFactory, FactoryTag::Color>::value)
        return colorfactory::colorFactoryProducer;
}   

}