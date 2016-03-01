// Author:   Anand Sundar
// Class:    CSCI 331
// Project:  Kitty Pirateer
//
// Purpose:
//     Player functionality implementation
//


// constructor to initialize the variables

#include "../hdr/Player.h"
#include "../hdr/Jukebox.h"
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>
#include <iostream>

#include "../hdr/ImageLoader.h" 
#include "../hdr/Game.h"

Player::Player()
{
  m_health =20; //full health when the singleton is created
  m_x = PLAYER_START_X; //start X-pos of player
  m_y = PLAYER_START_Y; //start Y-pos of player
  stopup=stopdown=stopleft=stopright=false;
  m_arraypos = 0;
  m_speed = PLAYER_SPEED;
  c_up=c_down=c_left=c_right=false;
  m_stepSize = 4;
  m_currTile = 3;
  m_lastStep = glutGet(GLUT_ELAPSED_TIME);
  m_downTexture[0]= ImageLoader::LoadTexture("./imgs/CatDownA.png");
  m_downTexture[1]= ImageLoader::LoadTexture("./imgs/CatDownB.png");
  m_downTexture[2]= ImageLoader::LoadTexture("./imgs/CatDownC.png");
  m_downTexture[3]= ImageLoader::LoadTexture("./imgs/CatDownB.png");
  m_upTexture[0]= ImageLoader::LoadTexture("./imgs/CatUpA.png");
  m_upTexture[1]= ImageLoader::LoadTexture("./imgs/CatUpB.png");
  m_upTexture[2]= ImageLoader::LoadTexture("./imgs/CatUpC.png");
  m_upTexture[3]= ImageLoader::LoadTexture("./imgs/CatUpB.png");
  m_leftTexture[0]= ImageLoader::LoadTexture("./imgs/CatLeftA.png");
  m_leftTexture[1]= ImageLoader::LoadTexture("./imgs/CatLeftB.png");
  m_leftTexture[2]= ImageLoader::LoadTexture("./imgs/CatLeftC.png");
  m_leftTexture[3]= ImageLoader::LoadTexture("./imgs/CatLeftB.png");
  m_rightTexture[0]= ImageLoader::LoadTexture("./imgs/CatRightA.png");
  m_rightTexture[1]= ImageLoader::LoadTexture("./imgs/CatRightB.png");
  m_rightTexture[2]= ImageLoader::LoadTexture("./imgs/CatRightC.png");
  m_rightTexture[3]= ImageLoader::LoadTexture("./imgs/CatRightB.png");
  m_attackUp[0] = ImageLoader::LoadTexture("./imgs/CatAttackUpA.png");
  m_attackUp[1] = ImageLoader::LoadTexture("./imgs/CatAttackUpB.png");
  m_attackUp[2] = ImageLoader::LoadTexture("./imgs/CatAttackUpC.png");
  m_attackUp[3] = ImageLoader::LoadTexture("./imgs/CatAttackUpD.png");
  m_attackDown[0] = ImageLoader::LoadTexture("./imgs/CatAttackDownA.png");
  m_attackDown[1] = ImageLoader::LoadTexture("./imgs/CatAttackDownB.png");
  m_attackDown[2] = ImageLoader::LoadTexture("./imgs/CatAttackDownC.png");
  m_attackDown[3] = ImageLoader::LoadTexture("./imgs/CatAttackDownD.png");
  m_attackRight[0] = ImageLoader::LoadTexture("./imgs/CatAttackRightA.png");
  m_attackRight[1] = ImageLoader::LoadTexture("./imgs/CatAttackRightB.png");
  m_attackRight[2] = ImageLoader::LoadTexture("./imgs/CatAttackRightC.png");
  m_attackRight[3] = ImageLoader::LoadTexture("./imgs/CatAttackRightD.png");
  m_attackLeft[0] = ImageLoader::LoadTexture("./imgs/CatAttackLeftA.png");
  m_attackLeft[1] = ImageLoader::LoadTexture("./imgs/CatAttackLeftB.png");
  m_attackLeft[2] = ImageLoader::LoadTexture("./imgs/CatAttackLeftC.png");
  m_attackLeft[3] = ImageLoader::LoadTexture("./imgs/CatAttackLeftD.png");
  m_lastFrame = 0;
  m_stepNum = 1;
  m_attacking = 0;	
}

//player singleton

int Player::getHealth()
{
   return m_health;        
}
//returns the player height 
int Player:: getHeight() 
{
   return SPRITE_SIZE_Y;
}
//returns the player width
int Player::getWidth()
{
   return SPRITE_SIZE_X;
}

//returns the player direction used by robert
int Player::getDirection()
{
   return m_direction;
}

int Player::getX()
{
    return m_x;
}

int Player::getY()
{
   return m_y;
}

int Player::getTile()
{
   return m_currTile;
}
void Player::init()
{
   m_PlayerTexture = ImageLoader::LoadTexture("./imgs/CatUpB.png");   
}

void Player::display()
{
   displayTexture();
}

void Player::addHealth(int addHealth)
{
   if(m_health < 100 ) 
   {
      m_health+= addHealth;
      if(m_health == 100)
      {
         m_health = 100;
      } 
   }
}
void Player::displayTexture()
{
	if(m_attacking == 0){
		//draw the player
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
		glBindTexture (GL_TEXTURE_2D, m_PlayerTexture);
		ImageLoader::rectangle(m_x,m_y, SPRITE_SIZE_X, SPRITE_SIZE_Y);
		glDisable(GL_TEXTURE_2D);
		glFlush();
		m_frame = 0;
	}else{
		displayAttack();	
	}
}

void Player::collision(int xpos, int ypos, int width, int height, int cond)
{
   //send the player position to the itemhandler and store the returned bool value and do
   //the check
/*
   //bool check = ItemHandler::getInstance().
   if(m_x+SPRITE_SIZE_X > xpos && m_x < xpos + width && m_y+SPRITE_SIZE_Y > ypos && m_y < ypos+height){
	   if(cond == 0){   
	      if(c_up){
      	   m_y -=m_stepSize;
         }
         if(c_right){
      	   m_x -=m_stepSize;
         }
         if(c_down){
      	   m_y +=m_stepSize;
         }
         if(c_left){
      	   m_x +=m_stepSize;
         }
      }else if(cond == 1){
         m_speed = 0.5;
      }
	}else{
	   m_speed = 1;
	}
	*/
   if(m_x+m_stepSize+SPRITE_SIZE_X > xpos && m_x < xpos + width
      && m_y+SPRITE_SIZE_Y > ypos && m_y < ypos+height){
      stopright = true;
      m_x -=m_stepSize;
   }else if(m_x+SPRITE_SIZE_X > xpos && m_x-m_stepSize < xpos + width
      && m_y+SPRITE_SIZE_Y > ypos && m_y < ypos+height){
      stopleft = true;
      m_x+=m_stepSize;
   }else if(m_y-m_stepSize < ypos+height  && m_y > ypos
      && m_x +SPRITE_SIZE_X > xpos && m_x < xpos+width){
      stopdown = true;
      m_y+=m_stepSize;
   }else if(m_y+SPRITE_SIZE_Y+m_stepSize> ypos && m_y < ypos+height
      && m_x+SPRITE_SIZE_X > xpos && m_x < xpos+width){
      stopup = true;
      m_y-=m_stepSize;
   }else{
      stopright = false;
      stopleft = false;
      stopup = false;
      stopdown = false;
   }

}

void Player::update()
{
   //ZombieHandler::getInstance().update(m_x,m_y);

   //code from collision detection lab
   int size = MapHandler::getInstance().getNumObstacles();
   Obstacle* ob;
   ob = MapHandler::getInstance().getObstacles();
  
   for(int i=0;i<size;i++){
      int xpos = ob[i].getX();
      int ypos = ob[i].getY();
      int width = ob[i].getW();
      int height = ob[i].getH();
      int cond = ob[i].getC();

      collision(xpos, ypos, width, height, cond);
      if(stopright == true || stopleft == true||stopup==true||stopdown==true)
      	break;   
   }

}

void Player::attacked(int damage)
{
    m_health -= damage;   

}

void Player::displayAttack()
{
	int attackX, attackY, attackW, attackH;

	switch(m_direction)
	{
		case 0: 
			attackX = m_x; 
			attackY = m_y;
			attackW = 45;
			attackH = 60;
			break;
 		case 1: 
			attackX = m_x; 
			attackY = m_y;
			attackW = 60;
			attackH = 60;
			break;
		case 2:
			attackX = m_x - 15;
			attackY = m_y - 30;
			attackW = 45;
			attackH = 60;
			break;
		case 3:
			attackX = m_x - 30; 
			attackY = m_y;
			attackW = 60;
			attackH = 60;
			break;	
	}
	
	int now;
	int seconds;
	now = glutGet(GLUT_ELAPSED_TIME);
  
	seconds =  now - m_lastFrame;
	if (seconds > 50){
		m_lastFrame = glutGet(GLUT_ELAPSED_TIME);
		if(m_frame == 4){
			m_attacking = 0;
			return;
		}
		switch(m_direction)
		{
			case 0: 
				displayAttackUp(m_frame);
				m_frame++;
				break;
			case 1: 
				displayAttackRight(m_frame);
				m_frame++;
				break;
			case 2: 
				displayAttackDown(m_frame);
				m_frame++;
				break;
			case 3: 
				displayAttackLeft(m_frame);
				m_frame++;
				break;
		}
	}
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_AttackTexture);
	ImageLoader::rectangle(attackX,attackY,attackW, attackH);
	glDisable(GL_TEXTURE_2D);
	glFlush();
}

void Player::attack()
{
	if(m_attacking == 0){
		m_attacking = 1;
	
		

	
   //what to do here??
   //0 = melee attacks
   //1 = gun
   //2 = spell
   
   int weaponId = ItemHandler::getInstance().getWeapon()->getType(); // stores the weapon id
   int weaponDamage = ItemHandler::getInstance().getWeapon()->getDamage(); // gets the damage for the weapon
   int weaponRange = ItemHandler::getInstance().getWeapon()->getRange();  
   int midpointx = SPRITE_SIZE_X / 2 + m_x;
   int midpointy = SPRITE_SIZE_Y / 2 + m_y;
   
   float x1,x2,y1,y2 = 0.0;
   switch (m_direction)
   {
      case 0://u
        x1 = m_x;
        x2 = m_x + SPRITE_SIZE_X;
        y1 = m_y + SPRITE_SIZE_Y;
        y2 = m_y + SPRITE_SIZE_Y + weaponRange;
        ZombieHandler::getInstance().attacked(x1,y1,x2,y2,weaponDamage);
        break;
      case 2://d
        x1 = m_x;
        y1 = m_y - weaponRange;
        x2 = m_x + SPRITE_SIZE_X;
        y2 = m_y;
        ZombieHandler::getInstance().attacked(x1,y1,x2,y2,weaponDamage);
        break;
      case 3://l
        x1 = m_x - weaponRange; 
        y1 = m_y;
        x2 = m_x; 
        y2 = m_y + SPRITE_SIZE_Y;
        ZombieHandler::getInstance().attacked(x1,y1,x2,y2,weaponDamage);
        break;
      case 1://r
        x1 = m_x + SPRITE_SIZE_X; 
        y1 = m_y;
        x2 = m_x + SPRITE_SIZE_X + weaponRange;
        y2 = m_y + SPRITE_SIZE_Y;
        ZombieHandler::getInstance().attacked(x1,y1,x2,y2,weaponDamage);
        break;

   }
}
}

void Player::down ()
{ 
    if(!stopdown){

       if(m_y-5 <= 0)
       {
         if(m_currTile != 6 && m_currTile!= 7 && m_currTile!=8){
              m_currTile +=3;
              MapHandler::getInstance().updateTile(m_currTile);
              m_y = 1054-SPRITE_SIZE_Y;
         }
       }else{
           m_y -= 4 * m_speed;
        }
     }
     //m_x = m_x - m_speed; //updates the position of the player
     m_direction = 2;
        int now;
  int seconds;
  now = glutGet(GLUT_ELAPSED_TIME);
  
  seconds =  now - m_lastStep;
  if (seconds > 200){
   Jukebox::PlaySound("./sounds/Step.wav");
     m_lastStep = glutGet(GLUT_ELAPSED_TIME);
  
      switch (m_stepNum){
		case 0: m_stepNum = 1;
			break;
 		case 1: m_stepNum = 2;
			break;
		case 2: m_stepNum = 3;
			break;
		case 3: m_stepNum = 0;
			break;
		}
	}     
     
     m_PlayerTexture = m_downTexture[m_stepNum];
}

void Player::up ()
{
  
           if(!stopup)
           {

              if(m_y+SPRITE_SIZE_Y >= 1054)
              {
                 if(m_currTile != 0 && m_currTile != 1 && m_currTile != 2)
                 {
                    m_currTile-=3;
                    MapHandler::getInstance().updateTile(m_currTile);
                    m_y = 5;
                 }
              }else{
                 m_y +=4*m_speed;
              }
           }
    //m_x = m_x + m_speed;
    m_direction = 0;
       int now;
  int seconds;
  now = glutGet(GLUT_ELAPSED_TIME);
  
  seconds =  now - m_lastStep;
  if (seconds > 200){
   Jukebox::PlaySound("./sounds/Step.wav");
     m_lastStep = glutGet(GLUT_ELAPSED_TIME);
  
      switch (m_stepNum){
		case 0: m_stepNum = 1;
			break;
 		case 1: m_stepNum = 2;
			break;
		case 2: m_stepNum = 3;
			break;
		case 3: m_stepNum = 0;
			break;
	}
}
    m_PlayerTexture= m_upTexture[m_stepNum];
}

void Player::right ()
{  
           if(!stopright)
           {
 
              if(m_x+ SPRITE_SIZE_X>= 1054)
              {
                 if(m_currTile != 2 && m_currTile != 5 && m_currTile != 8)
                 {
                    m_currTile +=1;
                    MapHandler::getInstance().updateTile(m_currTile);
                    m_x = 5;
                 }
              }else{
                 m_x += 4*m_speed;
              }
          }
    //m_y = m_y + m_speed;
    m_direction = 1;
       int now;
  int seconds;
  now = glutGet(GLUT_ELAPSED_TIME);
  
  seconds =  now - m_lastStep;
  if (seconds > 200){
   Jukebox::PlaySound("./sounds/Step.wav");
     m_lastStep = glutGet(GLUT_ELAPSED_TIME);
  
      switch (m_stepNum){
		case 0: m_stepNum = 1;
			break;
 		case 1: m_stepNum = 2;
			break;
		case 2: m_stepNum = 3;
			break;
		case 3: m_stepNum = 0;
			break;
		}
	}
    m_PlayerTexture= m_rightTexture[m_stepNum];
}

void Player::left ()
{  
       if(!stopleft)
       {
          
          if(m_x-5 <= 0)
          {
             if(m_currTile != 0 && m_currTile != 3 && m_currTile != 6)
             {
                m_currTile -= 1;
                MapHandler::getInstance().updateTile(m_currTile);
                m_x = 1054-SPRITE_SIZE_X ;
             }
          }else{
             m_x -= 4*m_speed;
          }
       }
    //m_y = m_y - m_speed;
    m_direction = 3;
       int now;
  int seconds;
  now = glutGet(GLUT_ELAPSED_TIME);
  
  seconds =  now - m_lastStep;
  if (seconds > 200){
   Jukebox::PlaySound("./sounds/Step.wav");
     m_lastStep = glutGet(GLUT_ELAPSED_TIME);
  
      switch (m_stepNum){
		case 0: m_stepNum = 1;
			break;
 		case 1: m_stepNum = 2;
			break;
		case 2: m_stepNum = 3;
			break;
		case 3: m_stepNum = 0;
			break;
		}
	}
    
    m_PlayerTexture= m_leftTexture[m_stepNum];
}
void Player::displayAttackUp(int frame)
{
	m_AttackTexture = m_attackUp[frame];
}
void Player::displayAttackRight(int frame)
{
	m_AttackTexture = m_attackRight[frame];
}
void Player::displayAttackDown(int frame)
{
	m_AttackTexture = m_attackDown[frame];
}
void Player::displayAttackLeft(int frame)
{
	m_AttackTexture = m_attackLeft[frame];
}

