#include "../hdr/Projectile.h"
#include "../hdr/Player.h"
#include "../hdr/ImageLoader.h"
#include "../hdr/ZombieHandler.h"
#include "../hdr/config.h"
#include <iostream>
#include <stdlib.h>

void Projectile::display()
{
	if(Player::getInstance().getTile() == m_tilePos){
		
		if(m_displayed == true){
			//draw image
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
			glBindTexture (GL_TEXTURE_2D, m_itemTexture);
			ImageLoader::rectangle(m_x, m_y, m_itemWidth, m_itemWidth);
			glDisable(GL_TEXTURE_2D);
			glFlush();
		}
	}
	displayProjectileMove();
}

void Projectile::displayProjectileMove()
{
	if(m_used && Player::getInstance().getTile() == m_startTile){
		if(m_x + m_itemWidth < SCREEN_SIZE_X && m_x > 0 && m_y + m_itemWidth < SCREEN_SIZE_Y && m_y > 0){ 
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
			glBindTexture (GL_TEXTURE_2D, m_itemTexture);
			ImageLoader::rectangle(m_x, m_y, m_itemWidth, m_itemWidth);
			glDisable(GL_TEXTURE_2D);
			glFlush();
		
			attack();
		}
		switch (m_direction){
			case 0:
				m_y+=5;
				break;
			case 1:
				m_x+=5;
				break;
			case 2:
				m_y-=5;
				break;
			case 3:
				m_x-=5;
				break;
		}
		if(abs(m_startX - m_x) >= m_range || abs(m_startY - m_y) >= m_range){
			m_used = false;
		}
	}else{
		m_used = false;
	}
}

void Projectile::attack()
{
	ZombieHandler::getInstance().attacked(m_x, m_y, m_x + m_itemWidth, m_y + m_itemWidth, m_damage);
}

Projectile::Projectile(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d)
{
	m_range = r;
	m_displayed = display;
	m_itemWidth = 30;
	m_x = x;
	m_y = y;
	m_tilePos = tile;
	m_itemTexture = ImageLoader::LoadTexture("./imgs/AOESpell.png");
}
