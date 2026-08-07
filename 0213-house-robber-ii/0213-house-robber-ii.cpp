class Solution {
public:
    int recursion(int i, int n, vector<int>&dp, vector<int>&nums){
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        int rob = nums[i] + recursion(i+2, n, dp, nums);
        int skip = recursion(i+1, n, dp, nums);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);

        vector<int>dp(n, -1);
        int robfirst = recursion(0, n-2, dp, nums);
        dp.assign(n, -1);
        int roblast = recursion(1, n-1, dp, nums);
        

        return max(robfirst, roblast);
    }
};