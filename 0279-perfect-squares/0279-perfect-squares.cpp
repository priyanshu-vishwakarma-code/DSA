class Solution {
public:
    int recursion(int target, vector<int>&dp){
        if(target == 0) return 0; // one possible combination of answer
        if(target < 0) return INT_MAX; // not possible through this way
        
        if(dp[target] != -1) return dp[target];

        int ans = INT_MAX;
        for(int i = 1 ; i*i<=target ; i++){
            int sq = i * i;
            int temp = recursion(target-sq, dp);
            if(temp != INT_MAX){
                ans = min(ans, temp+1);
            }
        }
        return dp[target] = ans;
    }

    int numSquares(int n) {
        if(n == 0 || n == 1) return n;
        vector<int>dp(n+1, -1);
        return recursion(n, dp);
    }
};