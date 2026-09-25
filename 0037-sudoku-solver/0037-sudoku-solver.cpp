class Solution {
public:
    bool issafe(vector<vector<char>>&board,int row, int col, int num){
        char n = num + '0';

        //horizontal
        for(int j = 0 ; j<9 ; j++)
            if(board[row][j]==n) return false;

        //vertical
        for(int i = 0 ; i<9 ; i++)
            if(board[i][col]==n) return false;

        //3x3 grid
        int i;
        if(row>= 0 && row<=2) i = 0;
        else if(row>= 3 && row<=5) i = 3;
        else if(row >= 6 && row <= 8) i = 6;

        int j;
        if(col>= 0 && col<=2) j = 0;
        else if(col >= 3 && col <= 5) j = 3;
        else if(col >= 6 && col <= 8) j = 6;

        for(int a = 0 ; a<3 ; a++){
            for(int b = 0 ; b<3 ; b++){
                if(board[i+a][j+b]==n) return false;
            }
        }

        //none of the above is true, hence it's safe
        return true;
    }
    bool solve(vector<vector<char>>&board){
        for(int row = 0 ; row<9 ; row++){
            for(int col = 0 ; col<9 ; col++){
                if(board[row][col]=='.'){
                    for(int num = 1 ; num<=9 ; num++){
                        if(issafe(board,row,col,num)){
                            board[row][col] = num + '0';
                            if(solve(board)) return true;
                            board[row][col] = '.';  
                        }   
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};