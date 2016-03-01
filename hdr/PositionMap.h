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
#include "Shapes.h"

// class which contains the position of elements on a single tile
class PositionMap{
   public:
      PositionMap();
      ~PositionMap();
      // inserts an element to the map at position x,y
      void add(int x, int y);
      // returns the number of elements in map
      int size();
   private:
      // node in a linked list which contains the data of the element
      struct node{
         Point* data;
         node* next;
      };
      node* m_head;
      node* m_tail;
      // number of elements in this map
      int m_num;
   public: 
      // this is an iterator which is able to traverse the list of positions
      // PATTERN: iterator
      class Iterator
      {
         public:
            Iterator(node* start):
               m_cur_node(start){}
            // prefix increment
            const Iterator &operator++()
            {
               m_cur_node = m_cur_node->next;
               return *this;
            }
            // postfix increment
            Iterator operator++(int)
            {
               Iterator temp = *this;
               m_cur_node = m_cur_node->next;
               return temp;
            }
            // dereferencer
            Point* operator*()
            {
               if(m_cur_node){
                  return m_cur_node->data;
               }else{
                  return NULL;
               }
            }
            Iterator &operator=(Iterator& other){
               m_cur_node = other.m_cur_node;
               return *this;
            }
         private:
            node* m_cur_node;
      };
      // iterator to the start of the list
      Iterator Begin(){
         return Iterator(m_head);
      }
      Iterator End(){
         return Iterator(m_tail);
      }
};
#endif
