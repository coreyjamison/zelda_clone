/*
 * coords.hpp
 *
 *  Created on: Jul 31, 2014
 *      Author: Corey
 */

#ifndef VEC2_HPP_
#define VEC2_HPP_

#include <cmath>
#include <type_traits>

/*
 * Vec2
 *
 * 2-dimensional vector with x and y components.
 *
 * num_type should be a numerical type, otherwise behaviour is undefined.
 */
template <typename num_type>
struct Vec2
{
	Vec2()
	:	x( 0 ),
		y( 0 )
	{}

	Vec2( num_type initX, num_type initY )
	:	x( initX ),
	 	y( initY )
	{}

	/*
	 * Gets the euclidean length of the vector.
	 *
	 * @return The length of the vector.
	 */
	num_type length() const
	{
		return sqrt( x * x + y * y );
	}

	/*
	 * Returns a new vector scaled to a new length.
	 *
	 * @param newLength The length to scale the vector to.
	 * @return The new vector.
	 */
	Vec2 scale( num_type newLength ) const
	{
		double len = length();
		if( len != 0 )
		{
			double newX = x * newLength / len;
			double newY = y * newLength / len;
			return Vec2( newX, newY );
		}
		else
		{
			return *this;
		}
	}

	/*
	 * Returns a new vector, scaled back to a maximum length.
	 *
	 * @param newLength The maximum length of the new vector.
	 * @return The new vector.
	 */
	Vec2 scaleBack( num_type newLength ) const
	{
		double myDist = length();
		if( myDist > newLength && myDist > 0 )
		{
			double newX = x * newLength / myDist;
			double newY = y * newLength / myDist;
			return Vec2( newX, newY );
		}
		else
		{
			return *this;
		}
	}

	/*
	 * Returns a new vector that is the average of this and the other vector.
	 *
	 * @param other The other vector.
	 * @return A new averaged vector.
	 */
	Vec2 average( const Vec2& other) const
	{
		return {(x + other.x) / 2, (y + other.y) / 2};
	}

	/*
	 * Returns the dot product of this vector with another vector.
	 *
	 * @param other The other vector.
	 * @return The result of the dot product.
	 */
	num_type dot( const Vec2& other ) const
	{
		return x * other.x + y * other.y;
	}

	/*
	 * Standard arithmetic operators.
	 */
	Vec2 operator+( const Vec2& other ) const
	{
		return Vec2( x + other.x, y + other.y );
	}

	Vec2 operator+=( const Vec2& other )
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2 operator-( const Vec2& other ) const
	{
		return Vec2( x - other.x, y - other.y );
	}

	Vec2 operator-=( const Vec2& other )
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vec2 operator*( const num_type multFactor ) const
	{
		return Vec2( x * multFactor, y * multFactor );
	}

	Vec2 operator*=( const num_type multFactor )
	{
		x *= multFactor;
		y *= multFactor;
		return *this;
	}

	Vec2 operator/( const num_type divisor ) const
	{
		return Vec2( x / divisor, y / divisor );
	}

	Vec2 operator/=( const num_type divisor )
	{
		x /= divisor;
		y /= divisor;
		return *this;
	}

	/*
	 * Standard comparison operators
	 */
	bool operator==( const Vec2& other ) const
	{
		return ( x == other.x ) && ( y == other.y );
	}

	Vec2 operator=( const Vec2& other )
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	bool operator!=( const Vec2& other ) const
	{
		return ( x != other.x ) && ( y != other.y );
	}

	num_type x;
	num_type y;
};



#endif /* VEC2_HPP_ */
