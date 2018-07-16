#pragma once

#include <functional>
#include <memory>

namespace factory 
{

/**
 * A template for a factory, which is just a std::function.
 * See AnimalFactory.hpp for example usage.
 */
template <class ReturnType, class ...Args>
using Factory = std::function<ReturnType(Args...)>;

}