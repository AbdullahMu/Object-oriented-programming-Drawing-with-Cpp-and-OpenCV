#ifndef BWCOLOR_H
#define BWCOLOR_H

#include "color.h"

class BWColor : public Color
{
public:
    explicit BWColor(unsigned char color) : m_color(color) {}
    void changeColor(unsigned char color) { m_color = color; }
    std::array<unsigned char, 3> getRGBColor() const override
    {
        return {m_color, m_color, m_color};
    }
    unsigned char getBWColor() const override { return m_color; }

private:
    unsigned char m_color;
};

#endif //BWCOLOR_H