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

#endif
