#ifndef BULLET_H_
#define BULLET_H_

//#include "Jukebox.h"
#include <GL/freeglut.h>

class Car {  
   private:
    int m_x;  
    int m_y; 
    float m_direction;
    float m_speed;

    int m_xangle;
    int m_yangle; 

    GLuint m_carTexture;   

   public:
    void left ();
    void right ();
    void up ();
    void down ();
    void stop ();
    void honk ();
    void display ();
    void displayWireFrame ();
    void displaySolidCube ();
    void displayTexture ();
    void update ();
    void init();
    Car(int x = 260, int y = 170);
};

#endif /* BULLET_H_ */
