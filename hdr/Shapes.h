// **********************************************
// Filename:   Shapes.h
// Author:     Daniel Guenther
// Date:       2016-02-28
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    implements classes which allow the definition of shapes
//    Note: should be useful to determine collisions
// ************************************************

#include <cmath>
using namespace std;

#ifndef SHAPES_H
#define SHAPES_H

// coordinate plane point
class Point{
   public:
      Point(int x, int y): m_x(x), m_y(y) {}
      // change the coordinates of the point
      int getX();
      int getY();
      // get the distance between two points
      float distance(Point& other);
   private:
      int m_x,m_y;
};

// Line object
// Defined by two points
class Line{
   public:
      // requires two points.
      // Ex: Line(Point(0,0),Point(0,1));
      Line(Point A, Point B);
      // returns true if point P is below the line 
      // ('below' on a cartesian plane)
      // NOTE: on a vertical line, 'left' is defined to be 'below'
      bool isBelow(Point P);
   private:
      // two lines on the line
      Point m_A, m_B;
};

// Triangle object
//TODO

// Square object
// Note: is actually a rectangle
class Square{
   public:
      // creates a Square with the points specified
      // (x1,y1) - bottom left corner
      // (x2,y2) - top right corner
      Square(int x1, int y1, int x2, int y2);
      // returns true if point is inside of Square
      bool isIn(int x, int y);
      // returns true if the other Square collided with this Square
      bool collides(Square& other);
   private:
      // m_x1, m_y1 - coordinates of the bottom left corner
      // m_x2, m_y2 - coordinates of the top right corner
      int m_x1, m_y1, m_x2, m_y2;
};
#endif // SHAPES_H
