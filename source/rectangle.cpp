#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle():
v_(50, 50),
width(50),
height(50)
{};


Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_, float l_):
min_(min_),
max_(max_)
{};

Rectangle::Rectangle(Vec2 const& v_, float w_, float h_):
v_(v_),
width(w_),
height(h_)
{};

Rectangle::Rectangle(Vec2 const& v_, float w_, float h_, Color const& f_):
v_(v_),
width(w_),
height(h_),
f_(f_)
{};



void Rectangle::set_height(float h_)
{
    height = h_;
};

void Rectangle::set_width(float w_)
{
    width = w_;
};

float Rectangle::get_l_()
{
    l_ = max_.x_ - min_.x_;
    return l_;
};

float Rectangle::get_height() const //Höhe
{
    return height;
};

float Rectangle::get_width() const //Breite
{
    return width;
};

float Rectangle::get_perimeter() const //Umfang
{
    return 2 * (width + height);
};

float Rectangle::get_area() const //Flächeninhalt
{
    return width * height;
};

void Rectangle::draw(Window const& win) const
{
    win.draw_line(v_.x_, v_.y_, width + v_.x_, v_.y_, f_.r_, f_.g_, f_.b_);
    win.draw_line(width + v_.x_, v_.y_, width + v_.x_, height + v_.y_, f_.r_, f_.g_, f_.b_);
    win.draw_line(width + v_.x_, height + v_.y_, v_.x_, height + v_.y_, f_.r_, f_.g_, f_.b_);
    win.draw_line(v_.x_, height + v_.y_, v_.x_, v_.y_, f_.r_, f_.g_, f_.b_);
};

void Rectangle::draw(Window const& win, Color const& c) const
{
    win.draw_line(v_.x_, v_.y_, width + v_.x_, v_.y_, c.r_, c.g_, c.b_);
    win.draw_line(width + v_.x_, v_.y_, width + v_.x_, height + v_.y_, c.r_, c.g_, c.b_);
    win.draw_line(width + v_.x_, height + v_.y_, v_.x_, height + v_.y_, c.r_, c.g_, c.b_);
    win.draw_line(v_.x_, height + v_.y_, v_.x_, v_.y_, c.r_, c.g_, c.b_);
};

bool Rectangle::is_Inside(Vec2 const & w_) const
{
    if(w_.x_ >= v_.x_ && w_.y_ >= v_.y_ && w_.x_ <= v_.x_ + width && w_.x_ <= v_.x_ + height)
    {
        return true;
    }
    else
    {
        return false;
    }
};



