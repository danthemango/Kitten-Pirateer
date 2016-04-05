#include "../hdr/Bomb.h"
#include "../hdr/ImageLoader.h"
#include "../hdr/Player.h"
#include "../hdr/Jukebox.h"
#include "../hdr/MapHandler.h"
#include <iostream>
#include "../hdr/Game.h"


void Bomb::use()
{
	int playerX = Player::getInstance().getX();
	int playerY = Player::getInstance().getY();
	int width = Player::getInstance().getWidth();
	int height = Player::getInstance().getHeight();
	
	
	if(playerX+width > 366 && playerX  < 472
      && playerY > (1054-624) && playerY+height < 1054-531 && Player::getInstance().getTile() == 2){
      m_amount = 0;
      Jukebox::PlaySound("./sounds/Bomb.wav");
     
      MapHandler::getInstance().updateLevel(1);
      ItemHandler::getInstance().removeItems();
      ItemHandler::getInstance().setLevel(1);
      ItemHandler::getInstance().buildItemArray("./config/INPUT_ITEMS_LEVEL1");
      MapHandler::getInstance().updateTile(2);
      ItemHandler::getInstance().setLevel(1);
      
	}
	
}


Bomb::Bomb(int id, int x, int y, std::string name, bool display, int r, int tile)
{
	m_range = r;
   m_itemID = id;
   m_name = name;
   m_amount = 1;
   m_displayed = display;
   m_x = x;
   m_y = y;
   m_tilePos = tile;
   m_itemWidth = 20;
   m_itemTexture = ImageLoader::LoadTexture("./imgs/bomb.png");
	
}
