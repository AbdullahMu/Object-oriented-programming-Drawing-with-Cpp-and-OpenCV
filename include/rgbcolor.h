#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include "color.h"

class RGBColor : public Color
{
public:
    explicit RGBColor(unsigned char r, unsigned char g, unsigned char b) : m_r(r), m_g(g), m_b(b) {}
    void changeColor(unsigned char r, unsigned char g, unsigned char b)
    {
        m_r = r;
        m_g = g;
        m_b = b;
    }
    std::array<unsigned char, 3> getRGBColor() const override
    {
        return {m_r, m_g, m_b};
    }
    unsigned char getBWColor() const override { return (m_r + m_g + m_b) / 3; }

private:
    unsigned char m_r;
    unsigned char m_g;
    unsigned char m_b;
};

#endif //RGBCOLOR_H