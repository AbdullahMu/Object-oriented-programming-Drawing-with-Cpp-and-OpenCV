#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "color.h"
#include "bwcolor.h"
#include "rgbcolor.h"

class Circle : public Shape
{
public:
    // constructors
    Circle(std::array<int, 2> const &center, int const &radius, BWColor &color)
        : m_points(fill(Point(center), radius)), m_color(dynamic_cast<Color *>(&color))
    {
    }
    Circle(std::array<int, 2> const &center, int const &radius, RGBColor &color)
        : m_points(fill(Point(center), radius)), m_color(dynamic_cast<Color *>(&color))
    {
    }

    std::vector<Point> fill(Point const &center, int const &radius)
    {
        for (int x = center.x - radius; x <= center.x + radius; x++)
        {
            for (int y = center.y - radius; y <= center.y + radius; y++)
                if (pow(x - center.x, 2.0) + pow(y - center.y, 2.0) <= pow(radius, 2.0))
                    m_points.push_back(Point({x, y}));
        }
        return m_points;
    }

    std::vector<Point> getPoints() const
    {
        return m_points;
    }
    const Color *getColor() const { return m_color; }

private:
    std::vector<Point> m_points;
    Color *m_color;
};

#endif //CIRCLE_H