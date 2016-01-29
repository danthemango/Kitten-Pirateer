#include "Car.h"
#include "Jukebox.h"
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>

#include "ImageLoader.h" 
#include "Game.h"

class ImageLoader;

void Car::left ()
{
   m_direction = 4;
   if(m_x-50 <= 0)
   {
	   Game::getInstance().changeScreen(m_direction);
	   m_x = 950;
   }else{
	   m_x -= 50;
   }
   m_carTexture= ImageLoader::LoadTexture( "./imgs/Left.bmp" );
}
void Car::right ()
{
   m_direction = 2;
   if(m_x+110 >= 1023)
   {
	   Game::getInstance().changeScreen(m_direction);
	   m_x = 10;
   }else{
	m_x += 50;
   }
   m_carTexture= ImageLoader::LoadTexture( "./imgs/Right.bmp" );
}
void Car::up ()
{
  m_direction = 1;
  if(m_y+110 >= 731)
  {
	  Game::getInstance().changeScreen(m_direction);
	  m_y = 10;
  }else{
	m_y += 50;
  }
  m_carTexture= ImageLoader::LoadTexture( "./imgs/Up.bmp" );
}
void Car::down ()
{
  m_direction = 3;
  if(m_y-50 <= 0)
  {
	  Game::getInstance().changeScreen(m_direction);
	   m_y = 670;
   }else{
	m_y -= 50;
  }
  m_carTexture= ImageLoader::LoadTexture( "./imgs/Down.bmp" );
}
void Car::attack ()
{
  Game::getInstance().changeScreen(1);
}
void Car::honk ()
{
  Jukebox::PlaySound("./sounds/AHH.WAV");
}

void Car::display ()
{
   displayTexture ();
}

void Car::displayTexture ()
{
   // Draw the car
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   glBindTexture (GL_TEXTURE_2D, m_carTexture);
   ImageLoader::rectangle(m_x,m_y, 50, 50);
   glDisable(GL_TEXTURE_2D);
   glFlush();

}
void Car::update ()
{
  
}

void Car::init()
{
  m_carTexture= ImageLoader::LoadTexture( "./imgs/Up.bmp" );
}


Car::Car(int x, int y)
{
   m_x=x;
   m_y=y;
   m_direction = 0; // 1.5 up 3 left 4.5 down
   m_speed = 0;
}

