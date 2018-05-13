#ifndef MAT2_HPP
#define MAT2_HPP

#include "vec2.hpp"

// Mat2 definition
struct Mat2
{
    Mat2(); 
    Mat2(float a_, float b_, float c_, float d_); 
    
    Mat2& operator *= (Mat2 const& m);
    
    float det() const;

    float a_;
    float b_;
    float c_;
    float d_;

};

Mat2 operator * (Mat2 const& m1, Mat2 const& m2);
Mat2 operator * (Mat2 const& m, float z);

Vec2 operator * (Mat2 const& m, Vec2 const& v);
Vec2 operator * (Vec2 const& v, Mat2 const& m);

Mat2 inverse (Mat2 const& m);
Mat2 transpose (Mat2 const& m);
Mat2 make_rotation_mat2 (float phi);




# endif