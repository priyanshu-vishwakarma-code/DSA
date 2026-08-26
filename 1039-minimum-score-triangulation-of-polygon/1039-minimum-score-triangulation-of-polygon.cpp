class Solution {
public:
    int recursion(int i, int j, vector<vector<int>>&dp, vector<int>&v){
        if(i+1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i+1 ; k<j ; k++){
            ans = min(ans, (v[i]*v[j]*v[k]) + recursion(i, k, dp, v) + recursion(k, j, dp, v));
        }
        
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return recursion(0, n-1, dp, values);
    }
};