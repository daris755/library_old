struct Point {
    double x = 0, y = 0;

    Point(double a = 0, double b = 0) : x(a), y(b) {}

    // 弧度法
    void rotate(double theta) {
        double new_x = x * cos(theta) - y * sin(theta);
        double new_y = x * sin(theta) + y * cos(theta);
        x = new_x, y = new_y;
    }

    // 大きさ
    double norm() {
        return hypot(x, y);
    }

    // 偏角
    double arg() {
        return atan2(y, x);
    }

    // 内積
    double operator*(const Point &p2) {
        return x * p2.x + y * p2.y;
    }

    Point operator+(const Point &p2) {
        Point ret;
        ret.x = x + p2.x;
        ret.y = y + p2.y;
        return ret;
    }

    Point operator-(const Point &p2) {
        Point ret;
        ret.x = x - p2.x;
        ret.y = y - p2.y;
        return ret;
    }

    friend istream &operator>>(istream &is, Point &p) {
        double a, b;
        is >> a >> b;
        p = Point(a, b);
        return is;
    }

    friend ostream &operator<<(ostream &os, const Point &p) {
        return os << p.x << " " << p.y;
    }
};
