class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m = mat.size() , n = mat[0].size();

        int strow = 0 , endrow = m-1;
        while(strow<=endrow){
            int midrow = strow + ((endrow-strow)/2);
            if(mat[midrow][0]<= tar && tar<=mat[midrow][n-1]){
                int st = 0 , end = n-1;
                bool found = false;
                while(st<=end){
                    int mid = st + ((end-st)/2);
                    if(mat[midrow][mid]==tar){
                        found = true;
                        break;
                    }
                    else if(mat[midrow][mid]<tar) st = mid + 1;
                    else end = mid - 1;
                }
                return found;
            }
            else if(tar<mat[midrow][0]) endrow = midrow - 1;
            else if(tar>mat[midrow][n-1]) strow = midrow + 1;
        }
        return false;
    }
};