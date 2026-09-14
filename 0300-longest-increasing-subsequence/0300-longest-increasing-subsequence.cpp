class Solution {
public:
    int solve(int curr, int last, vector<vector<int>>&dp, vector<int>&nums){
        if(curr >= nums.size()) return 0;

        if(last != -1 && dp[curr][last] != -1) return dp[curr][last];
        
        int include = 0;
        if(last == -1 || nums[last] < nums[curr]){
            include = 1 + solve(curr+1, curr, dp, nums);
        }

        int exclude = solve(curr+1, last, dp, nums);

        int ans = max(include, exclude);
        if(last != -1) dp[curr][last] = ans;
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // RECURSION + MEMORIZATION
        // vector<vector<int>>dp(n, vector<int>(n, -1));
        // return solve(0, -1, dp, nums);

        // TABULATION
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int curr = n-1; curr>=0 ; curr--){
            for(int last = curr-1 ; last>=-1 ; last--){
                int include = 0;
                if(last == -1 || nums[last] < nums[curr]){
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = dp[curr+1][last+1];
                
                int ans = max(include, exclude);
                dp[curr][last+1] = ans;
            }
        }
        return dp[0][0];

    }
};