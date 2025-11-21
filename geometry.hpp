#include <cmath>
#include <algorithm>
#include <limits>

const double EPSILON = 1e-9;

struct Double {
    double value;

    bool is_equal(Double other)
    {
        double difference = value - other.value;
        double maximum = std::max(std::fabs(value), std::fabs(other.value));

        if (maximum > 1) {
            difference /= maximum;
        }

        return std::fabs(difference) < EPSILON;
    }

    bool is_less(Double other)
    {
        return (value < other.value) && !is_equal(other);
    }
};

enum class Kind {
    Line,
    Ray,
    Segment
};

struct Point2D {
    Double x, y;

    Point2D sub(Point2D other)
    {
        Double newX = { x.value - other.x.value };
        Double newY { y.value - other.y.value };
        return Point2D { newX, newY };
    }

    Point2D add(Point2D other)
    {
        Double newX = { x.value + other.x.value };
        Double newY { y.value + other.y.value };
        return Point2D { newX, newY };
    }

    Double distance(Point2D other)
    {
        double dx = { x.value - other.x.value };
        double dy = { y.value - other.y.value };
        return Double { std::sqrt(dx * dx + dy * dy) };
    }

    double dot(Point2D other) const {
        return x.value * other.x.value + y.value * other.y.value;
    }

    double cross(Point2D other) const {
        return x.value * other.y.value - y.value * other.x.value;
    }

    double length_sq() const {
        return x.value * x.value + y.value * y.value;
    }

    Point2D mul(double scalar) const {
        return Point2D { {x.value * scalar}, {y.value * scalar} };
    }
};

struct Geometry {
    Kind kind;
    Point2D begin, end;
};

// Расстояние от точки p до геометрического объекта g
Double dist_point_geo(Point2D p, Geometry g) {
    Point2D ab = g.end.sub(g.begin);
    Point2D ap = p.sub(g.begin);

    double ab_len_sq = ab.length_sq();
    
    // Если длина направляющего вектора ~0, объект вырожден в точку
    if (ab_len_sq < EPSILON) {
        return p.distance(g.begin);
    }

    // Проекция точки P на прямую AB: t = (AP * AB) / |AB|^2
    double t = ap.dot(ab) / ab_len_sq;

    // Ограничение t в зависимости от типа геометрии
    if (g.kind == Kind::Segment) {
        if (t < 0.0) t = 0.0;
        else if (t > 1.0) t = 1.0;
    } else if (g.kind == Kind::Ray) {
        if (t < 0.0) t = 0.0;
    }

    // Ближайшая точка на объекте
    Point2D closest = g.begin.add(ab.mul(t));
    return p.distance(closest);
}

Double distance(Geometry g1, Geometry g2)
{
    // Векторы направлений
    Point2D v1 = g1.end.sub(g1.begin);
    Point2D v2 = g2.end.sub(g2.begin);
    
    // Вектор между началами объектов
    Point2D origin_diff = g2.begin.sub(g1.begin);

    double det = v1.cross(v2);

    // 1. Проверка на пересечение
    // P1 + t*V1 = P2 + u*V2
    // t*V1 - u*V2 = P2 - P1
    // По правилу Крамера:
    
    if (std::fabs(det) > EPSILON) {
        double t = origin_diff.cross(v2) / det;
        double u = origin_diff.cross(v1) / det;

        // Попадают ли параметры t и u в допустимые диапазоны
        bool t_valid = false;
        if (g1.kind == Kind::Line) t_valid = true;
        else if (g1.kind == Kind::Ray) t_valid = (t >= -EPSILON);
        else if (g1.kind == Kind::Segment) t_valid = (t >= -EPSILON && t <= 1.0 + EPSILON);

        bool u_valid = false;
        if (g2.kind == Kind::Line) u_valid = true;
        else if (g2.kind == Kind::Ray) u_valid = (u >= -EPSILON);
        else if (g2.kind == Kind::Segment) u_valid = (u >= -EPSILON && u <= 1.0 + EPSILON);

        if (t_valid && u_valid) {
            return Double { 0.0 };
        }
    }

    // 2. Если не пересекаются (или параллельны), расстояние достигается на одной из вершин одного объекта по отношению к другому объекту.
    
    double min_dist_val = std::numeric_limits<double>::infinity();
    Double min_res { min_dist_val };

    auto update_min = [&](Point2D p, Geometry g) {
        Double d = dist_point_geo(p, g);
        if (d.is_less(min_res)) {
            min_res = d;
        }
    };

    // Вершины g1 против объекта g2
    // Line не имеет вершин для проверки (бесконечна), Ray имеет begin, Segment имеет begin и end.
    if (g1.kind != Kind::Line) update_min(g1.begin, g2);
    if (g1.kind == Kind::Segment) update_min(g1.end, g2);

    // Вершины g2 против объекта g1
    if (g2.kind != Kind::Line) update_min(g2.begin, g1);
    if (g2.kind == Kind::Segment) update_min(g2.end, g1);

    // Две параллельные прямые. У них нет вершин и логика выше пропустит этот случай, поэтому нужно проверить любую точку одной прямой против другой.
    if (g1.kind == Kind::Line && g2.kind == Kind::Line) {
        update_min(g1.begin, g2);
    }

    return min_res;
}
