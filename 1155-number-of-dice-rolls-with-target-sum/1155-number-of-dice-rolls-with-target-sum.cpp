class Solution {
public:
    const int MOD = 1'000'000'007;

    int solve(int n, int k, int tar, vector<vector<int>>&dp){
        if(tar < 0) return 0;
        if(n == 0){
            if(tar == 0) return 1;
            else return 0;
        }

        if(dp[n][tar] != -1) return dp[n][tar];

        long long count = 0;
        for(int i = 1 ; i<=k ; i++){
            count = (count + solve(n-1, k, tar-i, dp)) % MOD;
        }
        
        return dp[n][tar] = count;
    }

    int numRollsToTarget(int n, int k, int target) {

        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        int ans = solve(n, k, target, dp);        

        return ans % MOD;
    }
};