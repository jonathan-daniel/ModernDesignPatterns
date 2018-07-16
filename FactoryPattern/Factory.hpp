#pragma once

#include <functional>
#include <memory>

namespace factory 
{

template <class ReturnType, class ...Args>
using Factory = std::function<ReturnType(Args...)>;

}