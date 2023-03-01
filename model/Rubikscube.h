#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

class RubiksCube{
public:
    //Defining all the colors
    enum class COLOR{
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    //Defining all the faces
    enum class FACE{
        UP,
        LEFT, FRONT, RIGHT, BACK,
        DOWN
    };

    // defining all the possible moves
    enum class MOVE{
        F, FPRIME, F2,
        B, BPRIME, B2,
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2
    };

    // Tells whether the cube is solved or not
    virtual bool isSolved() const = 0;

    // gives the move in string
    static string getMove(MOVE move);

    // gets the color of the cubie
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    // Function for color letter
    static char getColorLetter(COLOR color);

    // The functions that needs to trigger the moves
    RubiksCube &makeMove(MOVE ind);

    //Invert the move
    RubiksCube &invert(MOVE ind);

    // 18 possible moves functions
    virtual RubiksCube &l() = 0;
    virtual RubiksCube &lprime() = 0;
    virtual RubiksCube &l2() = 0;
    virtual RubiksCube &r() = 0;
    virtual RubiksCube &rprime() = 0;
    virtual RubiksCube &r2() = 0;
    virtual RubiksCube &f() = 0;
    virtual RubiksCube &fprime() = 0;
    virtual RubiksCube &f2() = 0;
    virtual RubiksCube &b() = 0;
    virtual RubiksCube &bprime() = 0;
    virtual RubiksCube &b2() = 0;
    virtual RubiksCube &u() = 0;
    virtual RubiksCube &uprime() = 0;
    virtual RubiksCube &u2() = 0;
    virtual RubiksCube &d() = 0;
    virtual RubiksCube &dprime() = 0;
    virtual RubiksCube &d2() = 0;

    //printing the rubiks cube
    void print() const;

    // gets the random moves
    vector<MOVE> RandomShuffleCube(unsigned int times);

    //function to get the corner cubie
    string getCornerColorString(uint8_t ind) const;
    
};

#endif