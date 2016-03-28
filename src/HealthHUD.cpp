/*
File: HealthHUD.cpp
Author: Benjamin Smith
Purpose:
	Display the health stats of the players health to the HUD
*/

#include "../hdr/HealthHUD.h"
#include "../hdr/Player.h"

// Display the health of the player to the screen. 	
void HealthHUD::displayHUD() {
   
   // DrJ - Class/Object
   // Here there is use of local object variables defined by your formatting
   // requirements to be listed as m_ 

    m_health = Player::getInstance().getHealth();
	m_healthString = std::to_string(m_health);
    m_printHealth = m_healthString.c_str();

    // The health of the player will be available to the controller.

	RenderString(m_width + 70, m_height - 144, GLUT_BITMAP_TIMES_ROMAN_24, "Health:");
	RenderString(m_width + 90, m_height - 175, GLUT_BITMAP_TIMES_ROMAN_24 , m_printHealth);


   // Keep track of the players current posisiton
	m_posX = Player::getInstance().getX();
	m_posY = Player::getInstance().getY();

   // Create a rectange above the player that will display a health increase/decrease
   // when the player is hurt or healed
/*	ImageLoader::rectangle(m_posX,m_posY+30,30,10);
       glEnable(GL_TEXTURE_2D);
	   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	   glBindTexture (GL_TEXTURE_2D, m_healthLabel);
	   ImageLoader::rectangle(0,0,30,10);
	   glDisable(GL_TEXTURE_2D);
	   glFlush();
*/
}

