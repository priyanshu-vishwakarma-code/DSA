class Solution {
public:
    int recursion(int n, vector<int>&dp){
       if(n==0 || n==1){
        dp[n] = n;
        return dp[n];
       }

       if(dp[n] != -1) return dp[n];

       return dp[n] = recursion(n-1, dp) + recursion(n-2, dp);
    }

    int fib(int n) {
        vector<int>dp(n+1,-1);
        return recursion(n , dp);
    }
};