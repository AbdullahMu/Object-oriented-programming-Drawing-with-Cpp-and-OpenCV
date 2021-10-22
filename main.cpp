#include "matrix.h"
#include "rgb_matrix.h"
#include "bw_matrix.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

void mushroom()
{
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

    bw.saveImage("MUSHROOM_SAMPLE");
}

void house()
{
    RGBMatrix rgb(2000, 2000, 0);
    RGBColor rgbColor(102, 205, 255);
    Rectangle sky({0, 0}, 2000, 1500, rgbColor);
    rgbColor.changeColor(0, 153, 0);
    Rectangle grass({0, 1500}, 2000, 2000, rgbColor);
    rgbColor.changeColor(255, 255, 0);
    Circle sun({50, 50}, 300, rgbColor);
    Triangle ray1({360, 50}, {550, 30}, {550, 70}, rgbColor);
    Triangle ray2({270, 270}, {420, 360}, {390, 400}, rgbColor);
    Triangle ray3({50, 360}, {30, 550}, {70, 550}, rgbColor);
    rgbColor.changeColor(102, 51, 0);
    Rectangle wall({600, 900}, 1000, 800, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Rectangle flue({1300, 550}, 100, 200, rgbColor);
    rgbColor.changeColor(51, 0, 0);
    Triangle roof({560, 900}, {1100, 500}, {1640, 900}, rgbColor);
    rgbColor.changeColor(204, 102, 0);
    Rectangle door({1400, 1350}, 150, 300, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Circle knob({1535, 1500}, 6, rgbColor);
    rgbColor.changeColor(102, 163, 255);
    Rectangle window1({700, 950}, 300, 350, rgbColor);
    Rectangle window2({1200, 950}, 300, 350, rgbColor);

    rgb.draw(sky);
    rgb.draw(grass);
    rgb.draw(sun);
    rgb.draw(ray1);
    rgb.draw(ray2);
    rgb.draw(ray3);
    rgb.draw(wall);
    rgb.draw(flue);
    rgb.draw(roof);
    rgb.draw(door);
    rgb.draw(knob);
    rgb.draw(window1);
    rgb.draw(window2);

    rgb.saveImage("HOUSE_SAMPLE");

    // rgb.display();
}

void my_letter_A()
{
    int bgColor = 255;
    int capColor = 179;
    int stipeColor = 128;
    int bottomColor = 52;
    BWMatrix bw(2000, 2000, 255);
    BWColor bwColor(capColor);
    
    Triangle outter_frame({1000, 250}, {1700, 1800}, {200, 1800}, 0);
    Triangle inner({1000, 750}, {1500, 2000}, {400, 2000}, 255);
    Rectangle bar({600, 1250}, 800, 200, 0);
    

    bw.draw(outter_frame);
    bw.draw(inner);
    bw.draw(bar);
    // bw.display();

    bw.saveImage("MY_A");
}

void my_rainbow_image()
{

    RGBMatrix rgb(108, 192, 0);

    // sky
    RGBColor rgbColor(148, 228, 244);
    Rectangle sky({0, 0}, 192, 108, rgbColor);

    // red spectrum in rainbow
    rgbColor.changeColor(255, 26, 0);
    Circle red_spectrum({120, 120}, 130, rgbColor);

    // orange spectrum in rainbow
    rgbColor.changeColor(255, 141, 0);
    Circle orange_spectrum({120, 120}, 120, rgbColor);

    // yellow spectrum in rainbow
    rgbColor.changeColor(227, 255, 0);
    Circle yellow_spectrum({120, 120}, 110, rgbColor);

    // green spectrum in rainbow
    rgbColor.changeColor(0, 255, 4);
    Circle green_spectrum({120, 120}, 100, rgbColor);

    // blue spectrum in rainbow
    rgbColor.changeColor(0, 81, 255);
    Circle blue_spectrum({120, 120}, 90, rgbColor);

    // clipping the rainbow!
    rgbColor.changeColor(148, 228, 244);
    Circle clipping_sky({120, 120}, 80, rgbColor);

    rgb.draw(sky);
    rgb.draw(red_spectrum);
    rgb.draw(orange_spectrum);
    rgb.draw(yellow_spectrum);
    rgb.draw(green_spectrum);
    rgb.draw(blue_spectrum);
    rgb.draw(clipping_sky);

    rgb.saveImage("MY_RAINNBOW_IMAGE");

    // rgb.display();
}

void house_with_rain_bow(){

    RGBMatrix rgb(2000, 2000, 0);
    RGBColor rgbColor(148, 228, 244);
    Rectangle sky({0, 0}, 2000, 1500, rgbColor);
    rgbColor.changeColor(0, 153, 0);
    Rectangle grass({0, 1500}, 2000, 2000, rgbColor);
    rgbColor.changeColor(255, 255, 0);
    Circle sun({50, 50}, 300, rgbColor);
    Triangle ray1({360, 50}, {550, 30}, {550, 70}, rgbColor);
    Triangle ray2({270, 270}, {420, 360}, {390, 400}, rgbColor);
    Triangle ray3({50, 360}, {30, 550}, {70, 550}, rgbColor);
    rgbColor.changeColor(102, 51, 0);
    Rectangle wall({600, 900}, 1000, 800, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Rectangle flue({1300, 550}, 100, 200, rgbColor);
    rgbColor.changeColor(51, 0, 0);
    Triangle roof({560, 900}, {1100, 500}, {1640, 900}, rgbColor);
    rgbColor.changeColor(204, 102, 0);
    Rectangle door({1400, 1350}, 150, 300, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Circle knob({1535, 1500}, 6, rgbColor);
    rgbColor.changeColor(102, 163, 255);
    Rectangle window1({700, 950}, 300, 350, rgbColor);
    Rectangle window2({1200, 950}, 300, 350, rgbColor);

    

    // red spectrum in rainbow
    rgbColor.changeColor(255, 26, 0);
    Circle red_spectrum({2400, 2400}, 2600, rgbColor);

    // orange spectrum in rainbow
    rgbColor.changeColor(255, 141, 0);
    Circle orange_spectrum({2400, 2400}, 2500, rgbColor);

    // yellow spectrum in rainbow
    rgbColor.changeColor(227, 255, 0);
    Circle yellow_spectrum({2400, 2400}, 2400, rgbColor);

    // green spectrum in rainbow
    rgbColor.changeColor(0, 255, 4);
    Circle green_spectrum({2400, 2400}, 2300, rgbColor);

    // blue spectrum in rainbow
    rgbColor.changeColor(0, 81, 255);
    Circle blue_spectrum({2400, 2400}, 2200, rgbColor);

    // clipping the rainbow!
    rgbColor.changeColor(148, 228, 244);
    Circle clipping_sky({2400, 2400}, 2100, rgbColor);

    rgb.draw(sky);
    rgb.draw(red_spectrum);
    rgb.draw(orange_spectrum);
    rgb.draw(yellow_spectrum);
    rgb.draw(green_spectrum);
    rgb.draw(blue_spectrum);
    rgb.draw(clipping_sky);

    rgb.draw(grass);
    rgb.draw(sun);
    rgb.draw(ray1);
    rgb.draw(ray2);
    rgb.draw(ray3);
    rgb.draw(wall);
    rgb.draw(flue);
    rgb.draw(roof);
    rgb.draw(door);
    rgb.draw(knob);
    rgb.draw(window1);
    rgb.draw(window2);

    rgb.saveImage("HOUSE_WITH_RAINBOW");
}

    int
    main()
{
    try
    {
        // mushroom();
        // house();
        my_rainbow_image();
        // // my_letter_A();

        // house_with_rain_bow();

        std::cout
            << "code has been sucessfuly executed! \n";
    }
    catch (...)
    {
    }
}
