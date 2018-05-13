#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#define _USE_MATH_DEFINES
#include <math.h>
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <cmath>

class Circle 
{
    public:
    Circle();
    Circle(float r_, Vec2 const& v_);
    Circle(float r_, Vec2 const& v_, Color const& f_);

    void set_radius(float r_);
    float get_radius() const;
    float get_area() const; //Flächeninhalt
    float get_circumference() const; //Kreisumfang
    float get_diameter() const; //Durchmesser

    void draw(Window const& win) const;
    void draw(Window const& win, Color const& c_) const;

    bool is_Inside(Vec2 const& v_) const;
    void fill(Window const& win);
    void fill(Window const& win, Color const& c);






    private:
    float r_;
    Vec2 v_;
    Color f_;
};

#endif