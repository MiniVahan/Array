
#pragma once

class Point
{
private:
	int x;
    int y;
    static unsigned int count;
public:
	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;
    static unsigned int get_count();
public:
	Point();
	Point(int x, int y);
	Point(const Point& a);
	const Point& operator=(const Point& b);
	bool operator==(const Point& b);
	bool operator!=(const Point& b);
    ~Point();
};
