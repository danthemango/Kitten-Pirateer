// **********************************************
// Filename:   GameObject.h
// Author:     created by Julie Beeston
//                some modifications by Daniel Guenther
// Date:       2016-02-01
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    basic object type of an element in the game
// ************************************************

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <stdlib.h>
#include <math.h>

class GameObject {
   public:
      virtual void display () = 0;
      virtual void update () = 0;
      // TODO rewrite this, there is no ball in this game
      //virtual bool collide (Ball *b) { return false; }

   private:
      void arc(GLfloat x, GLfloat y, GLfloat r, int n, int s, int e) {
         int i;
         GLfloat r2 = r/2.0;
         glBegin(GL_POLYGON);
         {
            for (i = s; i < e; i++) {
               double a = 2*i*M_PI/n;
               glVertex2f(x+r2+r2*cos(a),y+r2+r2*sin(a));
            }
         }
         glEnd();
      }

      void circle(GLfloat x, GLfloat y, GLfloat r, int n) {
         arc(x, y, r, n, 0, n);
      }

      void rectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
         glBegin(GL_POLYGON);
         {
            glVertex2f(x,y);
            glVertex2f(x+width,y);
            glVertex2f(x+width,y+ height);
            glVertex2f(x,y+ height);
         }
         glEnd();
      }

      void line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat thickness=5.0) {
         glLineWidth(thickness);
         glBegin(GL_LINES);
         {
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
         }
         glEnd();
         glLineWidth(1.f);//reset
      }
};

#endif /* GAME_OBJEC_H_ */
