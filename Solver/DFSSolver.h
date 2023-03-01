#include<bits/stdc++.h>
#include "../model/Rubikscube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

template<typename T, typename H>
class DFSSolver{
    private:
    int max_search_depth;
    vector<RubiksCube::MOVE> moves;

    bool dfs(int dep){
        if(rubiksCube.isSolved()) return true;
        if(dep > max_search_depth) return false;

        for(int i = 0; i<18; i++){
            rubiksCube.makeMove(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            if(dfs(dep + 1)) return true;
            rubiksCube.invert(RubiksCube::MOVE(i));
            moves.pop_back();
        }
        return false;
    }

    public:

    T rubiksCube;
    DFSSolver(T _rubiksCube, int _max_search_depth = 8){
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<RubiksCube::MOVE> solve(){
        dfs(1);
        return moves;
    }

};

#endif