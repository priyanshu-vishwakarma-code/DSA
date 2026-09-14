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

        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, -1, dp, nums);
    }
};