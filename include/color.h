#ifndef COLOR_H
#define COLOR_H

#include <array>

class Color
{
public:
    virtual ~Color() = default;
    virtual std::array<unsigned char, 3> getRGBColor() const = 0;
    virtual unsigned char getBWColor() const = 0;
};

#endif //COLOR_H