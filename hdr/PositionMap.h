// **********************************************
// Filename:   PositionMap.h
// Author:     Daniel Guenther
// Date:       2016-02-27
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    Container which holds positions of objects with respect to the tiles
// ************************************************

#ifndef POSITIONMAP_H
#define POSITIONMAP_H

#include "config.h"

// structure which can contain the position of an object
struct Position{
   int x,y;
};

// class which contains the position of elements on a single tile
class PositionMap{
   public:
      PositionMap();
      ~PositionMap();
      // inserts an element to the map at position x,y
      void addElement(int x, y);
   private:
      // node in a linked list which contains the data of the element
      struct node{
         Position* data;
         node* next;
      };
      node* m_head;
      // number of elements in this map
      int m_num;
   public: 
      // returns the number of elements in map
      int size();
      // this is an iterator which is able to traverse the list of positions
      // PATTERN: iterator
      class PositionMapIterator()
      {
         public:
            PositionMapIterator(node* start):
               m_cur_node(start);
            //~PositionMapIterator();
            // prefix increment
            const PositionMapIterator &operator++()
            {
               m_cur_node = m_cur_node->next;
               return *this;
            }
            // postfix increment
            PositionMapIterator operator++(int)
            {
               PositionMapIterator temp = *this;
               m_cur_node = m_cur_node->next;
               return temp;
            }
            // dereferencer
            Position* operator*()
            {
               if(m_cur_node){
                  return m_cur_node->data;
               }else{
                  return NULL;
               }
            }
         private:
            node* m_cur_node;
      };
      // iterator to the start of the list
      Iterator Begin(){
         Iterator(m_head);
      }
};
#endif
