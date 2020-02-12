#include <iostream>


struct Point
{
	float _x;
	float _y;
	Point(float x, float y): _x(x), _y(y) {}
	Point(const Point& p): _x(p._x), _y(p._y) {}
	void operator+=(const Point& p)
	{	
		_x += p._x;
		_y += p._y;
	}
	Point operator+(const Point& p) const
	{
		return {_x + p._x, _y + p._y};
	}
};


class Shape {
    public:
    Shape() : center_point(100, 100) {
        this->ref_count += 1;
    }
    Shape(float center_x, float center_y) : center_point(center_x, center_y) {
        this->ref_count += 1;
    }

    private:
    static int ref_count;

    protected:
    Point center_point;

    public:
    virtual void draw() = 0;
    virtual void move(const Point& vector) = 0;
};

int Shape::ref_count = 0;


class Rectangle : public Shape{
    public:
    Rectangle(const Point& top_left, const Point& bottom_right) : Shape(), top_left(top_left), bottom_right(bottom_right) {
        float center_x = (top_left._x + bottom_right._x) / 2;
        float center_y = (top_left._y + bottom_right._y) / 2;
        this->center_point = Point(center_x, center_y);
    }

    private:
    Point top_left;
    Point bottom_right;

    public:
    virtual void draw() {
        std::cout << "<Rectangle( (" << this->top_left._x << ", " << this->top_left._y << "), (" << this->bottom_right._x << ", " << this->bottom_right._y << ") )>" << std::endl;
    }
    virtual void move(const Point& vector) {
        this->center_point += vector;
        this->top_left += vector;
        this->bottom_right += vector;
    }

};

/*
class Circle : public Shape{
    //...
};

class Path : public Shape{
    //...
};
*/


namespace utils {

void complex_transform(Shape* anything) {
    anything->move(Point(5, 5));
    anything->move(Point(0, 10));
}

void other_transforms(Shape& anything) {
    //...
}

}

int main() {
    Point top_left(10, 10), bottom_right(100, 100);
    Rectangle r = {top_left, bottom_right};
    Shape* s = &r;
    utils::complex_transform(s);
    r.draw();
}
