/* 
 * Comp 318 Spring 2024, Programming Assignment 1
 * Wheaton College MA
 * Authors: Gavin Graham & Paedar Rader
 */

#include "position.h"
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

Position::Position(int x, int y) {
  xPos = x;
  yPos = y;
  wall = false;
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
  return wall;
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
