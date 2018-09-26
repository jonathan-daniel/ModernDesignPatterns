#pragma once

#include "ShapeFactory.hpp"
#include "ColorFactory.hpp"

namespace abstractfactory 
{

struct FactoryTag 
{
	struct Shape {} static constexpr shape{};
	struct Color {} static constexpr color{};
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