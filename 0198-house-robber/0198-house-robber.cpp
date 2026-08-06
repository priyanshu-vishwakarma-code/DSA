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
        // return recursion(0, dp, nums);     // the recursive + memoriztaion method

        // THE TABULATION METHOD
        // if(n==1) return nums[0];
        // else if(n==2) return max(nums[0],nums[1]);
        // dp[0] = nums[0], dp[1] = max(nums[0],nums[1]);
        // for(int i = 2 ; i<n ; i++){
        //     int rob = dp[i-2] + nums[i];
        //     int skip = dp[i-1];
        //     if(rob > skip) dp[i] = rob;
        //     else dp[i] = skip;
        // }
        // return dp[n-1];

        // TABULATION + SPACE OPTIMIZATION
        if(n==1) return nums[0];
        else if(n==2) return max(nums[0],nums[1]);
        int x = nums[0], y = max(nums[0],nums[1]);
        for(int i = 2 ; i<n ; i++){
            int rob = x + nums[i], skip = y;
            if(rob > skip){
                x = y;
                y = rob;
            }
            else x = skip, y = skip;
        }
        return y;
    }
};