// **********************************************
// Filename:   PositionMap.cpp
// Author:     Daniel Guenther
// Date:       2016-02-27
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    Container which holds positions of objects with respect to the tiles
// ************************************************

#include "../hdr/PositionMap.h"

PositionMap::PositionMap()
{
   // ensure we are aware that no elements have been created in the list
   node* temp = new node;
   m_head = m_tail;
   m_num = 0; // no elements yet
}

PositionMap::~PositionMap()
{
   // delete all elements in the list
   while(m_head != NULL){
      node* temp = m_head;
      delete m_head->data;
      delete m_head;
      temp = temp->next;
   }
}

// inserts an element to the map at position x,y
void PositionMap::add(int x, int y)
{
   m_num++;
   // create a new head if needed
   if(m_head == m_tail){
      m_head = new node;
      m_head->data = new Point(x,y);
      m_head->next = m_tail;
      m_tail = m_head->next;
      return;
   }

   // traverse list to find next empty spot
   node* temp = m_head;
   while(temp->next != m_tail){
      temp = temp->next;
   }
   // insert the data in this position
   temp->next = new node;
   temp->next->data = new Point(x,y);
   temp->next->next = m_tail;
   m_tail = temp->next->next;
}

// returns the number of elements in map
int PositionMap::size()
{
   return m_num;
}

// initialize
PositionMap::Iterator::Iterator(node* start):
   m_cur_node(start)
{}

// prefix increment
const PositionMap::Iterator& PositionMap::Iterator::operator++()
{
   m_cur_node = m_cur_node->next;
   return *this;
}

// postfix increment
PositionMap::Iterator PositionMap::Iterator::operator++(int)
{
   Iterator temp = *this;
   m_cur_node = m_cur_node->next;
   return temp;
}

// dereferencer
Point* PositionMap::Iterator::operator*()
{
   if(m_cur_node){
      return m_cur_node->data;
   }else{
      return NULL;
   }
}

bool PositionMap::Iterator::operator!=(Iterator const &other){
   return other.m_cur_node != m_cur_node;
}

PositionMap::Iterator& PositionMap::Iterator::operator=(Iterator& other){
   m_cur_node = other.m_cur_node;
   return *this;
}
