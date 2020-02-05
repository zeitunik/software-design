struct Point
{
	flost _x;
	float _y;
	Point(float x, float y): _x(x), _y(y) {}
	Point(Point p): _x(p._x), _y(p._y) {}
};


class Shape {
    private:
    static int ref_count;
    Point center_point;
};
