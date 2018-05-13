#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle 
{
    public:

    Rectangle();
    Rectangle(Vec2 const& min_, Vec2 const& max_, float l_);
    Rectangle(Vec2 const& v_, float width, float height);
    Rectangle(Vec2 const& v_, float width, float height, Color const& f_);


    void set_height(float h_);
    void set_width(float w_);
    
    float get_l_();
    float get_height() const; //Höhe
    float get_width() const; //Breite
    float get_perimeter() const; //Umfang
    float get_area() const; //Flächeninhalt

    void draw(Window const& win) const;
    void draw(Window const& win, Color const& c_) const;
    bool is_Inside(Vec2 const& w_) const;


    private:
    
    Vec2 v_;
    float width;
    float height;
    Vec2 min_;
    Vec2 max_;
    float l_;
    Color f_;

};


#endif