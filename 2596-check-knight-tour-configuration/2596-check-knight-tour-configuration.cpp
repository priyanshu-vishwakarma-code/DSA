class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        return recursion(grid,0,0,grid.size(),0);
    }

    bool recursion(vector<vector<int>>&grid, int row, int col, int n, int expmove){
        if(row<0 || row>n-1 || col<0 || col>n-1 ||grid[row][col]!=expmove) return false;
        if(grid[row][col]==n*n-1) return true;

        if(recursion(grid, row-2, col+1, n, expmove+1)) return true;
        if(recursion(grid, row-1, col+2, n, expmove+1)) return true;
        if(recursion(grid, row+1, col+2, n, expmove+1)) return true;
        if(recursion(grid, row+2, col+1, n, expmove+1)) return true;
        if(recursion(grid, row+2, col-1, n, expmove+1)) return true;
        if(recursion(grid, row+1, col-2, n, expmove+1)) return true;
        if(recursion(grid, row-1, col-2, n, expmove+1)) return true;
        if(recursion(grid, row-2, col-1, n, expmove+1)) return true;

        return false;
    }
};