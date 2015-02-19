/*
 * component_modifier.hpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Corey
 */

#ifndef ECS_COMPONENT_MODIFIER_HPP_
#define ECS_COMPONENT_MODIFIER_HPP_

#include "entity.hpp"

class ComponentModifier
{
public:
	ComponentModifier(Entity* modifierEntity);
	virtual ~ComponentModifier() = default;

	virtual bool attach(Entity* e) = 0;
	virtual void apply() = 0;
	virtual void remove() = 0;
};

template <class ComponentType>
class ConcreteComponentModifier : public ComponentModifier
{
public:
	ConcreteComponentModifier()
	:	_component(nullptr) {}
	virtual ~ConcreteComponentModifier() = default;

	virtual bool attach(Entity* e)
	{
		_component = e->getComponent<ComponentType>();

		if(_component)
		{
			return true;
		}
		return false;
	}

	virtual void apply()
	{
		modify(_component);
	}
	virtual void remove()
	{
		unmodify(_component);
	}

	virtual void modify(ComponentType* c) = 0;
	virtual void unModify(ComponentType* c) = 0;

protected:
	ComponentType* _component;
};


#endif /* ECS_COMPONENT_MODIFIER_HPP_ */
