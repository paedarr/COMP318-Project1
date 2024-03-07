/* 
 * Comp 318 Spring 2024, Programming Assignment 1
 * Wheaton College MA
 * Authors: Gavin Graham & Paedar Rader
 */

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#include "mazeUtils.h"
#include "maze.h"
#include "position.h"
#include "myDictionary.h"

using namespace std;

int main() {
  // Initial code to read input from cin.
  // You shouldn't need to modify this portion of code
  cout << "Welcome to The A-Maze-ing Race." << endl;
  string map;
  cout << "where is your maze file? ";
  cin >> map;

  Maze* userMaze = loadMap(map);

  // TODO: write code that will solve the maze, ask the user for output file and
  //       write the solution to that file.

   vector<Position*> solutionPath;
   bool valid = false;

  string outputName = "";
  string search;

    while (!valid){
      cout << "BFS or DFS search?:" << endl;
      cin >> search;
      if (search == "BFS"){
        cout << "Please enter name of desired output file:" << endl;
        cin >> outputName;
        solutionPath = userMaze->solveBreadthFirst();
        valid = true;
      }
      else if (search == "DFS"){
        cout << "Please enter name of desired output file:" << endl;
        cin >> outputName;
        solutionPath = userMaze->solveDepthFirst();
        valid = true;
      }
      else {
          cout << "Invalid search algorithm. Please enter BFS or DFS." << endl;
      }
   }

   string solution_output = renderAnswer(userMaze, solutionPath);

    cout << endl;
    cout << "Loading " << map << "..." << endl;
    cout << userMaze->getWidth() << " " << userMaze->getHeight() << endl;
    userMaze->print_maze();
    cout << endl;
    cout << search << " Searching..." << endl;
    cout << solution_output << endl;
    cout << endl;
    if (userMaze->path_length == 0){
      cout << "** No valid path! Start and end have no possible traversals. **" << endl;
    }
    cout << "Path length: " << userMaze->path_length << endl;
    cout << "# of visited nodes: " << userMaze->num_of_nodes_visited << endl;

   ofstream outputFile(outputName);
    if (!outputFile.is_open()) {
        cout << "Error: Unable to open file " << outputName << ". Program shutting down, as there is an error." << endl;
        return 1;
    }

    outputFile << solution_output;
    outputFile.close();


  return 0;
}
