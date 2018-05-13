#include "mat2.hpp"
#include "vec2.hpp"
#include <iostream>
#include <math.h>

//Standardkonstruktor
Mat2::Mat2(): 
a_(1),
b_(0),
c_(0),
d_(1) 
{};

//Konstruktor
Mat2::Mat2(float a, float b, float c, float d):
a_(a),
b_(b),
c_(c),
d_(d) 
{};

//Aufgabe 2.5

Mat2& Mat2::operator *= (Mat2 const& v)
{
    float atemp, btemp, ctemp, dtemp;

    atemp = a_ * v.a_ + b_ * v.c_;
    btemp = a_ * v.b_ + b_ * v.d_;
    ctemp = c_ * v.a_ + d_ * v.c_;
    dtemp = c_ * v.b_ + d_ * v.d_;

    a_ = atemp,
    b_ = btemp,
    c_ = ctemp,
    d_ = dtemp;

    return *this;
};


Mat2 operator * (Mat2 const& m1, Mat2 const& m2)
{
    Mat2 result;

    result.a_ = m1.a_ * m2.a_ + m1.b_ * m2.c_;
    result.b_ = m1.a_ * m2.b_ + m1.b_ * m2.d_;
    result.c_ = m1.c_ * m2.a_ + m1.d_ * m2.c_;
    result.d_ = m1.c_ * m2.b_ + m1.d_ * m2.d_;

    return result;
};

Mat2 operator * (Mat2 const& m, float z)
{
    Mat2 n{m};
    n.a_ *= z;
    n.b_ *= z;
    n.c_ *= z;
    n.d_ *= z;
    return n;
};

Vec2 operator * (Mat2 const& m, Vec2 const& v)
{
    Vec2 result;
    result.x_ = m.a_ * v.x_ + m.b_ * v.y_;
    result.y_ = m.c_ * v.x_ + m.d_ * v.y_;
    return result;
};

Vec2 operator * (Vec2 const& v, Mat2 const& m)
{
    Vec2 result;
    result.x_ = m.a_ * v.x_ + m.b_ * v.y_;
    result.y_ = m.c_ * v.x_ + m.d_ * v.y_;
    return result;
};

float Mat2::det() const
{
    return a_ * d_ - c_ * b_;
};

Mat2 inverse (Mat2 const& m)
{
    float det = m.det();
    
    if (det != 0.0f)
    {
        Mat2 n{m.d_, -1 * m.b_, -1 * m.c_, m.a_};
        return n * (1 / det);
    }
    else
    {
        std::cout<<"Es gibt kein Inverses"<<std::endl;
        return m;
    }
};

Mat2 transpose (Mat2 const& m)
{
    Mat2 n{m.a_, m.c_, m.b_, m.d_};
    return n;
};

Mat2 make_rotation_mat2 (float phi)
{
    Mat2 m;
    
    m.a_ = cos(phi);
    m.b_ = sin(phi);
    m.c_ = -(sin(phi));
    m.d_ = cos(phi);
    
    return m;
};

