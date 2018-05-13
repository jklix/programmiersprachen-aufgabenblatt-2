#include "vec2.hpp"
#include <iostream>


Vec2::Vec2():  //Standard Konstruktor
x_(0),
y_(0)
{};

Vec2::Vec2(float x, float y): // Konstruktor
x_(x),
y_(y)
{};

Vec2& Vec2 :: operator +=(Vec2 const& v) //Addition Aufgabe 2.3
{
    x_ += v.x_;
    y_ += v.y_;
    return *this;
};


Vec2& Vec2 :: operator -=(Vec2 const& v) //Subtraktion Aufgabe 2.3
{
    x_ -= v.x_;
    y_ -= v.y_;
    return *this;
};

Vec2& Vec2 :: operator *= (float s)  // Multiplikation Aufgabe 2.3
{
    x_ *= s;
    y_ *= s;
    return *this;
};

Vec2& Vec2 :: operator /=(float s)  // Division Aufgabe 2.3
{
    if (s == 0.0)
    {
        std::cout <<"Nicht möglich durch 0 zu teilen." <<std::endl;
    } 
    else
    {
        x_ /= s;
        y_ /= s;
    }
    return *this;
};

//Aufgabe 2.4

Vec2 operator + (Vec2 const& u, Vec2 const& v)
{
    /*Vec2 result;
    result.operator+=(v);
    return result;*/ 
    
    Vec2 result;
    result.x_ = u.x_ + v.x_;
    result.y_ = u.y_ + v.y_;
    return result;
};

Vec2 operator - (Vec2 const& u, Vec2 const& v)
{
    Vec2 result;
    result.x_ = u.x_ - v.x_;
    result.y_ = u.y_ - v.y_;
    return result;
};

Vec2 operator * (Vec2 const& v, float s)
{
    Vec2 result;
    result.x_ = v.x_ * s;
    result.y_ = v.y_ * s;
    return result;
};

Vec2 operator / (Vec2 const& v, float s)
{
    Vec2 result;

    if (s == 0.0f)
    {
        std::cout <<"Nicht möglich durch 0 zu teilen." <<std::endl;
    }
    else
    {
        result.x_ = v.x_ / s;
        result.y_ = v.y_ / s;
    }
    return result;
};

Vec2 operator * (float s, Vec2 const& v)
{
    Vec2 result;
    result.x_ = v.x_ * s;
    result.y_ = v.y_ * s;
    return result;
};
