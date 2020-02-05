struct Point
{
	flost _x;
	float _y;
	Point(float x, float y): _x(x), _y(y) {}
	Point(Point p): _x(p._x), _y(p._y) {}
};


class Shape {
    Shape() : center_point(100, 100) {
        this->ref_count += 1;
    }
    Shape(float center_x, float center_y) : center_point(center_x, center_y) {
        this->ref_count += 1;
    }

    private:
    static int ref_count;
    Point center_point;

    public:
    virtual void draw() {};
};
