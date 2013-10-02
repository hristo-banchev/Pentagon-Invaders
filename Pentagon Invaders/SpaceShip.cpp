#define _USE_MATH_DEFINES

#include <math.h>

#include "SpaceShip.h"
#include "Delta.h"

#define PI2 (2 * M_PI)

SpaceShip::SpaceShip()
{
	_vertices = NULL;
	setColor(ColorManager::white);
}

SpaceShip::SpaceShip(const Vector2f center, int radius, int numberOfVertices)
{
	_numberOfVertices = numberOfVertices;
	_radius	= radius;
	_speed = 1.0f;
	_rotationSpeed = 1.0f;
	_rotationAngle = 0.0;
	_center = center;
	_vertices = NULL;

	setColor(ColorManager::white);

	setStats(ShipStatistics());

	generateVertices();
}

SpaceShip::~SpaceShip()
{
	delete[] _vertices;
}

inline void SpaceShip::generateVertices()
{
	if (_vertices != NULL)
	{
		delete[] _vertices;
	}

	_vertices = new Vector2f[_numberOfVertices];

	Vector2f radVect = Vector2f(0.0f, (float)_radius);

	for (int i = 0; i < _numberOfVertices; i++)
	{
		Vector2f direction = radVect.rotate((float) (PI2 * i / _numberOfVertices + _rotationAngle));
		_vertices[i] = _center + direction;
	}
}

void SpaceShip::move(Vector2f& direction)
{
	_center = _center + (direction * _speed * Delta::get());
}

void SpaceShip::rotate(double angle)
{
	_rotationAngle += angle * _rotationSpeed * Delta::get();

	bool recalculate = true;

	while (recalculate)
	{
		if (_rotationAngle > PI2)
		{
			_rotationAngle -= PI2;
		} 
		else if (_rotationAngle < 0.0)
		{
			_rotationAngle += PI2;
		}
		else
		{
			recalculate = false;
		}
	}
}

ShipStatistics SpaceShip::getStats() const
{
	return _stats;
}

void SpaceShip::setStats(const ShipStatistics stats)
{
	_stats = stats;
}

Vector2f* SpaceShip::getVertices() const
{
	Vector2f* clones = new Vector2f[_numberOfVertices];

	for (int i = 0; i < _numberOfVertices; i++)
	{
		clones[i] = _vertices[i];
	}

	return clones;
}

const int SpaceShip::getNumberOfVertices() const
{
	return _numberOfVertices;
}

void SpaceShip::setColor(const Color& color)
{
	_color = &color;
}

const Color& SpaceShip::getColor() const
{
	return *_color;
}