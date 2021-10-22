#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"
#include "color.h"
#include "bwcolor.h"
#include "rgbcolor.h"

#include <vector>
#include <iostream>
#include <math.h>


class Shape
{
public:
    Shape(){};
    virtual ~Shape() { delete m_color; }
    std::vector<Point> getPoints() const { return m_points; }
    const Color *getColor() const { return m_color; }

protected:
    Shape(const BWColor &color) { m_color = new BWColor(color); }
    Shape(const RGBColor &color) { m_color = new RGBColor(color); }

protected:
    std::vector<Point> m_points;
    Color *m_color;
};

#endif // SHAPE_H
