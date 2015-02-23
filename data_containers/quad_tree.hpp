/*
 * quad_tree.hpp
 *
 *  Created on: Feb 21, 2015
 *      Author: Corey
 */

#ifndef DATA_CONTAINERS_QUAD_TREE_HPP_
#define DATA_CONTAINERS_QUAD_TREE_HPP_

#include <vector>

#include "vec2.hpp"

#include <iostream>
using namespace std;

class QuadTreeObject {
public:
	virtual ~QuadTreeObject() = default;

	virtual double getLeft() = 0;
	virtual double getRight() = 0;
	virtual double getTop() = 0;
	virtual double getBottom() = 0;
};

using namespace std;
template <class T>
class QuadTree {
public:
	QuadTree(int level, int maxLevel, int maxPerLevel, double x, double y, double w, double h)
	:	_level(level), _maxLevel(maxLevel), _maxPerLevel(maxPerLevel), _divided(false),
		_x(x), _y(y), _w(w), _h(h),
		_NW(nullptr), _NE(nullptr), _SW(nullptr), _SE(nullptr),
		_objects()
	{}

	~QuadTree()
	{
		if(_divided)
		{
			delete _NW;
			delete _NE;
			delete _SW;
			delete _SE;
		}
	}

	bool contains(T* obj)
	{
		return _x <= obj->getRight() &&
				obj->getLeft() <= _x+_w &&
				_y <= obj->getBottom() &&
				obj->getTop() <= _y+_h;
	}

	void insert(T* obj)
	{
		if(_divided)
		{
			cout << "divided, so insert into children" << endl;
			_NW->insert(obj);
			_NE->insert(obj);
			_SW->insert(obj);
			_SE->insert(obj);
		}
		else
		{
			if(contains(obj))
				_objects.push_back(obj);
			if(_objects.size() >= _maxPerLevel)
				subdivide();
		}
	}


	void subdivide()
	{
		if(_level == _maxLevel)
		{
			cout << "at max level - won't subdivide!" << endl;
			return;
		}

		if(_divided)
		{
			cout << "already divided! subdivide children!" << endl;
			_NW->subdivide();
			_NE->subdivide();
			_SW->subdivide();
			_SE->subdivide();
		}
		else
		{
			cout << "dividing!" << endl;
			_NW = new QuadTree(_level+1, _maxLevel, _maxPerLevel, _x, _y, _w/2, _h/2);
			_NE = new QuadTree(_level+1, _maxLevel, _maxPerLevel, _x+_w/2, _y, _w/2, _h/2);
			_SW = new QuadTree(_level+1, _maxLevel, _maxPerLevel, _x, _y+_h/2, _w/2, _h/2);
			_SE = new QuadTree(_level+1, _maxLevel, _maxPerLevel, _x+_w/2, _y+_h/2, _w/2, _h/2);
			_divided = true;

			for(auto obj : _objects)
			{
				_NW->insert(obj);
				_NE->insert(obj);
				_SW->insert(obj);
				_SE->insert(obj);
			}
			_objects.clear();
		}
	}

	vector<pair<T*, T*>> getCollisions()
	{
		vector<pair<T*, T*>> collisions;
		if(_divided)
		{
			auto nw = _NW->getCollisions();
			auto ne = _NE->getCollisions();
			auto sw = _SW->getCollisions();
			auto se = _SE->getCollisions();
			collisions.insert(collisions.end(), nw.begin(), nw.end());
			collisions.insert(collisions.end(), ne.begin(), ne.end());
			collisions.insert(collisions.end(), sw.begin(), sw.end());
			collisions.insert(collisions.end(), se.begin(), se.end());
		}
		else
		{
			for(auto obj1 : _objects)
			{
				for(auto obj2 : _objects)
				{
					/* no duplicates */
					if(obj1 < obj2)
						collisions.push_back({obj1, obj2});
				}
			}
		}
		return collisions;
	}

private:
	int _level;
	int _maxLevel;
	int _maxPerLevel;
	bool _divided;

	double _x;
	double _y;
	double _w;
	double _h;

	QuadTree* _NW;
	QuadTree* _NE;
	QuadTree* _SW;
	QuadTree* _SE;

	vector<T*> _objects;
};



#endif /* DATA_CONTAINERS_QUAD_TREE_HPP_ */
