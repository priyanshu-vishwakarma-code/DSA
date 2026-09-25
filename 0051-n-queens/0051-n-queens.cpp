class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));

        solve(n,board,ans,0);
        return ans;
    }

    void solve(int n , vector<string>&board, vector<vector<string>>&ans, int row){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col = 0 ; col<n ; col++){
            if(issafe(n,board,row,col)){
                board[row][col]='Q';
                solve(n,board,ans,row+1);
                board[row][col] = '.';
            }
        }
    }

    bool issafe(int n, vector<string>&board, int row, int col){
        //col check
        for(int i = 0 ; i<row ; i++) 
            if(board[i][col]=='Q') return false;

        //primary diogonal
        for(int i = row-1, j = col-1 ; i>=0 && j>=0 ; i--,j--) 
            if(board[i][j]=='Q') return false;

        //secondary diogonal
        for(int i = row-1 , j = col+1 ; i>=0 && j<n ; i--,j++) 
            if(board[i][j]=='Q') return false;

        return true;
    }
};