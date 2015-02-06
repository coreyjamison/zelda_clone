/*
 * collision_system.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: Corey
 */

#include <iostream>

#include "collision_system.hpp"

using namespace std;
bool CollisionSystem::run()
{
	// TODO: fix loop
	// Right now, each collision is detected twice:
	// if A and B collide:
	// it's detected with node1 = A, node2 = B AND
	// node1 = B, node2 = A
	for(CollisionNode* node1 : _nodes)
	{
		for(CollisionNode* node2 : _nodes) {
			if(node1 == node2)
				continue;

			//TODO: remove invalid nodes
			if(!node1->valid || !node2->valid)
				continue;

			double l1 = node1->position->curPos.x - (node1->collision->size.x / 2);
			double r1 = node1->position->curPos.x + (node1->collision->size.x / 2);
			double t1 = node1->position->curPos.y - (node1->collision->size.y / 2);
			double b1 = node1->position->curPos.y + (node1->collision->size.y / 2);
			double l2 = node2->position->curPos.x - (node2->collision->size.x / 2);
			double r2 = node2->position->curPos.x + (node2->collision->size.x / 2);
			double t2 = node2->position->curPos.y - (node2->collision->size.y / 2);
			double b2 = node2->position->curPos.y + (node2->collision->size.y / 2);

			if( (	(l1 <= l2 && l2 <= r1) ||
					(l1 <= r2 && r2 <= r1) ) &&
				(	(t1 <= t2 && t2 <= b1) ||
					(t1 <= b2 && b2 <= b1) ) )
			{
				cout << "Collision!" << endl;
				if(node1->collision->mask & node2->collision->type)
				{
					cout << "1 -> 2" << endl;
					// node1 does something to node2
				}
				if(node2->collision->mask & node1->collision->type)
				{
					cout << "2 -> 1" << endl;
					// node2 does something to node1
				}
			}
		}
	}

	return true;
}

void CollisionSystem::onNodeChange(Node* node)
{
	_nodes.push_back(static_cast<CollisionNode*>(node));
}

