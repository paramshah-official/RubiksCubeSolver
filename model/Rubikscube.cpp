#include "Rubikscube.h"

string RubiksCube::getMove(MOVE move){
    switch (move){
        case MOVE::L: return "L";
        case MOVE::LPRIME: return "L'";
        case MOVE::L2: return "L2";
        case MOVE::R: return "R";
        case MOVE::RPRIME: return "R'";
        case MOVE::R2: return "R2";
        case MOVE::U: return "U";
        case MOVE::UPRIME: return "U'";
        case MOVE::U2: return "U2";
        case MOVE::D: return "D";
        case MOVE::DPRIME: return "D'";
        case MOVE::D2: return "D2";
        case MOVE::F: return "F";
        case MOVE::FPRIME: return "F'";
        case MOVE::F2: return "F2";
        case MOVE::B: return "B";
        case MOVE::BPRIME: return "B'";
        case MOVE::B2: return "B2";
    }
}

char RubiksCube::getColorLetter(COLOR color){
    switch (color)
    {
    case COLOR::BLUE: return 'B';
    case COLOR::YELLOW: return 'Y';
    case COLOR::GREEN: return 'G';
    case COLOR::RED: return 'R';
    case COLOR::WHITE: return 'W';
    case COLOR::ORANGE: return 'O';
    }
}


//function to make move
RubiksCube &RubiksCube::makeMove(MOVE move){
    switch (move)
    {
        case MOVE::L: return this->l();
        case MOVE::LPRIME: return this->lprime();
        case MOVE::L2: return this->l2();
        case MOVE::R: return this->r();
        case MOVE::RPRIME: return this->rprime();
        case MOVE::R2: return this->r2();
        case MOVE::U: return this->u();
        case MOVE::UPRIME: return this->uprime();
        case MOVE::U2: return this->u2();
        case MOVE::D: return this->d();
        case MOVE::DPRIME: return this->dprime();
        case MOVE::D2: return this->d2();
        case MOVE::F: return this->f();
        case MOVE::FPRIME: return this->fprime();
        case MOVE::F2: return this->f2();
        case MOVE::B: return this->b();
        case MOVE::BPRIME: return this->bprime();
        case MOVE::B2: return this->b2();
    }
}

//Inverts the move
RubiksCube &RubiksCube::invert(MOVE move){
    switch (move)
    {
        case MOVE::L2: return this->l();
        case MOVE::LPRIME: return this->lprime();
        case MOVE::L: return this->l2();
        case MOVE::R2: return this->r();
        case MOVE::RPRIME: return this->rprime();
        case MOVE::R: return this->r2();
        case MOVE::U2: return this->u();
        case MOVE::UPRIME: return this->uprime();
        case MOVE::U: return this->u2();
        case MOVE::D2: return this->d();
        case MOVE::DPRIME: return this->dprime();
        case MOVE::D: return this->d2();
        case MOVE::F2: return this->f();
        case MOVE::FPRIME: return this->fprime();
        case MOVE::F: return this->f2();
        case MOVE::B2: return this->b();
        case MOVE::BPRIME: return this->bprime();
        case MOVE::B: return this->b2();
    }
}

void RubiksCube::print() const {
    cout<<"Rubiks Cube: \n\n";

    // Orange center
    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    //Green White Blue and Yellow Centers
    for (int row = 0; row <= 2; row++) {
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        }
        cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        }
        cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        }
        cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    //Red Center
    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Randomly shuffles moves for the rubik's cube function
vector<RubiksCube::MOVE> RubiksCube::RandomShuffleCube(unsigned int times){
    vector<MOVE> moves_performed;
    srand(time(0));

    for(unsigned int i = 0; i<times; i++){
        unsigned int selectMove = (rand()%18);
        moves_performed.push_back(static_cast<MOVE>(selectMove));
        this->makeMove(static_cast<MOVE>(selectMove));
    }

    return moves_performed;
}

// Corner cubie
string RubiksCube::getCornerColorString(uint8_t ind) const {
    string str = "";

    switch (ind) {
//        UFR
        case 0:
            str += getColorLetter(getColor(FACE::UP, 2, 2));
            str += getColorLetter(getColor(FACE::FRONT, 0, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;

//            UFL
        case 1:
            str += getColorLetter(getColor(FACE::UP, 2, 0));
            str += getColorLetter(getColor(FACE::FRONT, 0, 0));
            str += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;

//            UBL
        case 2:
            str += getColorLetter(getColor(FACE::UP, 0, 0));
            str += getColorLetter(getColor(FACE::BACK, 0, 2));
            str += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;

//            UBR
        case 3:
            str += getColorLetter(getColor(FACE::UP, 0, 2));
            str += getColorLetter(getColor(FACE::BACK, 0, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;

//            DFR
        case 4:
            str += getColorLetter(getColor(FACE::DOWN, 0, 2));
            str += getColorLetter(getColor(FACE::FRONT, 2, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;

//            DFL
        case 5:
            str += getColorLetter(getColor(FACE::DOWN, 0, 0));
            str += getColorLetter(getColor(FACE::FRONT, 2, 0));
            str += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;

//            DBR
        case 6:
            str += getColorLetter(getColor(FACE::DOWN, 2, 2));
            str += getColorLetter(getColor(FACE::BACK, 2, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;

//            DBL
        case 7:
            str += getColorLetter(getColor(FACE::DOWN, 2, 0));
            str += getColorLetter(getColor(FACE::BACK, 2, 2));
            str += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
    }
    return str;
}