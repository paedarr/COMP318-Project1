# ***AUTHORS - Paedar Rader, Gavin Graham***

# PROJECT SPLITS:
## Paedar's Work - 
DFS Algorithm, Position Class Implementation, Dictionary Impl., Main Impl., Maze Class Impl., README.md, Test Debugging
#### Est. Time: ~15 hours

## Gavin's Work - 
BFS Algorithm, Maze Class Implementation, Assisted w/ Position+Dictionary, Test Debugging, BFS Research
#### Est. Time: ~11 hours + Tutoring

**Both of us met at the library multiple times, and there, spent upwards of 6 hours debugging and working on code together.**
---

# **Project Description**
#### This project is focused on the traversal of a maze, represented as a vector of Position object pointers. Utilizing the Position class, and its methods, allows for a more detailed, and functional traversal of the maze. The program uses multiple files, and has some dependencies, which are listed below in the _dependencies_ category.

---

# **Dependencies/File List**
#### All of the following files are required for the program to compile, and run, successfully:
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

---

# **How to Compile & Run**
#### ***Follow the steps below to Compile and Run the program properly***:
1. Make sure all files listed in the _dependencies_ category are located within the same directory. 
2. Using any C++ compiler, preferably g++, and compile main.cpp using the following command in terminal/shell:
> g++ main.cpp mazeUtils.cpp position.cpp maze.cpp myDictionary.cpp
**or**
> g++ test.cpp mazeUtils.cpp position.cpp maze.cpp myDictionary.cpp
> _use this command for the testing cases file (test.cpp)_
3. If program compiles with no errors, next command line should prompt, where you should then type:
> ./a.out
4. Program should now be outputting and prompting user input in the terminal, where the program asks for the location of the .map file. If you use direct file location specification (not specifying a file path), make sure the location of the .map file is in the
same place as the .cpp files. If the file is located elsewhere, please specify the complete filepath to reach the .map file.
> (ex.) /Algorithms318/maze_project/labyrinths/example2.map
> _Put this entire command into the input prompt_
5. Then, if the location is found, the program will then prompt the user to either do a DFS or BFS on the maze. 
6. Once chosen which search to do, the user is prompted for the desired name of the output file where the traversal of the maze (the path) is outputted to. The user does **not** have to specify the file extension name (_like say, .txt_), as the output will be in the .txt format anyways.
7. If the maze is valid, then the chosen Algorithm traverses the maze using the given search. This process, as well as other visual indication (like the number of nodes visited) are outputted to the terminal for the user to see. The user should see two mazes, one before the traversal, and one after showing the path. If an empty maze is given, or a maze with no possible solution, there is proper error handling, and the user will be aware of what occured.
8. If executed correctly, the program should conclude and the user should be brought back to their command prompt. 


---


# **SAMPLE RUNS:**

### Test 1 (DFS - example2.map):
```
Welcome to The A-Maze-ing Race.
where is your maze file? /home/ubuntu/workspace/labyrinths/example2.map
BFS or DFS search?:
DFS
Please enter name of desired output file:
DFS2out

Loading /home/ubuntu/workspace/labyrinths/example2.map...
5 6
.#..#
...##
##.#.
...##
.###.
.....

DFS Searching...
@#..#
@@@##
##@#.
@@@##
@###.
@@@@@


Path length: 14
'#' of visited nodes: 14
```
*As you can see, DFS works properly, and handles the traversal well, given the correct information.*

### Test 2 (BFS - example5.map):
```
Welcome to The A-Maze-ing Race.
where is your maze file? example5.map
BFS or DFS search?:
BFS
Please enter name of desired output file:
BFS5out    

Loading example5.map...
9 9
........#
#.#####..
...#...#.
.###.#.#.
...#.#.#.
##.#.#.#.
...#.#.#.
.###.#.#.
.....#...

BFS Searching...
@@@@@@@@#
#.#####@@
...#...#@
.###.#.#@
...#.#.#@
##.#.#.#@
...#.#.#@
.###.#.#@
.....#..@


Path length: 17
# of visited nodes: 32
```