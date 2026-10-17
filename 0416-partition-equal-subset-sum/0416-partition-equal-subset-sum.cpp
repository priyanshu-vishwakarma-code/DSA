class Solution {
public:
    bool solve(int index, int target, vector<vector<int>>&dp, vector<int>&nums){
        // base case
        if(target < 0 || index >= nums.size()) return false;
        if(target == 0) return true;

        if(dp[index][target] != -1) return dp[index][target];

        int include = solve(index + 1, target-nums[index], dp, nums);
        int exclude = solve(index +1, target, dp, nums);

        return dp[index][target] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i : nums) sum += i;
        if(sum % 2 == 1) return false;
        int target = sum/2;

        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return solve(0, target, dp, nums);
    }
};