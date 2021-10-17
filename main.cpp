#include "matrix.h"
#include "rgb_matrix.h"
#include "bw_matrix.h"
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <iostream>

#include <cstdlib>
#include <ctime>

void mashroom(){
    int bgColor = 255;
    int capColor = 179;
    int stipeColor = 128;
    int bottomColor = 52;
    BWMatrix bw(2000, 2000, 255);
    BWColor bwColor(capColor);
    Circle cap({1000, 1000}, 700, bwColor);
    bwColor.changeColor(bgColor);
    Rectangle background({0, 700}, 2000, 1000, bwColor);
    Rectangle background2({800, 1300}, 400, 200, bwColor);
    bwColor.changeColor(stipeColor);
    Triangle stipe({1000, 350}, {1200, 1500}, {800, 1500}, bwColor);
    bwColor.changeColor(capColor);
    Rectangle background3({800, 350}, 400, 350, bwColor);
    bwColor.changeColor(bottomColor);
    Circle bottom({1000, 1500}, 200, bwColor);

    bw.draw(cap);
    bw.draw(background);
    bw.draw(bottom);
    bw.draw(background2);
    bw.draw(stipe);
    bw.draw(background3);
    // bw.display();
    bw.saveImage("mashroom");
}

int main()
{
    RGBMatrix rgb;
    BWMatrix bw;
    bw.readImage("images/hse_bw.png");
    rgb.readImage("images/hse_rgb.png");
    bw.saveImage("first");
    rgb.saveImage("second");

    BWMatrix inverted = bw.invert();
    inverted.saveImage("third");
    BWMatrix newBW = rgb.toBW();
    newBW.saveImage("fourth");

    mashroom();

    std::cout << "test test test1\n";
}