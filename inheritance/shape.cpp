#include "shape.hpp"

#include <cmath>

int Circle::get_area() const
{
	return (3.14*pow(radius, 2));
}

const Circle& Circle::operator=(const Circle& r)
{
	radius = r.radius;
	return *this;
}

bool Circle::operator==(const Circle& r)
{
	if (radius==r.radius) {
		return true;
	}
	return false;
}

Circle::Circle()
	: radius(1)
{
}

Circle::Circle(const Circle& r)
{
	*this = r;
}

Circle::Circle(int w)
	: radius(w)
{
}

int Triangle::get_area() const
{
	return (get_height()*get_width()/2);
}

const Triangle& Triangle::operator=(const Triangle& r)
{
	set_height(r.get_height());
	set_width(r.get_width());
	return *this;
}

bool Triangle::operator==(const Triangle& r)
{
	if (get_height()==r.get_height() && get_width()==r.get_width()) {
		return true;
	}
	return false;
}

Triangle::Triangle()
{
	set_height(1);
	set_width(1);
}

Triangle::Triangle(const Triangle& r)
{
	set_height(r.get_height());
	set_width(r.get_width());
}

Triangle::Triangle(int w, int h)
{
	set_height(h);
	set_width(w);
}


int Rectangle::get_area() const
{
	return (get_height()*get_width());
}

const Rectangle& Rectangle::operator=(const Rectangle& r)
{
	set_height(r.get_height());
	set_width(r.get_width());
	return *this;
}

bool Rectangle::operator==(const Rectangle& r)
{
	if (get_height()==r.get_height() && get_width()==r.get_width()) {
		return true;
	}
	return false;
}

Rectangle::Rectangle()
{
	set_height(1);
	set_width(1);
}

Rectangle::Rectangle(const Rectangle& r)
{
	set_height(r.get_height());
	set_width(r.get_width());
}

Rectangle::Rectangle(int w, int h)
{
	set_height(h);
	set_width(w);
}

void Shape::set_height(int i)
{
	height = i;
}

void Shape::set_width(int i)
{
	width = i;
}

int Shape::get_width() const
{
	return width;
}

int Shape::get_height() const
{
	return height;
}

Shape::Shape()
{
	width = 1;
	height = 1;
}

Shape::Shape(int w, int h)
	:width(w)
	,height(h)
{
}
