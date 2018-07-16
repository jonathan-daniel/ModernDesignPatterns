#pragma once

#include <memory>
#include <string>
#include <map>

template <typename BaseType>
class Factory {
private:
	std::map<std::string, std::shared_ptr<BaseType>> objectmap = {};

	template<typename DerivedType, typename ...Args>
	std::shared_ptr<BaseType> createDerivedObject(Args&& ...args) const
	{
		return std::shared_ptr<BaseType>(
			new DerivedType(std::forward<Args>(args)...)
		);
	}

public:
	// Register a certain key with an object of DerivedType with args as constructor parameters
	template<typename DerivedType, typename ...Args>
	void registerObject(const std::string& name, Args&& ...args)
	{
		objectmap.insert_or_assign(
			name,
			createDerivedObject<DerivedType>(
				std::forward<Args>(args)...
			)
		);
	}

	template<typename DerivedType>
	std::shared_ptr<DerivedType> get(const std::string& name)
	{
		std::shared_ptr<DerivedType> ret = std::dynamic_pointer_cast<DerivedType>(
			objectmap.at(name)
		);

		// Calls the copy constructor of the object.
		std::shared_ptr<DerivedType> backup = std::make_shared<DerivedType>(*ret);

		// Replace the shared ptr with a backup
		objectmap.insert_or_assign(
				name, backup
		);

		return ret;
	}
};