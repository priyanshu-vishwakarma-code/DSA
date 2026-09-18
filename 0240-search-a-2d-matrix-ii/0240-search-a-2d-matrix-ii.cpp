class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size() , n = mat[0].size();
        int row = 0 , col = n-1;

        while(col>=0 && row<m){
            if(mat[row][col]==target) return true;
            else if(target<mat[row][col]) col--;
            else if(target>mat[row][col]) row++; 
        }
        return false;
    }
};