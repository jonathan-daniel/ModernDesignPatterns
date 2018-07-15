#pragma once

#include <memory>
#include <string>
#include <map>

using namespace std;

template <typename BaseType>
class Factory {
private:
	map<string, shared_ptr<BaseType>> objectmap = {};

	template<typename DerivedType, typename ...Args>
	shared_ptr<BaseType> createDerivedObject(Args&& ...args) const
	{
		return shared_ptr<BaseType>(
			new DerivedType(forward<Args>(args)...)
		);
	}

public:
	// Register a certain key with an object of DerivedType with args as constructor parameters
	template<typename DerivedType, typename ...Args>
	void registerObject(const string& name, Args&& ...args)
	{
		objectmap.insert_or_assign(
			name,
			createDerivedObject<DerivedType>(
				forward<Args>(args)...
			)
		);
	}

	template<typename DerivedType>
	shared_ptr<DerivedType> create(const string& name)
	{
		shared_ptr<DerivedType> ret = dynamic_pointer_cast<DerivedType>(
			objectmap.at(name));

		// Calls the copy constructor of the object.
		shared_ptr<DerivedType> backup = make_shared<DerivedType>(*ret);

		// Replace the shared ptr with a backup
		objectmap.insert_or_assign(
				name, backup
		);

		return ret;
	}
};