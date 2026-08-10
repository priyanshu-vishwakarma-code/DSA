class Solution {
public:
    int recursion(int i, vector<int>&dp, vector<int>&cost){
        if(i >= cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        //choice 1 (1 step)
        int onestep = cost[i] + recursion(i+1, dp, cost);

        //choice 2 (2 step)
        int twostep = cost[i] + recursion(i+2, dp, cost);

        return dp[i] = min(onestep, twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int ans1, ans2;
        vector<int>dp(cost.size(), -1);
        ans1 = recursion(0, dp, cost);
        ans2 = recursion(1, dp, cost);
        return min(ans1, ans2);
    }
};