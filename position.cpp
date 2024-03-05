/* Comp 318 Spring 2023, programming assignment 2
 * Copyright (c) 2023
 * Wheaton College, Computer Science Department, Norton MA
 * M. Gagne
 */

#include "position.h"
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

Position::Position(int x, int y) {
  xPos = x;
  yPos = y;
  // make sure to implement wall detection based on maze's current char
}

int Position::getX()  {
  return xPos;
}

int Position::getY() {
  return yPos;
}

void Position::setWall()  {
  wall = true;
}

bool Position::isWall()  {
  if (wall == true){
    return true;
  }
  else{
    return false;
  }
}

string Position::to_string()  {
  string str1, str2;

  stringstream ss1, ss2;
  ss1 << xPos;
  ss2 << yPos;
  ss1 >> str1;
  ss2 >> str2;

  string coords = str1 + "," + str2;
  return coords;
}
