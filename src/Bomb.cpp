#include "../hdr/Bomb.h"
#include "../hdr/ImageLoader.h"
#include "../hdr/Player.h"


void Bomb::use()
{
	int playerX = Player::getInstance().getX();
	int playerY = Player::getInstance().getY();
	int width = Player::getInstance().getWidth();
	int height = Player::getInstance().getHeight();
	
	
	if(playerX+width > 366 && playerX  < 472
      && playerY > (1054-624) && playerY+height < 1054-531 && Player::getInstance().getTile() == 2){
      m_amount = 0;
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
