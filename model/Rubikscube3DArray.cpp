#include "Rubikscube.cpp"

class RubiksCube3DArray:public RubiksCube{
    private:
    //Will add any helper functions here

    //Function to rotate a particular face int clock wise fashion
    void rotateFace(int ind){
        char temp_arr[3][3];
        for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) temp_arr[i][j] = cube[ind][i][j];

        for(int i = 0; i<3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
        for(int i = 0; i<3; i++) cube[ind][i][0] = temp_arr[2][i];
        for(int i = 0; i<3; i++) cube[ind][2][i] = temp_arr[2 - i][2];
        for(int i = 0; i<3; i++) cube[ind][i][2] = temp_arr[0][i];
    }

    public:
    //Our Basic 3D cube
    char cube[6][3][3];

    //Setting up the initial colors (Solved)
    RubiksCube3DArray(){
        for(int i = 0; i<6; i++){
            for(int j = 0; j<3; j++){
                for(int k = 0; k<3; k++){
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    //Implementing the isSolved function
    bool isSolved() const override{
        for(int i = 0; i<6; i++){
            for(int j = 0; j<3; j++){
                for(int k = 0; k<3; k++){
                    if(this->cube[i][j][k] != getColorLetter(COLOR(i))) return false;
                }
            }
        }
        return true;
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override{
        char color = cube[(int)face][row][col];
        switch(color){
            case 'W': return COLOR::WHITE;
            case 'G': return COLOR::GREEN;
            case 'R': return COLOR::RED;
            case 'B': return COLOR::BLUE;
            case 'O': return COLOR::ORANGE;
            case 'Y': return COLOR::YELLOW;
        }
    }

    RubiksCube &l() override{
        //WHITE - RED - YELLOW - ORANGE will be affected
        //0 - 2 - 5 - 4
        // cout<<"This fn was called\n";
        rotateFace(1);
        char temp_arr[3]={};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &l2() override{
        this->l();
        this->l();
        return *this;
    }

    RubiksCube &lprime() override{
        this->l2();
        this->l();
        return *this;
    }

    RubiksCube &r() override{
        //WHITE - RED - YELLOW - ORANGE will be affected
        //0 - 2 - 5 - 4
        rotateFace(3);
        char temp_arr[3];
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &r2() override{
        this->r();
        this->r();
        return *this;
    }

    RubiksCube &rprime() override{
        this->r2();
        this->r();
        return *this;
    }
    RubiksCube &u() override{
        //WHITE - RED - YELLOW - ORANGE will be affected
        //0 - 2 - 5 - 4
        rotateFace(0);
        char temp_arr[3];
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        return *this;
    }

    RubiksCube &u2() override{
        this->u();
        this->u();
        return *this;
    }

    RubiksCube &uprime() override{
        this->u2();
        this->u();
        return *this;
    }
    RubiksCube &d() override{
        //WHITE - RED - YELLOW - ORANGE will be affected
        //0 - 2 - 5 - 4
        rotateFace(5);
        char temp_arr[3];
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    RubiksCube &d2() override{
        this->d();
        this->d();
        return *this;
    }

    RubiksCube &dprime() override{
        this->d2();
        this->d();
        return *this;
    }
    RubiksCube &f() override{
        //WHITE - RED - YELLOW - ORANGE will be affected
        //0 - 2 - 5 - 4
        rotateFace(2);
        char temp_arr[3];
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];
        return *this;
    }

    RubiksCube &f2() override{
        this->f();
        this->f();
        return *this;
    }

    RubiksCube &fprime() override{
        this->f2();
        this->f();
        return *this;
    }

    RubiksCube &b() override{
        //WHITE - RED - YELLOW - ORANGE will be affected
        //0 - 2 - 5 - 4
        rotateFace(4);
        char temp_arr[3];
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &b2() override{
        this->b();
        this->b();
        return *this;
    }

    RubiksCube &bprime() override{
        this->b2();
        this->b();
        return *this;
    }

    bool operator==(const RubiksCube3DArray &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubiksCube3DArray &operator=(const RubiksCube3DArray &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const RubiksCube3DArray &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }
};