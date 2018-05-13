#include "circle.hpp"
#include <iostream>
#include "window.hpp"


Circle::Circle():
r_(50),
v_(50, 50),
f_()
{};

Circle::Circle(float r_, Vec2 const& v_):
r_(r_),
v_(v_)
{};

Circle::Circle(float r_, Vec2 const& v_, Color const& f_):
r_(r_),
v_(v_),
f_(f_)
{};



void Circle::set_radius(float r) //Radius
{
    if(r == 0)
    {
        std::cout<< "Der Kreis braucht einen Radius."<<std::endl;
    }
    else
    {
        r_ = r;
    }
};

float Circle::get_radius() const
{
    return r_;
};

float Circle::get_area() const//Flächeninhalt
{
    return M_PI * r_ * r_;
};

float Circle::get_circumference() const //Umfang
{
    return M_PI * r_ * 2;
};

float Circle::get_diameter() const //Durchmesser
{
    return 2 * r_;
};

void Circle::draw(Window const& win) const

{
    Vec2 begin;
    Vec2 end;

    for(int i = 0; i <= 360; i++)
    {
        begin = {(float) cos(i*(2*M_PI/360))*r_, (float) sin(i*(2*M_PI/360))*r_};
        end = {(float) cos((i+1)*(2*M_PI/360))*r_, (float) sin((i+1)*(2*M_PI/360))*r_};

        win.draw_line(begin.x_ + v_.x_, begin.y_ + v_.y_, end.x_ + v_.x_, end.y_ + v_.y_, f_.r_, f_.g_, f_.b_);
    }

    /*for (float i = 0.0; i < 2 * M_PI; i += 0.001)
    {
        win.draw_point(v_.x_ + r_ * cos(i), v_.y_ + r_ * sin(i), f_.r_, f_.g_, f_.b_);
    }*/
};

void Circle::draw(Window const& win, Color const& c) const
{
    Vec2 begin;
    Vec2 end;
    

    for(int i = 0; i <= 360; i++)
    {
        begin = {(float) cos(i*(2*M_PI/360))*r_, (float) sin(i*(2*M_PI/360))*r_};
        end = {(float) cos(i*(2*M_PI/360))*r_, (float) sin(i*(2*M_PI/360))*r_};

        win.draw_line(begin.x_ + v_.x_, begin.y_ + v_.y_, end.x_ + v_.x_, end.y_ + v_.y_, c.r_, c.g_, c.b_);
    }
    
    /*for (float i = 0.0; i < 2 * M_PI; i += 0.001)
    {
        win.draw_point(v_.x_ + r_ * cos(i), v_.y_ + r_ * sin(i), c.r_, c.g_, c.b_);
    }*/
};

bool Circle::is_Inside(Vec2 const& w) const
{
    if(sqrt((w.x_ - v_.x_) * (w.x_ - v_.x_) + (w.x_ - v_.x_) * (w.x_ - v_.x_)) < r_)
    {
        return true;

    }
    else
    {
        return false;
    }
};



void Circle::fill(Window const& win) 
{
    for(float y_ = - r_; y_ < r_; y_ += 0.001)
    {
        for(float x_ = -r_; x_ < r_; x_ += r_ += 0.001)
        {
            if(sqrt(x_ * x_ + y_ * y_) < r_)win.draw_point(x_ + v_.x_, y_ + v_.y_, f_.r_, f_.g_,f_.b_);
        }
    }
    for (float i = 0.0; i < 2 * M_PI; i += 0.001)
    {
        win.draw_point(v_.x_ + r_ * cos(i), v_.y_ + r_ * sin(i), f_.r_, f_.g_, f_.b_);
    }
};