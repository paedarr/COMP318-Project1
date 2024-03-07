/* 
 * Comp 318 Spring 2024, Programming Assignment 1
 * Wheaton College MA
 * Authors: Gavin Graham & Paedar Rader
 */

#include <stdexcept>
#include <iostream>

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
#include "position.h"

using namespace std;


Maze::Maze(int w, int h) {
  
  width = w;
  height = h;
  path_length = 0;
  
  positions = new Position**[height];
  for (int i = 0; i < height; i++){
    positions[i] = new Position*[width];
    for (int j = 0; j < width; ++j){
      positions[i][j] = new Position(j, i);
    }
  }

  start = positions[0][0];
  end = positions[height - 1][width - 1];
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
  bool result = positions[y][x]->isWall();
  return result;
}

void Maze::setWall(int x, int y) {
  positions[y][x]->setWall();
}

vector<Position*> Maze::solveBreadthFirst() {
  /* you will need an unordered_map to store the previous of each position */
  /* the keys for this map are the to_string of a position object
   * the associated value should be a pointer to the Position from which
   * you saw the key
   */
  
    queue <Position*>maze_queue; // <-- for BFS queue storage
    
    maze_queue.push(start);
    start -> predecessor = nullptr;
    start -> visited = true;
    path_length = 0;
    num_of_nodes_visited = 0;
    
    while(!maze_queue.empty()){
      num_of_nodes_visited++;
      Position* current = maze_queue.front();
      maze_queue.pop();
      
      if (current == end ){
        vector<Position*> path;
        
        while (current != nullptr) {
                path.push_back(current);
                current = current->predecessor;
                path_length++;
            }
            reverse(path.begin(), path.end());
            return path;
      }
       vector<Position*> neighbors = getNeighbors(current);

        for (int i = 0; i < neighbors.size(); ++i) {
          Position * neighbor = neighbors[i];

            if (!neighbor -> visited) {
                maze_queue.push(neighbor);
                neighbor -> predecessor = current;
                neighbor -> visited = true;
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

    path_length = 0;
    num_of_nodes_visited = 0;

    while (!toVisit.empty()) {
        Position* current = toVisit.top();
        toVisit.pop();
        num_of_nodes_visited++;

        if (current == end) {
            vector<Position*> path;
            while (current != nullptr) {
                path.push_back(current);
                current = previous[current->to_string()];
                path_length++;
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

void Maze :: print_maze() {
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      if (isWall(x, y)) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
}