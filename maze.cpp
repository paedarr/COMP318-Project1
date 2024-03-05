/* Comp 318 Spring 2023, programming assignment 2
 * Copyright (c) 2023
 * Wheaton College, Computer Science Department, Norton MA
 * M. Gagne
 */

#include <stdexcept>

/* STL libraries needed */
#include <stack>
#include <queue>
#include <vector>

/* library for reverse function */
#include <algorithm>
/* there is a function called "reverse" in this library that can reverse the elements of a vector
 * call it as follows:
 * reverse(v.begin(), v.end()); // this reverses the order of the elements in vector v
 */

#include "maze.h"
#include "myDictionary.h"

using namespace std;

// Can Assume that Both start and end (Top Left & Bottom Right) are empty spaces. 

Maze::Maze(int w, int h) {
  // needs to initialize vector of position objects
  width = w;
  height = h;
  positions = new Position**[height];
  for (int i = 0; i < height; i++){
    positions[i] = new Position*[width];
    for (int j = 0; j < width; ++j){
      positions[i][j] = new Position(j, i);
    }
  }
}

Maze::~Maze() {
  for (int i = 0; i < getHeight(); ++i) {
        for (int j = 0; j < getWidth(); ++j) {
            delete positions[i][j]; 
        }
        delete[] positions[i];
    }
    delete[] positions;
}

int Maze::getWidth() {
  return width; 
}

int Maze::getHeight() {
  return height;
}

bool Maze::isWall(int x, int y) {
  if (positions[x][y] == '#')
    return true;
  else 
    return false;
}

void Maze::setWall(int x, int y) {
  positions[x][y] = "#";
}

vector<Position*> Maze::solveBreadthFirst() {
  /* you will need an unordered_map to store the previous of each position */
  /* the keys for this map are the to_string of a position object
   * the associated value should be a pointer to the Position from which
   * you saw the key
   */
   
    vector<int> path;
    mazeHelper maze_helper;
    queue maze_queue; // <-- for BFS stack storage
    unordered_map<string, Position*> previous;
    maze_queue.push_back(start)
    
    while(!maze_queue.empty()){
      Position* current = maze_queue.front();//could change to a to visit queue
      maze_queue.dequeue();

      if (current == end ){
        maze_helper.addVisitFrom(position);
        vector<Position*> path;

        while (current != nullptr) {
                path.push_back(current);
                current = previous[current->to_string()];
            }
            reverse(path.begin(), path.end());
            return path;
      }
       vector<Position*> neighbors = getNeighbors(current);

        for (int i = 0; i < neighbors.size(); ++i) {
          Position * neighbor = neighbors[i];

            if (previous.find(neighbor->to_string()) == previous.end()) {
                toVisit.push(neighbor);
                previous[neighbor->to_string()] = current;
            }
        }
    }

    return vector<Position*>();
  
    
  
}

vector<Position*> Maze::solveDepthFirst() {
  stack<Position*> toVisit;
    unordered_map<string, Position*> previous;

    toVisit.push(start);
    previous[start->to_string()] = nullptr;

    while (!toVisit.empty()) {
        Position* current = toVisit.top();
        toVisit.pop();

        if (current == end) {
            vector<Position*> path;
            while (current != nullptr) {
                path.push_back(current);
                current = previous[current->to_string()];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        vector<Position*> neighbors = getNeighbors(current);
        for (int i = 0; i < neighbors.size(); ++i) {
          Position * neighbor = neighbors[i];
            if (previous.find(neighbor->to_string()) == previous.end()) {
                toVisit.push(neighbor);
                previous[neighbor->to_string()] = current;
            }
        }
    }

    return vector<Position*>();
}

vector<Position*> Maze::getNeighbors(Position* position) {
  /*look up, left, right, down for neighbors */
  vector<Position*> neighbors;
  int x = position->getX();
  int y = position->getY();

  if (isValid(x - 1, y)) {
    neighbors.push_back(positions[y][x - 1]); //left neighbor
  }
  if (isValid(x + 1, y)) {
    neighbors.push_back(positions[y][x + 1]); //right neighbor
  }
  if (isValid(x, y - 1)) {
    neighbors.push_back(positions[y - 1][x]); //up neighbor
  }
  if (isValid(x, y + 1)) {
    neighbors.push_back(positions[y + 1][x]); //down neighbor
  }

  return neighbors;
}

bool Maze :: isValid(int x, int y) {
    return (x >= 0 && x < getWidth() && y >= 0 && y < getHeight() && !isWall(x, y));
}