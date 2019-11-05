//
// Created by Yusuf Pisan on 4/18/18.
//

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

// creature class object for maze
class Creature {
public:
    // overloaded insertion operator
    friend ostream &operator<<(ostream &Out, const Creature &Creature);

    // private creature variables
private:
    int Row;
    int Col;
    string Path;

public:
    // creature object constructor
    Creature(int Row, int Col);

    // string solution
    string solve(Maze &Maze);

    // boolean check for if creature is at maze exit
    bool atExit(const Maze &Maze) const;

    // moves creature north
    bool goNorth(Maze &Maze);

    // moves creature south
    bool goSouth(Maze &Maze);

    // moves creature east
    bool goEast(Maze &Maze);

    // moves creature west
    bool goWest(Maze &Maze);
};

#endif //ASS3_CREATURE_H
