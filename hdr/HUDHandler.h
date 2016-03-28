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
#include "../hdr/ImageLoader.h"

class HUDHandler {

private: 

int m_width, m_height;
GLuint m_backgroundHUD;

HUDHandler() {
            // Define the game width and height from initial generation.
			m_width = SCREEN_SIZE_X;
			m_height = SCREEN_SIZE_Y;
			m_backgroundHUD = ImageLoader::LoadTexture("./imgs/backgroundHUD.png");
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
/* DrJ -- Singleton
   Ensure the clas only has one instance and that instance is accessible via
   a global access point. \
*/
/*
   DrJ -- Static type Binding
   Singleton is a statically bound type as it is resolved at compile time.
*/

static HUDHandler& getInstance()
         {
                static HUDHandler    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
                return instance;
         };

		HUDHandler(HUDHandler const&);           // Don't Implement
        void operator=(HUDHandler const&); // Don't implement

    // Display all the HUD elements by iterating through the array of HUD items
    /*
    DrJ -- Composite Pattern
    Within HUDHandler displayHUD the array containting instances of HUD objects and is
    iterated through with a request to call the subclass' own displayHUD function.
    */
    void displayHUD() {

	   ImageLoader::rectangle(m_width,0,HUD_WIDTH, m_height);
      glEnable(GL_TEXTURE_2D);
	   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	   glBindTexture (GL_TEXTURE_2D, m_backgroundHUD);
	   ImageLoader::rectangle(m_width,0,HUD_WIDTH, m_height);
	   glDisable(GL_TEXTURE_2D);
	   glFlush();
      
      /* DrJ -- Polymorphism
         Definition: Polymorphism means having many forms. 
         The function displayHUD() is ploymorphic as it implements all versions
         of the function asimplemented differently in the approprite class object.
      */
      /*DrJ -- Dynamic Binding -- references of HUD pure virtual function for each 
        subclass are resolved at run-time.
      */
      for(int i=0; i<2; i++) {hud[i]->displayHUD();}
    };

};

#endif

/*
DrJ -- Clean Room

What are two ways to create an instance of an object? (hint: stack vs heap)
   The heap keeps track of the dynamically allocated memory, usually allocated via 
   the use of the 'new' operator.
   (Source: www.learncpp.com/cpp-tutorial/79-the-stack-and-the-heap/)

   The stack keeps track of all the active functions (and those that have not yet
   been terminated) from the start of the program to the current point of execution. It
   handles all function parameters and local variables.
   (Source: www.learncpp.com/cpp-tutorial/79-the-stack=and-the-heap/)

What is the lifetime of each?
   The lifetime of a dynamically created instance (heap) exists until it is 
   destroyed with the 'delete' operator. 
   The lifetime of a statically created instance (stack) exists until it is popped
   off of the stack at time of use.

What is the lifetime of an instance that is declared static?
   The lifetime of an instance that is declared static (stack) exists from the start
   of the program until its time of use, when it is destroyed along with its variables
   and a return value is passed back onto the stack in place of it. 

How do you free up the memory when you are done?
   Memory is freed up once the singleton is destroyed as all instanced of 
   allocated memory are created within the constructor that the singleton
   implements. On exit, a singleton is guarenteed to be destroyed. 
*/
