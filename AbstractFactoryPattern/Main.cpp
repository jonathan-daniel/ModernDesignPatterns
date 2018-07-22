#include "AbstractFactory.hpp"
#include "ShapeFactory.hpp"

int main()
{
	using namespace abstractfactory;
	using namespace shapefactory;

	auto rectFactory = factoryProducer(FactoryTag::shape)(ShapeTag::rectangle);

	auto shape = rectFactory();

	shape->draw();

	return 0;
}