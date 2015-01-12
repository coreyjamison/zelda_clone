/*
 * coords.hpp
 *
 *  Created on: Jul 31, 2014
 *      Author: Corey
 */

#ifndef COORDS_HPP_
#define COORDS_HPP_

#include <cmath>

// Don't be a dummy! Only use Vec2 with numerical types!
template <class num_type>
class Vec2
{
public:
	Vec2()
	:	x( 0 ),
		y( 0 )
	{}

	Vec2( num_type initX, num_type initY )
	:	x( initX ),
	 	y( initY )
	{}

	num_type getDist() const
	{
		return sqrt( x * x + y * y );
	}

	Vec2 scale( num_type dist )
	{
		double myDist = getDist();
		if( myDist != 0 )
		{
			double newX = x * dist / myDist;
			double newY = y * dist / myDist;
			return Vec2( newX, newY );
		}
		else
		{
			return *this;
		}
	}

	Vec2 scaleBack( num_type dist )
	{
		double myDist = getDist();
		//printf( "dist: %f, mydist: %f\n", dist, myDist );
		//printf( "old x: %f, y: %f\n", _x, y );
		if( myDist > dist && myDist > 0 )
		{
			double newX = x * dist / myDist;
			double newY = y * dist / myDist;
			return Vec2( newX, newY );
		}
		else
		{
			return *this;
		}
		//printf( "new x: %f, y: %f\n", _x, y );
	}

	num_type dot( const Vec2& other ) const
	{
		return x * other.x + y * other.y;
	}

	Vec2 operator+( const Vec2& other )
	{
		return Vec2( x + other.x, y + other.y );
	}

	Vec2 operator+=( const Vec2& other )
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2 operator-( const Vec2& other )
	{
		return Vec2( x - other.x, y - other.y );
	}

	Vec2 operator-=( const Vec2& other )
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vec2 operator*( const num_type multFactor )
	{
		return Vec2( x * multFactor, y * multFactor );
	}

	Vec2 operator*=( const num_type multFactor )
	{
		x *= multFactor;
		y *= multFactor;
		return *this;
	}

	bool operator==( const Vec2& other )
	{
		return ( x == other.x ) && ( y == other.y );
	}

	Vec2 operator=( const Vec2& other )
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	bool operator!=( const Vec2& other )
	{
		return ( x != other.x ) && ( y != other.y );
	}

	num_type x;
	num_type y;
};



#endif /* COORDS_HPP_ */
