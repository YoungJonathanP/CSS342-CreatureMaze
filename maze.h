//
// Created by Yusuf Pisan on 4/18/18.
//

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL {
    CLEAR, WALL, PATH, VISITED
};

// Maze class
class Maze {
    // Friend overloaded insertion operator
    friend ostream &operator<<(ostream &Out, const Maze &Maze);

private:
    // max maze size
    const static int MAX_SIZE = 100;
    // sets field
    char Field[MAX_SIZE][MAX_SIZE];
    // maze predetermined dimensions
    int Width, Height;
    // maze exit row/column
    int ExitRow, ExitColumn;
public:
    // maze builder
    explicit Maze(const string &FileName);

    // checks if maze is clear
    bool isClear(int Row, int Col) const;

    // marks maze as path to take
    void markAsPath(int Row, int Col);

    // marks maze as visited point
    void markAsVisited(int Row, int Col);

    // get method for exit row
    int getExitRow() const;

    // get method for exit column
    int getExitColumn() const;

};

#endif //ASS3_MAZE_H
