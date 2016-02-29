// **********************************************
// Filename:   Shapes.h
// Author:     Daniel Guenther
// Date:       2016-02-28
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    implements classes which allow the definition of shapes
// ************************************************

#include <cmath>

// coordinate plane point
class Point{
   public:
      Point(int x, int y){
         set(x,y);
      }
      // change the coordinates of the point
      set(int x, int y){
         m_x = x;
         m_y = y;
      }
      getX(){return m_x;}
      getY(){return m_y;}
      // get the distance between two points
      float distance(Point& other){
         // calculate delta x and y
         int dx = abs(m_x - other.m_x);
         int dy = abs(m_y - other.m_y);
         return sqrt(pow(dx,2) + pow(dy,2));
      }
   private:
      int m_x,m_y;
};

// Square object
class Square{
   public:
      // creates a Square with the points specified
      // (x1,y1) - bottom left corner
      // (x2,y2) - top right corner
      Square(int x1, int y1, int x2, int y2)
      {  
         m_x1 = x1;
         m_y1 = y1;
         m_x2 = x2;
         m_y2 = y2;
      }
      // returns true if point is inside of Square
      bool isIn(int x, int y){
         return x >= m_x1 && x <= m_x2 && y >= m_y1 && y <= m_y2;
      }
      // returns true if the other Square collided with this Square
      bool collides(Square& other)
      {
         return !(other.m_x1 > m_x2 || other.m_x2 < m_x1 
            || other.m_y1 > m_y2 || other.m_y2 < m_y1);
      }
   private:
      // m_x1, m_y1 - coordinates of the bottom left corner
      // m_x2, m_y2 - coordinates of the top right corner
      int m_x1, m_y1, m_x2, m_y2;
};
