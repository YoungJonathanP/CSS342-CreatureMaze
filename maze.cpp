//
// Created by Yusuf Pisan on 4/18/18.
// Created by Jonathan Young on 10/20/2019
//

#include <fstream>
#include <iostream>
#include "maze.h"

using namespace std;

// overloaded insertion operator
ostream &operator<<(ostream &Out, const Maze &Maze) {
    for (int Row = 0; Row < Maze.Height; ++Row) {
        for (int Col = 0; Col < Maze.Width; ++Col) {
            Out << Maze.Field[Row][Col];
        }
        Out << endl;
    }
    Out << endl;
    return Out;
}

// For Clion, need the following line in CMakeLists.txt so maze.txt is found
// at the same location as the cpp files
// # need to load data files from current directory as cpp files
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
// You can assume that mazes will have less than 100 rows and 100 columns.
Maze::Maze(const string &FileName) {
    ifstream InFile;
    InFile.open(FileName);
    if (!InFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    InFile >> Width >> Height;
    InFile >> ExitRow >> ExitColumn;
    string Str;
    getline(InFile, Str);
    for (int Row = 0; Row < Height; ++Row) {
        for (int Col = 0; Col < Width; ++Col) {
            InFile.get(Field[Row][Col]);
            // cout << Row << ", " << col << ": " << field[Row][col] << endl;
        }
        getline(InFile, Str);
    }

}

// Get method for finding Exit Row
int Maze::getExitRow() const {
    return ExitRow;
}

// get method for finding Exit Column
int Maze::getExitColumn() const {
    return ExitColumn;
}

// Boolean check method for availability of next space
bool Maze::isClear(int Row, int Col) const {
    return Field[Row][Col] == ' ';
}

// Marks maze for path to exit
void Maze::markAsPath(int Row, int Col) {
    Field[Row][Col] = '*';
}

// Marks path for space that does not offer way out
void Maze::markAsVisited(int Row, int Col) {
    Field[Row][Col] = '+';
}
