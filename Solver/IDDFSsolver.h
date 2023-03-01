#include<bits/stdc++.h>
#include "../model/Rubikscube.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

template<typename T, typename H>
class IDDFSSolver{
    private:
    int max_search_depth;
    int comp;
    vector<RubiksCube::MOVE> moves;

    bool dfs(int dep){
        if(rubiksCube.isSolved()) return true;
        if(dep > comp) return false;

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
    IDDFSSolver(T _rubiksCube, int _max_search_depth = 8){
        rubiksCube = _rubiksCube;
        comp = _max_search_depth;
        max_search_depth = _max_search_depth;
    }

    vector<RubiksCube::MOVE> solve(){
        for(int i = 1; i<=max_search_depth; i++){
            moves.clear();
            comp = i;
            if(dfs(1)) {
                return moves;
            }
        }
    }

};

#endif