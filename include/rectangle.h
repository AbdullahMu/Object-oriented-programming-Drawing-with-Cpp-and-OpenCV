#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(std::array<int, 2> const &top_left_vertex, int const &width, int const &height, BWColor &color)
        : m_points(fill(top_left_vertex, width, height)), m_color(dynamic_cast<Color *>(&color))
    {
    }

    Rectangle(std::array<int, 2> const &top_left_vertex, int const &width, int const &height, RGBColor &color)
        : m_points(fill(top_left_vertex, width, height)), m_color(dynamic_cast<Color *>(&color))
    {
    }

    std::vector<Point> fill(Point const &vertex, int const &width, int const &height)
    {
        for (int x = vertex.x; x <= vertex.x + width; x++)
        {
            for (int y = vertex.y; y <= vertex.y + height; y++)
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

#endif //RECTANGLE_H