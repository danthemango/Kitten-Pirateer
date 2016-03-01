/*
File: HUDHandler.h
Author: Benjamin Smith
Purpose: 
        Singleton used to generate the HUD via an array
*/

#pragma once 
#ifndef HUDHANDLER_H
#define HUDHANDLER_H

#include "../hdr/Game.h"
#include "../hdr/HUD.h"
#include "../hdr/ItemHUD.h"
#include "../hdr/HealthHUD.h"

class HUDHandler {

private: 

int m_width, m_height;

// Singleton for HUD
HUDHandler() {
            // Define the game width and height from initial generation.
			m_width = SCREEN_SIZE_X;
			m_height = SCREEN_SIZE_Y;
			// Create an overlay view over the main game as not to disrupt the primary functions of the game
			// Can be later implepented to be turned off through settings
			if (glutLayerGet(GLUT_OVERLAY_POSSIBLE)) {
				void glutEstablishOverlay();
			}
            // Array of HUD items used to display HUD on the game screen
            hud[0] = new ItemHUD(m_width, m_height);
            hud[1] = new HealthHUD(m_width, m_height);
		};

        HUD *hud[2];


public :
static HUDHandler& getInstance()
         {
                static HUDHandler    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
                return instance;
         };

		HUDHandler(HUDHandler const&);           // Don't Implement
        void operator=(HUDHandler const&); // Don't implement

    // Display all the HUD elements by iterating through the array of HUD items
    void displayHUD() {
        for(int i=0; i<2; i++) {hud[i]->displayHUD();}
    };

};

#endif
