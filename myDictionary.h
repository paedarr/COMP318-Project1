/* 
 * Comp 318 Spring 2024, Programming Assignment 1
 * Wheaton College MA
 * Authors: Gavin Graham & Paedar Rader
 */

// implement this and .cpp file
// USE ' unordered_map ' in this file

#ifndef MYDICTIONARY_H
#define MYDICTIONARY_H

#include <cstdlib>
#include <string>
#include <unordered_map>
#include "position.h"
using namespace std;

class mazeHelper{
    protected:
        unordered_map<string, Position *> visited;
        unordered_map<string, Position *> visited_from;
    public:
        void addVisited(Position * x);
        void addVisitFrom(Position * cur, Position * prev);
};

#endif