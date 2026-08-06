class Solution {
public:
    int recursion(int curr, vector<int>&dp, vector<int>&nums){
        // base case
        if(curr >= nums.size()){
           return 0;
        }
        
        // if max already calculated for the index
        if(dp[curr] != -1) return dp[curr];

        // not skip
        int ans1 = nums[curr] + recursion(curr+2, dp, nums);

        // skip
        int ans2 = recursion(curr+1, dp, nums);

        // updating the dp array and return the answer
        return dp[curr] = max(ans1, ans2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return recursion(0, dp, nums);
    }
};