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
        // if(n == 0 || n == 1) return n;
        // vector<int>dp(n+1, -1);
        // return recursion(n, dp);

        // TABULATION
        if(n==0 || n==1) return n;
        vector<int>dp(n+1, INT_MAX-1);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2 ; i<=n ; i++){
            for(int j = 1 ; j*j<=i ; j++){
                int sq = j*j;
                if(i - sq >= 0)
                dp[i] = min(dp[i], 1+dp[i-sq]);
            }
        }
        return dp[n];
        
    }
};