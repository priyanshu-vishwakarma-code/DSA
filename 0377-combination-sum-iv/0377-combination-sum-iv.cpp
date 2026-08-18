class Solution {
public:
    int recursion(int curr, vector<int>&dp, vector<int>&nums){
        if(curr < 0) return 0;
        if(curr == 0) return 1;

        if(dp[curr] != -1) return dp[curr];

        int ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            ans += recursion(curr - nums[i], dp, nums);
        }

        return dp[curr] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        // RECURSION + MEMORIZATION
        // vector<int>dp(target+1, -1);
        // return recursion(target, dp, nums);

        // TABULATION METHOD
        vector<unsigned int>dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1 ; i<=target ; i++){
            for(int j = 0 ; j<nums.size() ; j++){
                if(i - nums[j] < 0) continue;
                dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};