#include <cmath>

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
};

struct Geometry {
    Kind kind;
    Point2D begin, end;
};

Double distance(Geometry g1, Geometry g2)
{
    // Placeholder implementation
    return Double { 0.0 };
}
