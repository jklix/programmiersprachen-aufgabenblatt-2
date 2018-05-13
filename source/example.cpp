#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};



  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    std::vector<Circle> kreis;
    std::vector<Rectangle> rechteck;

    
    Vec2 p_ = {400.0f, 400.0f};
    Color e_ = {1.0f, 0.0f, 1.0f};

    Rectangle r {p_, 100.0f, 100.0f, e_};
    r.draw(win, e_);

    Circle kr {270, p_};
    kr.draw(win);

    //Rechteck
    //rechteck[1] = {p_, 100.0f, 100.0f, e_};
    /*rechteck[1].draw(win);

    
    //Kreis
    kreis[1] = {100.0f, p_, e_};
    kreis[1].draw(win);
    */
    



    //Uhr
    float z = win.get_time();
    float sek = z;
    float min = z/60;
    float stu = z / 3600;

    float winkel = - M_PI * 2 / 60;

    Vec2 mi = {400.0f ,400.0f};
    Color c = {0.0f, 0.0f, 0.0f};

    Circle uhr = {200, mi, c};
    uhr.draw(win);

    win.draw_line(400.0, 400.0f, 400.0f -sin(winkel * sek) * 200.0f, 400.0f - cos(winkel * sek) * 200.0f, 0.0f, 0.0f, 0.0f);
    win.draw_line(400.0, 400.0f, 400.0f -sin(winkel * min) * 160.0f, 400.0f - cos(winkel * min) * 160.0f, 0.0f, 0.0f, 0.0f);
    win.draw_line(400.0, 400.0f, 400.0f -sin(winkel * stu) * 100.0f, 400.0f - cos(winkel * stu) * 100.0f, 0.0f, 0.0f, 0.0f);





    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    win.draw_point(x1, y1,
        1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);


    win.update();
  }

  return 0;
}