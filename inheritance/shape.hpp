#ifndef S_HPP
#define S_HPP

class Shape {
	protected:
		int height;
		int width;
	public:
		void set_height(int i);
		void set_width(int i);
		int get_width() const;
		int get_height() const;
		virtual int get_area() const = 0;
	public:
		Shape();
		Shape(int h,int w);
};

class Rectangle : public Shape {
	public:
		int get_area() const;
	public:
		Rectangle();
		Rectangle(int h,int w);
		Rectangle(const Rectangle& s);
		const Rectangle& operator=(const Rectangle& s);
		bool operator==(const Rectangle& s);
};

class Triangle : public Shape {
	public:
		int get_area() const;
	public:
		Triangle();
		Triangle(int h,int w);
		Triangle(const Triangle& s);
		const Triangle& operator=(const Triangle& s);
		bool operator==(const Triangle& s);
};


class Circle : public Shape {
	private:
		int radius;
	public:
		int get_area() const;
	public:
		Circle();
		Circle(int r);
		Circle(const Circle& s);
		const Circle& operator=(const Circle& s);
		bool operator==(const Circle& s);
};
#endif
