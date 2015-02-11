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

struct NodeListInterface
{
	virtual ~NodeListInterface() = default;

	virtual void removeInvalids() = 0;
	virtual void addNode(Node* n) = 0;
};

template <typename T>
struct NodeList : public NodeListInterface
{
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
		if(typeid(*n) == typeid(T))
		{
			nodes.push_back(static_cast<T*>(n));
		}
	}

	vector<T*> nodes;
};


#endif /* NODE_LIST_HPP_ */
