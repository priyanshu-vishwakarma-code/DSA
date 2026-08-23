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
        // RECURSION + MEMORIZATION
        // int m = mat.size() , n = mat[0].size();
        // vector<vector<int>>dp(m, vector<int>(n,-1));
        // int maxans = 0;
        // for(int i = 0 ; i<m ; i++){
        //     for(int j = 0 ; j<n ; j++){
        //         if(mat[i][j] == '0') continue;
        //         int ans = solve(i, j, dp, mat);
        //         maxans = max(maxans, ans);
        //     }
        // }
        // return maxans * maxans;  

        // TABULATION
        int m = mat.size() , n = mat[0].size();
        vector<vector<int>>dp(m, vector<int>(n,0));
        int maxans = 0;
        for(int i = 0 ; i<m ; i++){
            dp[i][0] = mat[i][0] - '0';
            maxans = max(maxans, dp[i][0]);
        } 
        for(int j = 0 ; j<n ; j++){
            dp[0][j] = mat[0][j] - '0';
            maxans = max(maxans, dp[0][j]);
        } 
        
        for(int i = 1 ; i<m ; i++){
            for(int j = 1 ; j<n ; j++){
                if(mat[i][j] == '0') continue;
                int left = dp[i][j-1], top = dp[i-1][j], digonal = dp[i-1][j-1];
                dp[i][j] = 1 + min(left, min(top, digonal));
                maxans = max(maxans, dp[i][j]);
            }
        }
        return maxans * maxans;
    }
};