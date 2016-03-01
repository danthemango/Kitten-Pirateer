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

// change the coordinates of the point
void Point::set(int x, int y){
   m_x = x;
   m_y = y;
}

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

// creates a Square with the points specified
// (x1,y1) - bottom left corner
// (x2,y2) - top right corner
Square::Square(int x1, int y1, int x2, int y2)
{  
   m_x1 = x1;
   m_y1 = y1;
   m_x2 = x2;
   m_y2 = y2;
}

// returns true if point is inside of Square
bool Square::isIn(int x, int y){
   return x >= m_x1 && x <= m_x2 && y >= m_y1 && y <= m_y2;
}

// returns true if the other Square collided with this Square
bool Square::collides(Square& other)
{
   return !(other.m_x1 > m_x2 || other.m_x2 < m_x1 
         || other.m_y1 > m_y2 || other.m_y2 < m_y1);
}

Line::Line(Point A, Point B): m_A = A, m_B = B
{
}

// returns true if point P is below the line 
// ('below' on a cartesian plane)
// NOTE: on a vertical line, 'left' is defined to be 'below'
bool Line::isBelow(Point P)
{
   // check for a horizontal line
   // NOTE: important because we don't want to divide by 0 later
   if(m_A.getY() == m_B.getY()){
      return m_A.getY() < P.getY();
   }

   // ensure point A is 'left' of B
   if(m_A.getX() > m_B.getX()){
      Point temp = m_A;
      m_A = m_B;
      m_B = m_A;
   }

   // get the slope of the line
   float slope = (m_B.getX() - m_A.getX()) / (m_B.getY() - m_A.getY());
}
