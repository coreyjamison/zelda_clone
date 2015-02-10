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
	for(CollisionNode* node1 : _nodes)
	{
		for(CollisionNode* node2 : _nodes) {

			// This ensures each collision is only detected once,
			// and an object can't collide with itself
			if(node1 >= node2)
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

			double overlap = 100;

			// how much to push node 2 away from node 1
			// multiply by -1 to get how much to push node 2
			Vec2<double> push = {0, 0};

			if(l1 < r2 && l2 < r1 && t1 < b2 && t2 < b1)
			{
				cout << "r2 - l1:" << r2 - l1 << endl;
				cout << "r1 - l2:" << r1 - l2 << endl;
				cout << "b2 - t1:" << b2 - t1 << endl;
				cout << "b1 - t2:" << b1 - t2 << endl;
				if(r2 - l1 > 0 && r2 - l1 < overlap)
				{
					overlap = r2 - l1;
					push = {-overlap, 0};
				}
				if(r1 - l2 > 0 && r1 - l2 < overlap)
				{
					overlap = r1 - l2;
					push = {overlap, 0};
				}
				if(b2 - t1 > 0 && b2 - t1 < overlap)
				{
					overlap = b2 - t1;
					push = {0, -overlap};
				}
				if(b1 - t2 > 0 && b1 - t2 < overlap)
				{
					overlap = b1 - t2;
					push = {0, overlap};
				}

				cout << "Pushing by: " << push.x << ", " << push.y << endl;

				if(node1->collision->isStatic && !node2->collision->isStatic)
				{
					cout << "Only pushing node 2!" << endl;
					node2->position->curPos += push;
				}
				else if(!node1->collision->isStatic && node2->collision->isStatic)
				{
					cout << "Only pushing node 1!" << endl;
					node1->position->curPos += (push * -1);
				}
				else
				{
					cout << "Both equal push!" << endl;
					Vec2<double> halfPush = push / 2;
					cout << "Pushing by: " << halfPush.x << ", " << halfPush.y << endl;

					node1->position->curPos += (halfPush * -1);
					node2->position->curPos += (halfPush);
				}

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

