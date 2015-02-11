/*
 * node_system.hpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Corey
 */

#ifndef NODE_SYSTEM_HPP_
#define NODE_SYSTEM_HPP_

#include "node_list.hpp"

template <typename T>
class NodeSystem
{
public:
	void setNodeList(NodeList<T>* nodes)
	{
		_nodes = nodes;
	}

protected:
	NodeList<T>* _nodes;
};



#endif /* NODE_SYSTEM_HPP_ */
