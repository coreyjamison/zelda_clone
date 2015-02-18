/*
 * entity.hpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <unordered_map>

#include "component.hpp"

using namespace std;

class Component;
class ComponentModifier;

class Entity
{
public:
	Entity(unsigned long id);

	inline unsigned long getId() {return _id;}

	void addComponent(Component* c);

	template <typename T>
	T* getComponent()
	{
		if(_components.count(&typeid(T)) != 0)
		{
			return static_cast<T*>( _components[&typeid(T)]);
		}
		else
		{
			return nullptr;
		}
	}

	template <typename T>
	bool hasComponent()
	{
		return hasComponent(&typeid(T));
	}

	bool hasComponent(const type_info* componentType);

private:
	unsigned long _id;
	unordered_map<const type_info*, Component*> _components;
};



#endif /* ENTITY_HPP_ */
