//
// Created by Yusuf Pisan on 4/18/18.
// Jonathan Young 10/20/2019
// A creature maze that finds, marks and returns a path and directions out
//

#include <sstream>
#include "creature.h"

using namespace std;

// 5-  prints current location of creature, for example C(7,3)
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
    Out << "C(" << Creature.Col << ", " << Creature.Row << ')';
    return Out;
}

/*
 * Creature constructor. Sets Path to empty string.
 */
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {
    Path = "";
}

// Returns true if creature is at exit, false otherwise
bool Creature::atExit(const Maze &Maze) const {
    return (Row == Maze.getExitRow()) && (Col == Maze.getExitColumn());
}


// returns a string in the form of NNEEN
// (where N means North, E means East, etc)
string Creature::solve(Maze &Maze) {
    //string Path;
    Maze.markAsPath(Row, Col);
    if (!atExit(Maze)) {
        if (goNorth(Maze)) {
            goNorth(Maze);
        }
        if (goWest(Maze)) {
            goWest(Maze);
        }
        if (goEast(Maze)) {
            goEast(Maze);
        }
        if (goSouth(Maze)) {
            goSouth(Maze);
        }

    }
    if (!atExit(Maze)) {
        Path.append("X");
    }
    return Path;

}

// Moves creature North, checks if movement is available recursively.
bool Creature::goNorth(Maze &Maze) {
    bool Success = false;
    if (Maze.isClear(Row - 1, Col)) {
        Row--;
        Path.append("N");
        Maze.markAsPath(Row, Col);
        if (atExit(Maze)) {
            Success = true;
        } else {
            Success = goNorth(Maze);
            if (!Success) {
                Success = goWest(Maze);
                if (!Success) {
                    Success = goEast(Maze);
                    if (!Success) {
                        Maze.markAsVisited(Row, Col);
                        Row++;
                        Path.pop_back();
                    }
                }
            }
        }
    }
    return Success;
}

// Moves creature West, checks if movement is available recursively.
bool Creature::goWest(Maze &Maze) {
    bool Success = false;
    if (Maze.isClear(Row, Col - 1)) {
        Col--;
        Path.append("W");
        Maze.markAsPath(Row, Col);
        if (atExit(Maze)) {
            Success = true;
        } else {
            Success = goWest(Maze);
            if (!Success) {
                Success = goNorth(Maze);
                if (!Success) {
                    Success = goSouth(Maze);
                    if (!Success) {
                        Maze.markAsVisited(Row, Col);
                        Col++;
                        Path.pop_back();
                    }
                }
            }
        }
    }
    return Success;
}

// Moves creature East, checks if movement is available recursively.
bool Creature::goEast(Maze &Maze) {
    bool Success = false;
    if (Maze.isClear(Row, Col + 1)) {
        Col++;
        Path.append("E");
        Maze.markAsPath(Row, Col);
        if (atExit(Maze)) {
            Success = true;
        } else {
            Success = goEast(Maze);
            if (!Success) {
                Success = goNorth(Maze);
                if (!Success) {
                    Success = goSouth(Maze);
                    if (!Success) {
                        Maze.markAsVisited(Row, Col);
                        Col--;
                        Path.pop_back();
                    }
                }
            }
        }
    }
    return Success;
}

// Moves creature South, checks if movement is available recursively.
bool Creature::goSouth(Maze &Maze) {
    bool Success = false;
    if (Maze.isClear(Row + 1, Col)) {
        Row++;
        Path.append("S");
        Maze.markAsPath(Row, Col);
        if (atExit(Maze)) {
            Success = true;
        } else {
            Success = goSouth(Maze);
            if (!Success) {
                Success = goWest(Maze);
                if (!Success) {
                    Success = goEast(Maze);
                    if (!Success) {
                        Maze.markAsVisited(Row, Col);
                        Row--;
                        Path.pop_back();
                    }
                }
            }
        }
    }
    return Success;
}