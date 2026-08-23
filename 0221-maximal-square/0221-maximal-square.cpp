class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dp, vector<vector<char>>&mat){
        if(i >= mat.size() || j >= mat[0].size()) return 0;
        if(mat[i][j] == '0') return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j+1, dp, mat);
        int down = solve(i+1, j, dp, mat);
        int digonal = solve(i+1, j+1, dp, mat);

        int ans;
        ans = 1 + min(right, min(down, digonal));
        return dp[i][j] = ans;
    }

    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size() , n = mat[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        int maxans = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(mat[i][j] == '0') continue;
                int ans = solve(i, j, dp, mat);
                maxans = max(maxans, ans);
            }
        }
        return maxans * maxans;  
    }
};