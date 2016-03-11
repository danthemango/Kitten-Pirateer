// **********************************************
// Filename: Obstacle.h
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: Parent class for obstacles found in the games 2D top down maps . 
// These obstacles as of now will all be simple rectangular structure.
// though they can be combined to form other more complex shapes. 
//
// 
//    
// ************************************************



#ifndef OBSTACLE_H_
#define OBSTACLE_H_


class Player;

class Obstacle
{

private:
	//variables for the obstacle rectangles
	int m_x, m_y, m_width, m_height;
	int m_cond;
    
public:
	//functions to return values
	int getX() {return m_x;};
   	int getY() {return m_y;};
    int getW() {return m_width;};
    int getH() {return m_height;};
    int getC() {return m_cond;};
	
	Obstacle(int x, int y, int w, int h, int cond);
   	Obstacle(){};
   	~Obstacle(){};
	
};

#endif /*OBSTACLE_H_*/
