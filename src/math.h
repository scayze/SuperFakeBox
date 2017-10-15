#ifndef MATH_H
#define MATH_H

#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <random>

enum dir
{
	DIR_NONE = -1,
	DIR_LEFT = 0,
	DIR_UP = 1,
	DIR_RIGHT = 2,
	DIR_DOWN = 3
};

class Math
{
private:

public:

	static inline float randomFloat(float from, float to);
	static inline int randomInt(int from, int to);
	static inline sf::Vector2f vectorNormalize(sf::Vector2f v);
	static inline float vectorLength(sf::Vector2f v);
	static inline float vectorLengthSquared(sf::Vector2f v);
	static inline float vectorDistance(sf::Vector2f v1, sf::Vector2f v2);
	static inline float vectorSquaredDistance(sf::Vector2f v1, sf::Vector2f v2);
	static inline sf::Vector2f vectorSetMagnitude(sf::Vector2f, float magnitude);
	static inline float vectorCross(sf::Vector2f v1, sf::Vector2f v2);
	static inline float vectorDot(sf::Vector2f v1, sf::Vector2f v2);
	static inline float vectorProjectOn(sf::Vector2f v1, sf::Vector2f axis);
	static inline sf::Vector2f vectorRotate(sf::Vector2f v, float angle);
	static inline sf::Vector2f vectorRotateToVector(sf::Vector2f v1, sf::Vector2f v2, float angle);
	static inline sf::Vector2f vectorRotateAroundPoint(sf::Vector2f p, sf::Vector2f pivot, float angle);
	static inline float vectorGetRotation(sf::Vector2f p);
	static inline float PI();
	static inline dir vectorGetDirection(sf::Vector2f d);
	static inline sf::Vector2f directionGetVector(dir d);

};

//Get random float in range
float Math::randomFloat(float from, float to)
{
	static std::random_device rd;  // Random device engine, usually based on /dev/random on UNIX-like systems
	static std::mt19937_64 rng(rd());

	std::uniform_real_distribution<float> distribution(from,to);
	return distribution(rng);
}

//Get random int in range
int Math::randomInt(int from, int to)
{
	static std::random_device rd;  // Random device engine, usually based on /dev/random on UNIX-like systems
	static std::mt19937_64 rng(rd());

	std::uniform_int_distribution<int> distribution(from,to);
	return distribution(rng);
}

//Get normalized vector from direction
sf::Vector2f Math::directionGetVector(dir d)
{
	if(d == DIR_UP)
	{
		return sf::Vector2f(0,-1);
	}
	else if(d == DIR_DOWN)
	{
		return sf::Vector2f(0,1);
	}
	else if(d == DIR_RIGHT) return sf::Vector2f(1,0);
	else if(d == DIR_LEFT) return sf::Vector2f(-1,0);
	else
	{
		return sf::Vector2f(0,0);
	}
}

//Get die Distanz zwischen zwei vektoren
float Math::vectorDistance(sf::Vector2f v1, sf::Vector2f v2)
{
	//Satz Pythagoras
	return std::sqrt(std::fabs((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y)));
}

//Get die L�nge des Vektors quadriert
float Math::vectorSquaredDistance(sf::Vector2f v1, sf::Vector2f v2)
{
	//Satz Pythagoras -  sqrt
	return std::fabs((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}

//Get die L�nge des Vektors
float Math::vectorLength(sf::Vector2f v)
{
	return std::sqrt(v.x * v.x + v.y * v.y);
}

//Get die L�nge des Vektors squared
float Math::vectorLengthSquared(sf::Vector2f v)
{
	return v.x * v.x + v.y * v.y;
}

//Bringe Vektor auf die L�nge 1
sf::Vector2f Math::vectorNormalize(sf::Vector2f v)
{
	float length = std::sqrt(v.x * v.x + v.y * v.y);
	v.x = v.x / length;
	v.y = v.y / length;

	return v;
}

//Bringe VEktor auf gew�nschte L�nge
sf::Vector2f Math::vectorSetMagnitude(sf::Vector2f v, float m)
{
	float length = std::sqrt(v.x * v.x + v.y * v.y);
	v.x = v.x / length * m;
	v.y = v.y / length * m;

	return v;
}

//Dot Product of two vectors
float Math::vectorDot(sf::Vector2f v1, sf::Vector2f v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

//Cross Product of two vectors
float Math::vectorCross(sf::Vector2f v1, sf::Vector2f v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}


//Project a Vector on an axis and return the length of the projected vector
float Math::vectorProjectOn(sf::Vector2f v, sf::Vector2f axis)
{
	return vectorDot(v, vectorNormalize(axis));
}

//Rotate Vector
sf::Vector2f Math::vectorRotate(sf::Vector2f v, float angle)
{
	return sf::Vector2f(v.x*cos(angle) - v.y*sin(angle), v.x*sin(angle) + v.y*cos(angle));

	//		   Vector2f(a.x * cos(angle) � a.y * sin(angle), a.x * sin(angle) + a.y * cos(angle));
}
//Rotate Point around another point
sf::Vector2f Math::vectorRotateAroundPoint(sf::Vector2f p, sf::Vector2f pivot, float angle)
{
	return sf::Vector2f(
		cos(angle) * (p.x - pivot.x) - sin(angle) * (p.y - pivot.y) + pivot.x,
		sin(angle) * (p.x - pivot.x) + cos(angle) * (p.y - pivot.y) + pivot.y
	);
}

//Get Rotation of vector (from (0|0))
float Math::vectorGetRotation(sf::Vector2f p)
{
	return atan2(p.y, p.x);
}

//Get den Wert von PI
float Math::PI()
{
	return 3.14159265359f;
}

sf::Vector2f Math::vectorRotateToVector(sf::Vector2f v1, sf::Vector2f v2, float angle)
{
	float r1 = Math::vectorGetRotation(v1) + Math::PI();
	float r2 = Math::vectorGetRotation(v2) + Math::PI();


	if (std::fabs(r1 - r2) < angle || std::fabs(r1 - r2) > Math::PI() * 2 - angle) return v2;


	if (fabs(r1 - r2) < Math::PI())
	{
		if(r1>r2)	return Math::vectorRotate(v1, -angle);
		else		return Math::vectorRotate(v1, angle);
	}
	else
	{
		if (r1>r2)	return Math::vectorRotate(v1, angle);
		else		return Math::vectorRotate(v1, -angle);
	}

}

dir Math::vectorGetDirection(sf::Vector2f d)
{
	if(std::fabs(d.x) > std::fabs(d.y))
	{
		if(d.x>0) return DIR_RIGHT;
		return DIR_LEFT;
	}
	else if(std::fabs(d.x) < std::fabs(d.y))
	{
		if(d.y>0) return DIR_DOWN;
		return DIR_UP;
	}
	return DIR_NONE;
}


#endif 
