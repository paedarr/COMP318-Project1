/* Comp 318 Spring 2023, programming assignment 2
 * Copyright (c) 2023
 * Wheaton College, Computer Science Department, Norton MA
 * M. Gagne
 */

#include <iostream>
#include <string>
#include <utility>

#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main() {
  // Initial code to read input from cin.
  // You shouldn't need to modify this portion of code
  cout << "Welcome to The A-Maze-ing Race." << endl;
  string map;
  cout << "where is your maze file? ";
  cin >> map; //does this error check?

  // TODO: write code that will solve the maze, ask the user for output file and
  //       write the solution to that file.

   vector<Position*> solutionPath;
   bool valid = false;

  string outputName = "";

    while (!valid){
      string search;
      cout << "BFS or DFS search?:" << endl;
      cin >> search;
      if (search == "BFS"){
        cout << "Please enter name of desired output file:" << endl;
        cin >> outputName;
        Maze* userMaze = loadMap(map);
        solutionPath = userMaze->solveBreadthFirst();
        valid = true;
      }
      else if (search == "DFS"){
        cout << "Please enter name of desired output file:" << endl;
        cin >> outputName;
        Maze* userMaze = loadMap(map);
        solutionPath = userMaze->solveDepthFirst();
        valid = true;
      }
      else {
          cout << "Invalid search algorithm. Please enter BFS or DFS." << endl;
      }
   }

   string solution_output = renderAnswer(userMaze, solutionPath);

   ofstream outputFile(outputName);
    if (!outputFile.is_open()) {
        cout << "Error: Unable to open file " << outputName << ". Program shutting down, as there is an error." << endl;
        return 1;
    }
    outputFile << solutionString;
    outputFile.close();


  return 0;
}
