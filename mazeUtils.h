/* Comp 318 Spring 2023, programming assignment 2
 * Copyright (c) 2023
 * Wheaton College, Computer Science Department, Norton MA
 * M. Gagne
 */

#ifndef PRGASST02_MAZEUTILS_H
#define PRGASST02_MAZEUTILS_H

#include "maze.h"
#include "position.h"

#include <string>
#include <vector>
using std::string;
using std::vector;

/*
 * Reads a map from the specified file.
 * @param filename The name of the map file.
 * @return A pointer to the Maze object containing that map.  Deleting this
 *         object is the caller's responsibility.
 * @throws runtime_error If an error occurs while reading the file.
 */
Maze* loadMap(string filename);

/**
 * Transforms a solution into a string.
 * @param maze The Maze to use.
 * @param solution A list of the Position objects in the path.
 * @return The string representing the solution.
 */
string renderAnswer(Maze* maze, vector<Position*> solution);

#endif //PRGASST02_MAZEUTILS_H
