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
	for(CollisionNode* node1 : _nodes->nodes)
	{
		for(CollisionNode* node2 : _nodes->nodes) {

			// This ensures each collision is only detected once,
			// and an object can't collide with itself
			if(node1 >= node2)
				continue;

			if(!node1->valid || !node2->valid)
				continue;

			bool n1ignore = node1->collision->ignoredIds.find(node2->collision->parentId) != node1->collision->ignoredIds.end();
			bool n2ignore = node2->collision->ignoredIds.find(node1->collision->parentId) != node2->collision->ignoredIds.end();

			if(n1ignore || n2ignore)
			{
				cout << "Node1 ignored ids: " << endl;
				for(unsigned int id : node1->collision->ignoredIds)
				{
					cout << id << " ";
				}
				cout << endl << "Node2 ignored ids: " << endl;
				for(unsigned int id : node2->collision->ignoredIds)
				{
					cout << id << " ";
				}
				continue;
			}

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

				if(node1->collision->weight != -1 && node2->collision->weight != -1)
				{
					double node2Fraction = static_cast<double>(node1->collision->weight) /
							static_cast<double>(node2->collision->weight + node1->collision->weight);
					node1->position->curPos += (push * (node2Fraction - 1));
					node2->position->curPos += (push * node2Fraction);
				}
				else if(node1->collision->weight != -1)
				{
					node1->position->curPos += (push * -1);
				}
				else if(node2->collision->weight != -1)
				{
					node2->position->curPos += push;
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

