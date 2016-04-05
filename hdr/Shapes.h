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

#ifndef SHAPES_H
#define SHAPES_H
#include <vector>

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

// abstract shape class
class Shape{
   public:
      virtual bool isIn(Point& P) = 0;
      virtual bool collides(Shape* S) = 0;
};

// Triangle object
// defined by three points
class Triangle: public Shape{
   public:
      Triangle(Point& A, Point& B, Point& C);
      // returns true if a point is within a triangle
      bool isIn(Point& P);
      // returns true if triangle T is entirely with this triangle
      bool isIn(Triangle& T);
      // returns true if parameter collides with this triangle
      bool collides(Triangle* T);
      bool collides(Shape* S);
   private:
      Point m_A, m_B, m_C;
};

// TODO
class Circle{
   public:
      //
   private:
      //
};

// composite shape
class CompositeShape: public Shape{
   public:
      // create the polygon
      CompositeShape();
      // adds the shape to be part of the shape
      void add(Shape* S);
      // returns true when point P is in the shape
      bool isIn(Point& P);
      // returns true when any point in S is in this shape
      bool collides(Shape* S);
   private:
      // subshape array
      std::vector <Shape*> children;
}; 

// Line object
// Defined by two points
class Line{
   public:
      // requires two points.
      // Ex: Line(Point(0,0),Point(0,1));
      Line(Point& A, Point& B);
      // returns true if point P is below the line 
      // ('below' on a cartesian plane)
      // NOTE: on a vertical line, 'left' is defined to be 'below'
      bool isBelow(Point& P);
      // slope of the line
      float slope();
      // y-intercept
      float yIntercept();
      // returns true if line is vertical
      bool isVertical();
      // returns true if the two points are on the same side of the line
      bool sameSide(Point& P1, Point& P2);
   private:
      // the two points which define the line
      Point m_A, m_B;
};

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
      // returns the bottom left corner-point of square
      Point getPoint();
      // returns height
      int getHeight();
      // returns the width
      int getWidth();
      // returns a random point in the square
      Point randPoint();
   protected:
      // bottomleft corner of square
      int m_x, m_y;
      // height and width
      int m_height, m_width;
};

#endif // SHAPES_H
