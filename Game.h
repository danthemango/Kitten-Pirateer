//Editor: Keenan Longair
//Last Update:Jan23, 2016 @2:30pm.
//Purpose: Main Game.h file with class definitions. Essentially sets up the game instance
//which allows the game to start through a singleton. If you want an instance simply use the
//getInstance() function.
#ifndef GAME_H_
#define GAME_H_

class GameObject;

#define MAX_OBJECTS 50

class Game {
	
//Required portions for making this a Singleton.
    public:
        //Insead of a constructor, use this static method to create an instance
        // or used the already created instance) of Game
        static Game& getInstance()
        {
            static Game    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }
    private:
        
		//Make all the constructors private. If you want an instance, use the 
        //getInstance() method above.
        Game() {
           m_margine = 4;
           m_width = 500;
           m_height = 300;
           m_scorePanelWidth = 80;
        };
        Game(Game const&);
        void operator=(Game const&);

	//Now that we are  a Singleton, define the rest fo the class as usual.
	private:
      const static int c_interval = 1000 / 60; // 60 frames per second

      //Window size:
      int m_width;
      int m_height;
      int m_margine;
      int m_scorePanelWidth;//Temporary until we decide on a better setup.

      //Items in the game:
      int m_gameObjects;
      GameObject *m_myGameObjects[MAX_OBJECTS];
      int m_score;
	  
   public:
      //Functions for GL. 
      static void key(unsigned char key, int x, int y);//Key handles control 
	  //through the Game.cpp file currently but could call on the players move functions.
      static void run();//Run is the computing loop and calls update.
      static void idle();
      static void timer(int id);
      void update();//

      void RenderString(float x, float y, void *font, const char* string);//Function which 
	  //renders the score string for now. 
	  
      void updateScore(int addMe) {m_score += addMe;}; //Function which handles the score
	  //update.

	  //Next line would be updated for the player(?) if we set this up.
      //GameObject *paddle() {return m_myGameObjects[0];};

      void init();

      GLfloat frand();
};

#endif /* GAME_H_ */
