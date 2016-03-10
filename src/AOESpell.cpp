#include "../hdr/AOESpell.h"
#include "../hdr/ImageLoader.h"
#include "../hdr/Player.h"
#include "../hdr/ZombieHandler.h"

void AOESpell::use()
{
	
	if(m_amount > 0){
	
		int playerX = Player::getInstance().getX();
		int playerY = Player::getInstance().getY();
		int playerWidth = Player::getInstance().getWidth();
		int playerHeight = Player::getInstance().getHeight();
  
		ZombieHandler::getInstance().attacked(playerX - m_range, playerY - m_range,
		playerX + playerWidth + m_range, playerY + playerHeight + m_range, m_damage);                      
		
		decreaseAmount();
	}
}


AOESpell::AOESpell(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d)
{
	m_damage = d;
   m_range = r;
   m_itemID = id;
   m_name = name, 
   m_type = type;
   m_amount = 1;
   m_displayed = display;
   m_itemWidth = 30;
   m_x = x;
   m_y = y;
   m_tilePos = tile;
   m_itemTexture = ImageLoader::LoadTexture("./imgs/AOEScroll.png");
}
