#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape
{
public:
    // constructors

    Triangle(std::array<int, 2> const &vertex1, std::array<int, 2> const &vertex2, std::array<int, 2> const &vertex3, BWColor &color)
        : m_points(fill(Point(vertex1), Point(vertex2), Point(vertex3))), m_color(dynamic_cast<Color *>(&color))
    {
    }

    Triangle(std::array<int, 2> const &vertex1, std::array<int, 2> const &vertex2, std::array<int, 2> const &vertex3, RGBColor &color)
        : m_points(fill(Point(vertex1), Point(vertex2), Point(vertex3))), m_color(dynamic_cast<Color *>(&color))
    {
    }

    std::vector<Point> fill(Point const &A, Point const &B, Point const &C)
    {
        Point p_0 = topLeftBoundingPoint(A, B, C);
        Point p_1 = bottomRightBoundingPoint(A, B, C);
        Point P;

        float S_ABC = getArea(A, B, C);

        for (int x = p_0.x; x <= p_1.x; x++)
        {
            for (int y = p_0.y; y <= p_1.y; y++)
            {
                P = Point({x, y});
                float S_ABP = getArea(A, B, P);
                float S_BCP = getArea(B, C, P);
                float S_CAP = getArea(C, A, P);

                if (S_ABC == S_ABP + S_BCP + S_CAP)
                    m_points.push_back(Point({x, y}));
            }
        }
        return m_points;
    }

    float getArea(Point const &p1, Point const &p2, Point const &p3) const
    {
        float area = (1.0 / 2.0) * fabs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
        return area;
    }

    Point topLeftBoundingPoint(Point const &vertex1, Point const &vertex2, Point const &vertex3) const
    {
        int x_topLeft = vertex1.x;
        for (int x : {vertex1.x, vertex2.x, vertex3.x})
        {
            if (x_topLeft > x)
                x_topLeft = x;
        }

        int y_topLeft = vertex1.y;
        for (int y : {vertex1.y, vertex2.y, vertex3.y})
        {
            if (y_topLeft > y)
                y_topLeft = y;
        }

        return Point({x_topLeft, y_topLeft});
    }

    Point bottomRightBoundingPoint(Point const &vertex1, Point const &vertex2, Point const &vertex3) const
    {
        int x_bottomRight = vertex1.x;
        for (int x : {vertex1.x, vertex2.x, vertex3.x})
        {
            if (x_bottomRight < x)
                x_bottomRight = x;
        }

        int y_bottomRight = vertex1.y;
        for (int y : {vertex1.y, vertex2.y, vertex3.y})
        {
            if (y_bottomRight < y)
                y_bottomRight = y;
        }

        return Point({x_bottomRight, y_bottomRight});
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

#endif //TRIANGLE_H