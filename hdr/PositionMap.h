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
#include <cstddef>

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
      class Iterator
      {
         public:
            // initialize (ex. use Iterator i(map.Begin())):w
            Iterator(node* start);
            // go to the next element in map
            const Iterator &operator++();
            Iterator operator++(int);
            // get position from element
            Point* operator*();
            // check if two iterators aren't equal
            bool operator!=(Iterator const &other);
            // assignment
            Iterator &operator=(Iterator& other);
         private:
            node* m_cur_node;
      };
      // iterator to the start of the list
      Iterator Begin(){
         return Iterator(m_head);
      }
      // iterator to the end of the list
      Iterator End(){
         return Iterator(m_tail);
      }
};
#endif
