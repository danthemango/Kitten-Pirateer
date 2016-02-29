// Author: Daniel Guenther
// Date: 2016-02-28
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//    A 'Zombie' is a NPC which slowly follows the player
//    and deals damage when close enough
// ************************************************

Zombie::Zombie()
{
   m_visible = false;
   m_direction = UP;
}

// update takes in the player's position
// this function will act as the NPC's 'AI' 
virtual void Zombie::update(int x, int y)
{
   if(!m_visible || m_dead){
      return;
   }
   // TODO
}

// display is used to draw this object
virtual void Zombie::display()
{
   // TODO
}

// kill the zombie immediately
void Zombie::kill()
{
   m_dead = true;
}

// make the zombie disappear
void Zombie::disappear()
{
   m_visible = false;
}

void Zombie::spawn(int x, int y)
{
   // revive or vive the zombie
   m_dead = false;
   m_visible = true;
   m_health = 100;
   m_x = x;
   m_y = y;
}

void Zombie::attacked(int x1, int y1, int x2, int y2, int damage)
{
   if(m_dead || !m_visible){
      return;
   }
   // see if the sprite box touches the 'damage' box
   Square damageBox(x1, y1, x2, y2);
   Square spriteBox(m_x, m_y, m_x + SPRITE_SIZE_X, m_y + SRITE_SIZE_Y);
   // take damage if zombie is in attack range
   if(damageBox.collides(spriteBox)){
      m_health -= damage;
      // kill zombie if hurt enough
      if(m_health <= 0){
         m_dead = true;
      }
   }
}

virtual void Zombie::update(Point &playerpos)
{
   update(playerpos.getX(),playerpos.getY());
}

void Zombie::spawn(Point &pos)
{
   spawn(pos.getX(),pos.getY());
}
