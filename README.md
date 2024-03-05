# ***AUTHORS - Paedar Rader, Gavin Graham***

# PROJECT SPLITS:
## Paedar's Work - 
### DFS Algorithm, Position Class Implementation, Dictionary Impl., Main Impl., Asst. w/ Maze, README.md
### Est. Time: ~11 hours

## Gavin's Work - 
### BFS Algorithm, Maze Class Implementation, Assisted w/ Position+Dictionary
### Est. Time: 

---

# **Project Description**
### This project is focused on the traversal of a maze, represented as a vector of Position object pointers. Utilizing the Position class, and its methods, allows for a more detailed, and functional traversal of the maze. The program uses multiple files, and has some dependencies, which are listed below in the _dependencies_ category.

# **Dependencies**
### All of the following files are required for the program to compile, and run, successfully:
+ main.cpp
+ maze.cpp
+ maze.h
+ mazeUtils.cpp
+ mazeUtils.h
+ myDictionary.cpp
+ myDictionary.h
+ position.cpp
+ position.h

> README.md file is not required, but important towards running the program, and project details
> labyrinths folder is also not required, this is just for testing purposes

# **How to Compile & Run**
### Follow the steps below to Compile and Run the program properly:
1. Make sure all files listed in the _dependencies_ category are located within the same directory. 
2. Using any C++ compiler, preferably g++, and compile main.cpp using the following command in terminal/shell:
> g++ main.cpp
3. If program compiles with no errors, next command line should prompt, where you should then type:
> ./a.out
4. Program should now be outputting and prompting user input in the terminal, where the program asks for the location of the .map file.
5. Then, if the location is found, the program will then prompt the user to either do a DFS or BFS on the maze. 
6. Once chosen which search to do, the user is prompted for the desired name of the output file where the traversal of the maze (the path) is outputted to. 