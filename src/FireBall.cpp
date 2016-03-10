#include "../hdr/FireBall.h"
#include "../hdr/ImageLoader.h"
#include "../hdr/Player.h"
#include "../hdr/ZombieHandler.h"

void FireBall::use()
{
	
	
}


FireBall::FireBall(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d)
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
   m_itemTexture = ImageLoader::LoadTexture("./imgs/AOESpell.png");
	
}
