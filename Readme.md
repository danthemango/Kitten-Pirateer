Kitty Piratier
==============

This is a game developed as a group project for CSCI 331 at [VIU](https://www2.viu.ca/computingscience/).

Background:
Kitten Piratier: Adventure of Zombie Island is a top down adventure game in which you play as the 
famous feline pirate, known as the Kitten Piratier!

As the Kitten Piratier was sailing around the ocean in search of adventure, his ships supplies 
started to run low. In search of new supplies the Kitten Piratier ventured to a nearby island.
Unknown to the Piratier, the Island was crawling with danger. The Piratier stepped forth and
started searching for supplies to prevent his crew from getting scurvy. Your job as the piratier
is to collect as many lemons as you can from the Island before returning to your ship to gather
a bomb that will open up the hidden Mine. Once the Mine is open you will be tasked with 
entering the Mine and collecting what lemons remain. 

As you adventure onto this Island you will need to collect items and use them to survive the 
dangers that exist. As you may have assumed, you will need to navigate the Island with Zombies 
persuing your tasty flesh. Can you defeat the Zombies and collect all of the Lemons? Or will the 
Island claim you as one of its shambling horrors?

Objective Breakdown:
Your objective is to first collect all the lemons that randomly appear around the Island.
Once all of the lemons have been collected, a bomb will appear which you must collect.
With the bomb in hand, search around for the entrance to the Mine.
With the location of the Mine in one hand and the bomb in the other, head to cracked entrance
and use the bomb to open it.
Once you are inside, search and collect all of the lemons here to win the game.
Be warned! If you let your health reach 0, you will lose the game.
Good luck, brave Kitten! You will need it!

Installation:
1. Download the game, bring up a terminal and enter the directory you wish to place the game in.
2. Next simply enter the command: git clone https://github.com/danthemango/Kitten-Pirateer
3. After entering this command and allowing the game to download, enter make into the terminal.
4. Once make is finished compiling the game, you can start the game at any time by entering bin/game
   in the command line.
5. This will bring up the game's screen. Be patient though as it may take a minute to load.

Controls:
To move the character use the following commands:
Key:            Action:
	W				   Move Up
	S				   Move Down
	A				   Move Left
	D				   Move Right
	
To use weapons and items use the following commands:
Key:			Action:
	J				   Attack with current weapon
	U				   Swap current weapon
	K				   Use current item
	I				   Swap current item
	
To pause and resume the game, use the spacebar.
To Quit the game, hit escape followed by Q and then the enter key to confirm the quit.

Items:
Within the game there are various items which can be collected.
These items include boomerangs, health potions, aoe spells, fireball spells, hearts, a bomb and of 
course Lemons!
The spells and boomerang count as weapons and can be swapped with the U key and used with the J key.
You only start with your trusty feline sword! This sword can be used with the J key.
Lemons, the bomb, and Health potions will be usable through the K key and you can swap
between them with the I key.

Known Bugs:
-There currently is a rare bug during level transitioning. On rare occasions the program will crash
when the player transitions to the next level.
-The restart ability is not currently functional and as such the restart option will not work.
-On occasion a slight animation glitch can occur with the player character. This glitch simply makes
the character appear to jump by very small amounts. This glitch appears to be within the glut functions
themselves.

###Directory Layout:

* .:    this directory contains this README and a makefile, 
*    plus the remaining directories outlined below
*    hdr:  all project .h files
*    src:  all project .cpp files
*    bin:  all project executables
*    lib:  any included externally-built .o files
*    obj:  project-built .o files
*    tst: all test files and scripts
*    docs: all project documentation other than this readme
*    ass: game assets (like sounds, and sprites)
*    proto: complete prototype used to demonstrate the game
*    test: files used to test functions

###Other Documentation
*    About the game:         docs/about.txt
*    Overall design:         docs/design.txt
*    Implementation plan:    docs/implement.txt
*    Header example:         docs/genericHeader.txt
*    Compilation:            docs/compile.txt
