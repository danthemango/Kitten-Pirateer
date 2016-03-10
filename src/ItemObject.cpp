#include "../hdr/ItemObject.h"
#include "../hdr/Player.h"
#include "../hdr/ImageLoader.h"
#include <GL/glut.h>
#include <GL/freeglut.h>


void ItemObject::display()
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
}
