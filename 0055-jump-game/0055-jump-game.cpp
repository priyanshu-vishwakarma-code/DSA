class Solution {
public:
    bool recursion(int i, vector<int>&dp, vector<int>&nums){
        if(i == nums.size()-1) return true;
        if(i >= nums.size()) return false;

        if(dp[i] != -1) return dp[i];

        int jump = nums[i];
        while(jump > 0){
            if(recursion(i+jump, dp, nums)) return true;
            jump--;
        }

        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return recursion(0, dp, nums);
    }
};