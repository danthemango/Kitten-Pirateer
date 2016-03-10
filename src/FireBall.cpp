#include "../hdr/FireBall.h"
#include "../hdr/ImageLoader.h"
#include "../hdr/Player.h"
#include "../hdr/ZombieHandler.h"
#include <iostream>

void FireBall::use()
{
	if(m_amount > 0){
		m_used = true;
		m_direction = Player::getInstance().getDirection();
		m_x = Player::getInstance().getX();
		m_y = Player::getInstance().getY();
		
		switch (m_direction) {
			case 0:
				m_itemTexture = ImageLoader::LoadTexture("./imgs/FireBallSpellUp.png");
				break;
			case 1:
				m_itemTexture = ImageLoader::LoadTexture("./imgs/FireBallSpellRight.png");	
				break;
			case 2:
				m_itemTexture = ImageLoader::LoadTexture("./imgs/FireBallSpellDown.png");	
				break;
			case 3:
				m_itemTexture = ImageLoader::LoadTexture("./imgs/FireBallSpellLeft.png");	
				break;
		}
		m_startX = m_x;
		m_startY = m_y;
		m_startTile = Player::getInstance().getTile();
		decreaseAmount();	
	}
	
}


FireBall::FireBall(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d)
{
	m_used = false;
	m_damage = d;
	m_range = r;
	m_itemID = id;
	m_name = name;
	m_type = type;
	m_amount = 3;
	m_displayed = display;
	m_itemWidth = 30;
	m_x = x;
	m_y = y;
	m_element = 0;
	m_tilePos = tile;
	m_itemTexture = ImageLoader::LoadTexture("./imgs/FireBallScroll.png");	
}
