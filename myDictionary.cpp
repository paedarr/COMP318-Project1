#include "myDictionary.h"
using namespace std;

void mazeHelper::addVisited(Position * x){
    visited[x->to_string()] = x;
}

void mazeHelper::addVisitFrom(Position * cur, Position * prev){
    visited_from[cur->to_string()] = prev;
}

// Create a mazeHelper object to use these methods:
// mazeHelper myObj.addVisited(position);