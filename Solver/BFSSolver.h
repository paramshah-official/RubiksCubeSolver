#include<bits/stdc++.h>
#include "../model/Rubikscube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

template<typename T, typename H>
class BFSSolver{
    private:
    unordered_map<T, bool, H> vis;
    unordered_map<T, RubiksCube::MOVE, H> last_move;

    T bfs(){
        queue<T> q;
        q.push(rubiksCube);
        while(!q.empty()){
            T curr = q.front();
            q.pop();
            if(curr.isSolved()) return curr;

            for(int i = 0; i<18; i++){
                auto move = RubiksCube::MOVE(i);
                curr.makeMove(move);
                if(!vis[curr]){
                    q.push(curr);
                    last_move[curr] = move;
                }
                curr.invert(move);
            }
        }
        return rubiksCube;
    }

    public:
    T rubiksCube;

    BFSSolver(T _rubiksCube){
        rubiksCube = _rubiksCube;
    }

    vector<RubiksCube::MOVE> moves;
    vector<RubiksCube::MOVE> solve(){
        T solvedCube = bfs();
        T curr = solvedCube;
        vector<RubiksCube::MOVE> moves;
        while(!(curr == rubiksCube)){
            auto move = last_move[curr];
            moves.push_back(move);
            curr.invert(move);
        }

        rubiksCube = solvedCube;
        return moves;
    }
};



#endif