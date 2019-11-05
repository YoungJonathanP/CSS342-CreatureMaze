#include <iostream>

#include "creature.h"
#include "maze.h"

// Created by Jonathan Young on 10/20-2019
// Creature maze solver

// Provided test
void test() {
    Maze M("maze.txt");
    // cout << m << endl;
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}

// test larger maze size
void test1() {
    Maze M1("maze1.txt");
    Creature C(17, 4);
    cout << "Path: " << C.solve(M1) << endl;
    cout << M1 << endl;
}

// straight to end test
void test2() {
    Maze M2("maze2.txt");
    Creature C(4, 18);
    cout << "Path: " << C.solve(M2) << endl;
    cout << M2 << endl;
}

// dead end test
void test3() {
    Maze M3("maze3.txt");
    Creature C(4, 18);
    cout << "Path: " << C.solve(M3) << endl;
    cout << M3 << endl;
}

// Main test functions
int main() {
    //test();
    //test1();
    test2();
    //test3();
    cout << "Done!" << std::endl;
    return 0;
}