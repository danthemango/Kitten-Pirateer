#include "../hdr/Boomerang.h"
#include "../hdr/ImageLoader.h"
#include "../hdr/Player.h"
#include "../hdr/ItemHandler.h"
#include <stdlib.h>

void Boomerang::displayProjectileMove()
{
	if(m_used && Player::getInstance().getTile() == m_startTile){

		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
		glBindTexture (GL_TEXTURE_2D, m_itemTexture);
		ImageLoader::rectangle(m_x, m_y, m_itemWidth, m_itemWidth);
		glDisable(GL_TEXTURE_2D);
		glFlush();
		
		int size = ItemHandler::getInstance().getNumOfItems();

		for(int i=0;i<size;i++){
			ItemHandler::getInstance().m_itemList[i]->pickUp(m_x, m_y);		
		}


		if(!m_atRange){
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
			if(abs(m_startX - m_x) > m_range || abs(m_startY - m_y) > m_range){
				m_atRange = true;
			}
		}else if(m_atRange){
			if(Player::getInstance().getX() < m_x){
				m_x -= 5;
			} 
			if(Player::getInstance().getX() > m_x){
				m_x += 5;
			}
			if(Player::getInstance().getY() < m_y){
				m_y -= 5;
			}
			if(Player::getInstance().getY() > m_y){
				m_y += 5;
			}
			pickUp(m_x, m_y);
			if(m_x+5 > Player::getInstance().getX() && m_x-5 < Player::getInstance().getX() + Player::getInstance().getWidth() && 
				m_y+5 > Player::getInstance().getY() && m_y-5 < Player::getInstance().getY() + Player::getInstance().getHeight()){
				m_used = false;
				m_atRange = false;
			}
		}
	}else{
		m_used = false;
		m_atRange = false;
	}
}

void Boomerang::use()
{
	ItemHandler::getInstance().getItemList();
	if(!m_used){
		m_used = true;
		m_atRange = false;
		m_direction = Player::getInstance().getDirection();
		m_x = Player::getInstance().getX();
		m_y = Player::getInstance().getY();
		m_startTile = Player::getInstance().getTile();
		m_startX = m_x;
		m_startY = m_y;
		
		switch (m_direction) {
			case 0:
				//m_itemTexture = ImageLoader::LoadTexture("./imgs/FireBallSpellUp.png");
				m_y += m_itemWidth;
				break;
			case 1:
				m_x += m_itemWidth;
				//m_itemTexture = ImageLoader::LoadTexture("./imgs/FireBallSpellRight.png");	
				break;
			case 2:
				m_y -= m_itemWidth;
				//m_itemTexture = ImageLoader::LoadTexture("./imgs/FireBallSpellDown.png");	
				break;
			case 3:
				m_x -= m_itemWidth;
				//m_itemTexture = ImageLoader::LoadTexture("./imgs/FireBallSpellLeft.png");	
				break;
		}
		decreaseAmount();	
	}
}

Boomerang::Boomerang(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d)
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
	m_tilePos = tile;
	m_itemTexture = ImageLoader::LoadTexture("./imgs/Boomerang.png");	
	
	
}
