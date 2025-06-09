#include "point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}

static float computeDeterminant(Point const a, Point const b, Point const c)
{
    float ax = a.getX().toFloat();
    float ay = a.getY().toFloat();
    float bx = b.getX().toFloat();
    float by = b.getY().toFloat();
    float cx = c.getX().toFloat();
    float cy = c.getY().toFloat();

    return (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
}

static Fixed area(Point const a, Point const b, Point const c)
{
    float det = computeDeterminant(a, b, c);
    float absArea = det < 0 ? -det : det;
    return Fixed(absArea / 2.0f);
}


bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed totalArea = area(a, b, c);
	Fixed area1 = area(point, b, c);
	Fixed area2 = area(a, point, c);
	Fixed area3 = area(a, b, point);

	if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
		return false;

	return (area1 + area2 + area3 == totalArea);
}

