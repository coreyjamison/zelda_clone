/*
 * node_list.hpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Corey
 */

#ifndef NODE_LIST_HPP_
#define NODE_LIST_HPP_

#include <algorithm>
#include <vector>

#include "node.hpp"

class Entity;

struct NodeListInterface
{
	virtual ~NodeListInterface() = default;

	virtual void removeInvalids() = 0;
	virtual void addNode(Node* n) = 0;
	virtual void addNodeFromEntity(Entity* e) = 0;
};

template <typename T>
struct NodeList : public NodeListInterface
{
	~NodeList()
	{
		for(T* node : nodes)
		{
			delete node;
		}
	}

	struct NodeValidityChecker : public unary_function<T*, bool>
	{
		bool operator()(T* t) const
		{
			return !t->valid;
		}
	};

	virtual void removeInvalids()
	{
		nodes.erase(remove_if(nodes.begin(), nodes.end(), NodeValidityChecker()), nodes.end());
	}

	virtual void addNode(Node* n)
	{
		if(typeid(*n) == typeid(T) && !haveNode(n->parentId));
		{
			nodes.push_back(static_cast<T*>(n));
		}
	}

	virtual void addNodeFromEntity(Entity* e)
	{
		T* n = T::createFrom(e);
		if(n && !haveNode(e->getId()))
		{
			nodes.push_back(n);
		}
	}

	bool haveNode(unsigned int id)
	{
		for(T* node : nodes)
		{
			if(node->parentId == id)
				return true;
		}
		return false;
	}

	vector<T*> nodes;
};


#endif /* NODE_LIST_HPP_ */
