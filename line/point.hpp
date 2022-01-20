
#pragma once

class Point
{
private:
	int x;
    int y;
public:
	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;
public:
	Point();
	Point(int x, int y);
	Point(const Point& a);
	const Point& operator=(const Point& b);
};
