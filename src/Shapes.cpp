// **********************************************
// Filename:   Shapes.cpp
// Author:     Daniel Guenther
// Date:       2016-02-28
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    implements classes which allow the definition of shapes
// ************************************************

#include "../hdr/Shapes.h"
#include <random>
#include <cmath>
using namespace std;

// **************** POINT ****************
int Point::getX()
{
   return m_x;
}

int Point::getY()
{
   return m_y;
}

// get the distance between two points
float Point::distance(Point& other){
   // calculate delta x and y
   int dx = abs(m_x - other.m_x);
   int dy = abs(m_y - other.m_y);
   return sqrt(pow(dx,2) + pow(dy,2));
}

// **************** SQUARE ****************
// creates a Square with the points specified
// (x1,y1) - bottom left corner
// (x2,y2) - top right corner
Square::Square(int x1, int y1, int x2, int y2)
{  
   m_x = x1;
   m_y = y1;
   m_width = x2 - x1;
   m_height = y2 - y1;
}

// returns true if point is inside of Square
bool Square::isIn(int x, int y){
   // true if point is both within the width or height
   bool inwidth = x >= m_x && x <= m_x + m_width;
   bool inheight = y >= m_y && y <= m_y + m_height;
   return inwidth && inheight;
}

// returns true if the other Square collided with this Square
bool Square::collides(Square& other)
{
   // true if any corner in the other square is inside us
   return isIn(other.m_x,other.m_y) || isIn(other.m_x + m_width, other.m_y) 
      || isIn(other.m_x, other.m_y + m_height) || isIn(other.m_x + m_width, other.m_y + m_height);
}

// returns the bottom left corner-point of square
Point Square::getPoint()
{
   return Point(m_x,m_y);
}

// returns height
int Square::getHeight()
{
   return m_height;
}

// returns the width
int Square::getWidth()
{
   return m_width;
}

Point Square::randPoint()
{
   random_device rd;
   int x = (m_x + rd()) % (m_x+m_width);
   int y = (m_y + rd()) % (m_y+m_height);
   return Point(x,y);
}

// **************** LINE ****************
Line::Line(Point& A, Point& B): m_A(A), m_B(B)
{
   // ensure m_A is 'left' of m_B on the cartesian plane
   if(m_A.getX() > m_B.getX()){
      Point temp = m_A;
      m_A = m_B;
      m_B = m_A;
   }
}

// returns true if line is vertical
bool Line::isVertical()
{
   return m_A.getX() == m_B.getX();
}

// slope of the line
float Line::slope()
{
   // return junk value if impossible
   if(isVertical()){
      return 0;
   }

   return float((m_B.getX() - m_A.getX())) / (m_B.getY() - m_A.getY());
}

// y-intercept
float Line::yIntercept()
{
   // return junk value if impossible
   if(isVertical()){
      return 0;
   }

   return m_A.getY() - slope() * m_A.getX();
}

// returns true if point P is below the line 
// ('below' on a cartesian plane)
// NOTE: on a vertical line, 'left' is defined to be 'below'
bool Line::isBelow(Point& P)
{
   // on a vertical line, check if point is 'left' of the line
   if(isVertical()){
      return P.getX() < m_A.getX();
   }

   // get the y position of a point on the line which is at the same x position of the point
   int y = P.getX() * slope() + yIntercept();

   return P.getY() < y;
}

bool Line::sameSide(Point& P1, Point& P2)
{
   // either they're both below the line or neither is below
   return (isBelow(P1) && isBelow(P2)) || !(isBelow(P1) || isBelow(P2));
}

// ******************************** TRIANGLE ********************************
Triangle::Triangle(Point& A, Point& B, Point& C): m_A(A), m_B(B), m_C(C)
{
}

bool Triangle::isIn(Point& P)
{
   // create the three lines of the triangle
   Line AB(m_A,m_B);
   Line BC(m_B,m_C);
   Line AC(m_A,m_C);

   // if P is within the triangle, then it is going to be on
   // the same side of each line as the other point in the triangle
   // ex: P and m_C are going to be on the same side of line AB
   return AB.sameSide(P,m_C) && BC.sameSide(P,m_A) && AC.sameSide(P,m_B);
}

// returns true if triangle T collides with this triangle
bool Triangle::collides(Triangle* T)
{
   // true if any point in T is in this triangle
   return isIn(T->m_A) || isIn(T->m_B) || isIn(T->m_C);
}

bool Triangle::collides(Shape* S)
{
   return S->collides(this);
}

// returns true if triangle T is entirely with this triangle
bool Triangle::isIn(Triangle& T)
{
   // true if all points of T are within this triangle
   return isIn(T.m_A) && isIn(T.m_B) && isIn(T.m_C);
}

// ******************************** POLYGON *********************************
CompositeShape::CompositeShape()
{
   //
}

void CompositeShape::add(Shape* S)
{
   children.push_back(S);
}

// returns true when point P is in the shape
bool CompositeShape::isIn(Point& P)
{
   for(int i = 0; i < children.size(); i++){
      if(children[i]->isIn(P)){
         return true;
      }
   }
   return false;
}

// returns true when any point in S is in this shape
bool CompositeShape::collides(Shape* S)
{
   for(int i = 0; i < children.size(); i++){
      if(children[i]->collides(S)){
         return true;
      }
   }
   return false;
}
