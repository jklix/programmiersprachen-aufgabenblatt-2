#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
};


TEST_CASE("Vec2 constructor", "[Vec2]") //Konstruktor Test
{

  SECTION("standard_constructor")
  {
    Vec2 vecA;

    REQUIRE(vecA.x_ == 0);
    REQUIRE(vecA.y_ == 0);
  }

  SECTION("modifiable_constructor")
  {
    Vec2 vecB{0, 0};
    Vec2 vecC{-30, 30};
    Vec2 vecD{3.3f, 8.8f};

    REQUIRE(vecB.x_ == 0);
    REQUIRE(vecB.y_ == 0);
    REQUIRE(vecC.x_ == -30);
    REQUIRE(vecC.y_ == 30);
    REQUIRE(vecD.x_ == 3.3f);
    REQUIRE(vecD.y_ == 8.8f);
  }
};

TEST_CASE("Vec2_operator_plus", "[+]") // Test Addition Aufgabe 2.3
{
  Vec2 vecA{0, 0};
  Vec2 vecB{-3, 3};
  Vec2 vecC{3.3f, 8.8f};

  vecA += vecA;
  REQUIRE(vecA.x_ == 0);
  REQUIRE(vecA.y_ == 0);

  vecC += vecA;
  REQUIRE(vecC.x_ == Approx(3.3f));
  REQUIRE(vecC.y_ == Approx(8.8f));

  vecB += vecA;
  REQUIRE(vecB.x_ == -3);
  REQUIRE(vecB.y_ == 3); 
};


TEST_CASE("Vec2_operator2", "[-]")  // Test Subtraktion Aufgabe 2.3
{
  Vec2 vecA{0, 0};
  Vec2 vecB{-3, 3};
  Vec2 vecC{3.3f, 8.8f};
  Vec2 vecD{-2, -4};

  vecA -= vecA;
  REQUIRE(vecA.x_ == 0);
  REQUIRE(vecA.y_ == 0);

  vecC -= vecA;
  REQUIRE(vecC.x_ == Approx(3.3f));
  REQUIRE(vecC.y_ == Approx(8.8f));

  vecB -= vecA;
  REQUIRE(vecB.x_ == -3);
  REQUIRE(vecB.y_ == 3); 

  vecD -= vecB;
  REQUIRE(vecD.x_ == 1);
  REQUIRE(vecD.y_ == -7);
};


TEST_CASE("Vec2_operator3", "[*]")  // Test Multiplikation Aufgabe 2.3
{
  Vec2 vecA{0, 0};
  Vec2 vecB{1, 2};
  Vec2 vecC{-2, -3};
  Vec2 vecD{2.2, 2.5};

  vecA *= 1.0;
  REQUIRE(vecA.x_ == Approx(0.0f));
  REQUIRE(vecA.y_ == Approx(0.0f));

  vecB *= 2.0;
  REQUIRE(vecB.x_ == Approx(2.0f));
  REQUIRE(vecB.y_ == Approx(4.0f));

  vecC *= 3.0;
  REQUIRE(vecC.x_ == Approx(-6.0f));
  REQUIRE(vecC.y_ == Approx(-9.0f)); 

  vecD *= 4.0;
  REQUIRE(vecD.x_ == Approx(8.8f));
  REQUIRE(vecD.y_ == Approx(10.0f));
};

TEST_CASE("Vec2_operator4", "[/]")  // Test Division Aufgabe 2.3
{
  Vec2 vecA{0, 0};
  Vec2 vecB{8, 4};
  Vec2 vecC{-4, -4};
  Vec2 vecD{2.2, 2.4};


  REQUIRE(vecA.x_ == Approx(0.0f));
  REQUIRE(vecA.y_ == Approx(0.0f));

  vecB /= 2.0;
  REQUIRE(vecB.x_ == Approx(4.0f));
  REQUIRE(vecB.y_ == Approx(2.0f));

  vecC /= 2.0;
  REQUIRE(vecC.x_ == Approx(-2.0f));
  REQUIRE(vecC.y_ == Approx(-2.0f)); 

  vecD /= 2.0;
  REQUIRE(vecD.x_ == Approx(1.1f));
  REQUIRE(vecD.y_ == Approx(1.2f));
};

// Aufgabe 2.4
TEST_CASE("Vec2_Add", "[+]")
{
  Vec2 vecA{0, 0};
  Vec2 vecB{-3, 3};
  Vec2 vecC = vecA + vecB;
  Vec2 vecD{3.3f, 8.8f};
  Vec2 vecE = vecB + vecD;
  Vec2 vecF{4, 4};
  Vec2 vecG = vecC + vecF;

  REQUIRE(vecC.x_ == -3);
  REQUIRE(vecC.y_ == 3);

  REQUIRE(vecE.x_ == Approx(0.3f));
  REQUIRE(vecE.y_ == Approx(11.8f));

  REQUIRE(vecG.x_ == 1);
  REQUIRE(vecG.y_ == 7);
};

TEST_CASE("Vec2_Sub", "[-]")
{
  Vec2 vecA{0, 0};
  Vec2 vecB{-3, 3};
  Vec2 vecC = vecA - vecB;
  Vec2 vecD{3.3f, 8.8f};
  Vec2 vecE = vecB - vecD;
  Vec2 vecF{4, 4};
  Vec2 vecG = vecC - vecF;

  REQUIRE(vecC.x_ == 3);
  REQUIRE(vecC.y_ == -3);

  REQUIRE(vecE.x_ == Approx(-6.3f));
  REQUIRE(vecE.y_ == Approx(-5.8f));

  REQUIRE(vecG.x_ == -1);
  REQUIRE(vecG.y_ == -7);
};

TEST_CASE("Vec2_Mul", "[*]")
{
  Vec2 vecA{0, 0};
  Vec2 vecB = vecA * 1.0;
  Vec2 vecC{3, 3};
  Vec2 vecD = vecC * 2.0;
  Vec2 vecE{-2, -5};
  Vec2 vecF = vecE * 3.0;
  Vec2 vecG{2.3, 3.3};
  Vec2 vecH = vecG * 2.2;

  REQUIRE(vecB.x_ == Approx(0.0f));
  REQUIRE(vecB.y_ == Approx(0.0f));

  REQUIRE(vecD.x_ == Approx(6.0f));
  REQUIRE(vecD.y_ == Approx(6.0f));

  REQUIRE(vecF.x_ == Approx(-6.0f));
  REQUIRE(vecF.y_ == Approx(-15.0f));

  REQUIRE(vecH.x_ == Approx(5.06f));
  REQUIRE(vecH.y_ == Approx(7.26f));
};

TEST_CASE("Vec2_Div", "[/]")
{
  Vec2 vecA{0, 0};
  Vec2 vecB = vecA / 1.0;
  Vec2 vecC{4, 4};
  Vec2 vecD = vecC / 2.0;
  Vec2 vecE{-3, -5};
  Vec2 vecF = vecE / 2.0;
  Vec2 vecG{2.4, 4.8};
  Vec2 vecH = vecG / 2.2;

  REQUIRE(vecB.x_ == Approx(0.0f));
  REQUIRE(vecB.y_ == Approx(0.0f));

  REQUIRE(vecD.x_ == Approx(2.0f));
  REQUIRE(vecD.y_ == Approx(2.0f));

  REQUIRE(vecF.x_ == Approx(-1.5f));
  REQUIRE(vecF.y_ == Approx(-2.5f));

  REQUIRE(vecH.x_ == Approx(1.09091f));
  REQUIRE(vecH.y_ == Approx(2.18182f));
};

TEST_CASE("Mat2_Mul", "[*]")
{
  Mat2 mA{};
  Mat2 mB{1, 2, 3, 4};
  Mat2 mC{-1, 2, -3, 4};
  Mat2 mD{1.5, 0.5, 2.0, 2.5};

  mA *= mB;
  REQUIRE(mA.a_ == 1);
  REQUIRE(mA.b_ == 2);
  REQUIRE(mA.c_ == 3);
  REQUIRE(mA.d_ == 4);

  mB *= mC;
  REQUIRE(mB.a_ == -7);
  REQUIRE(mB.b_ == 10);
  REQUIRE(mB.c_ == -15);
  REQUIRE(mB.d_ == 22);

  mD *= mC;
  REQUIRE(mD.a_ == Approx(-3.0f));
  REQUIRE(mD.b_ == Approx(5.0f));
  REQUIRE(mD.c_ == Approx(-9.5f));
  REQUIRE(mD.d_ == Approx(14.0f));
};

TEST_CASE("Mat2_Mal","[*]")
{
  Mat2 mA{};
  Mat2 mB{1, 2, 3, 4};
  Mat2 mC{-1, 2, -3, 4};
  Mat2 mD{1.5, 0.5, 2.0, 2.5};
  Mat2 mE = mA * mB;
  Mat2 mF = mC * mD;
  Mat2 mG = mB * mC;

  REQUIRE(mE.a_ == 1);
  REQUIRE(mE.b_ == 2);
  REQUIRE(mE.c_ == 3);
  REQUIRE(mE.d_ == 4);

  REQUIRE(mF.a_ == Approx(2.5f));
  REQUIRE(mF.b_ == Approx(4.5f));
  REQUIRE(mF.c_ == Approx(3.5f));
  REQUIRE(mF.d_ == Approx(8.5f));

  REQUIRE(mG.a_ == -7);
  REQUIRE(mG.b_ == 10);
  REQUIRE(mG.c_ == -15);
  REQUIRE(mG.d_ == 22);
};

TEST_CASE("Mat2_Vec2","[*]")
{
  Mat2 mA {};
  Mat2 mB {1,2,3,4};
  Mat2 mC {-1, -2, -3, -4};

  Vec2 vA {-1,-2};
  Vec2 vB {2.0, 3.0};

  Vec2 vC, vD, vE, vF;

  vC = vA * mA;
  REQUIRE(vC.x_ == -1);
  REQUIRE(vC.y_ == -2);

  vD = vB * mB;
  REQUIRE(vD.x_ == Approx(8.0f));
  REQUIRE(vD.y_ == Approx(18.0f));

  vE = mC * vA;
  REQUIRE(vE.x_ == 5);
  REQUIRE(vE.y_ == 11);

  vF = mB * vB;
  REQUIRE(vF.x_ == Approx(8.0f));
  REQUIRE(vF.y_ == Approx(18.0f));
};

TEST_CASE("Mat2_det","[det]")
{
  Mat2 mA {};
  Mat2 mB {1,2,3,4};
  Mat2 mC {-1, -2, -3, -4};
  Mat2 mD {1.2, 2.3, 2.4, 4.5};

  REQUIRE(mA.det() == 1);
  REQUIRE(mB.det() == -2);
  REQUIRE(mC.det() == -2);
  REQUIRE(mD.det() == Approx(-0.12f));
};

TEST_CASE("Mat2_inv","[inv]")
{
  Mat2 mA {};
  Mat2 mB {1,2,3,4};
  Mat2 mC {0.0, 1.5, 0.0, 1.6};

  Mat2 mD = inverse(mA);
  REQUIRE(mD.a_ == 1);
  REQUIRE(mD.b_ == 0);
  REQUIRE(mD.c_ == 0);
  REQUIRE(mD.d_ == 1);

  Mat2 mE = inverse(mB);
  REQUIRE(mE.a_ == Approx(-2.0f));
  REQUIRE(mE.b_ == Approx(1.0f));
  REQUIRE(mE.c_ == Approx(1.5f));
  REQUIRE(mE.d_ == Approx(-0.5f));

  Mat2 mF = inverse(mC);
  REQUIRE(mF.a_ == Approx(0.0f));
  REQUIRE(mF.b_ == Approx(1.5f));
  REQUIRE(mF.c_ == Approx(0.0f));
  REQUIRE(mF.d_ == Approx(1.6f));
};

TEST_CASE("Mat2_tra","[tra]")
{
  Mat2 mA {};
  Mat2 mB {1,2,3,4};
  Mat2 mC {0.0, 1.5, 0.0, 1.6};

  Mat2 mD = transpose(mA);
  REQUIRE(mD.a_ == 1);
  REQUIRE(mD.b_ == 0);
  REQUIRE(mD.c_ == 0);
  REQUIRE(mD.d_ == 1);

  Mat2 mE = transpose(mB);
  REQUIRE(mE.a_ == 1);
  REQUIRE(mE.b_ == 3);
  REQUIRE(mE.c_ == 2);
  REQUIRE(mE.d_ == 4);

  Mat2 mF = transpose(mC);
  REQUIRE(mF.a_ == Approx(0.0f));
  REQUIRE(mF.b_ == Approx(0.0f));
  REQUIRE(mF.c_ == Approx(1.5f));
  REQUIRE(mF.d_ == Approx(1.6f));
};

TEST_CASE("Mat2_rot","[rot]")
{
  Mat2 mA = make_rotation_mat2(0.7853981633974483); //pi/4
  Mat2 mB = make_rotation_mat2(-2);
  Mat2 mC = make_rotation_mat2(1.3);

  REQUIRE(mA.a_ == Approx(0.999906049802f));
  REQUIRE(mA.b_ == Approx(0.013707354605f));
  REQUIRE(mA.c_ == Approx(-0.013707354605f));
  REQUIRE(mA.d_ == Approx(0.999906049802f));

  REQUIRE(mB.a_ == Approx(0.999390827019f));
  REQUIRE(mB.b_ == Approx(0.034899496703f));
  REQUIRE(mB.c_ == Approx(-0.034899496703f));
  REQUIRE(mB.d_ == Approx(0.999390827019f));

  REQUIRE(mC.a_ == Approx(0.999742609323f));
  REQUIRE(mC.b_ == Approx(-0.022687333573f));
  REQUIRE(mC.c_ == Approx(0.022687333573f));
  REQUIRE(mC.d_ == Approx(0.999742609323f));
};

TEST_CASE("Circle1","[Circle]")
{
  float r;
  Vec2 v(100, 150);
  Circle k(30, v);
  Circle kr(r, v);


  REQUIRE(k.get_radius() == 30);
  REQUIRE(k.get_area() == Approx(2827.4333882308139146f));
  REQUIRE(k.get_diameter() == 60);
  REQUIRE(k.get_circumference() == Approx(188.49556f));
  kr.set_radius(70.09);
  REQUIRE(kr.get_radius() == Approx(70.09f));
};

TEST_CASE("Rectangle","[Rect]")
{
  Vec2 v_(40, 30);
  Rectangle r(v_, 20, 30);

  REQUIRE(r.get_width() == 20);
  REQUIRE(r.get_height() == 30);
  REQUIRE(r.get_perimeter() == 100);
  REQUIRE(r.get_area() == 600);
  r.set_width(33.3);
  r.set_height(44.4);
  REQUIRE(r.get_width() == Approx(33.3f));
  REQUIRE(r.get_height() == Approx(44.4));
};  



TEST_CASE("Circle2","[is_Inside]")
{
  Vec2 v_(40, 30);
  Vec2 w_(50, 50);
  Vec2 a_(300, 300);
  Vec2 b_(-30, -30);
  Vec2 c_(40.0, 30.0);
  Circle k{{40}, {v_}, {0, 0, 0}};

  REQUIRE(k.is_Inside(w_) == true);
  REQUIRE(k.is_Inside(a_) == false);
  REQUIRE(k.is_Inside(b_) == false);
  REQUIRE(k.is_Inside(c_) == true);
};

TEST_CASE("Circle3","[is_Inside]")
{
  Vec2 v_(40, 30);
  Vec2 w_(50, 50);
  Vec2 a_(300, 300);
  Vec2 b_(-30, -30);
  Vec2 c_(40.0, 30.0);
  Rectangle rec{{v_}, {40}, {40}};

  REQUIRE(rec.is_Inside(w_) == true);
  REQUIRE(rec.is_Inside(a_) == false);
  REQUIRE(rec.is_Inside(b_) == false);
  REQUIRE(rec.is_Inside(c_) == true);
};









  