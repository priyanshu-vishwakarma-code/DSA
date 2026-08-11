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
        // RECURSION + MEMORIZATION
        // int ans1, ans2;
        // vector<int>dp(cost.size(), -1);
        // ans1 = recursion(0, dp, cost);
        // ans2 = recursion(1, dp, cost);
        // return min(ans1, ans2);

        // TABULATION
        // int n = cost.size();
        // if(n == 0) return 0;
        // if(n == 1) return cost[0];
        // vector<int>dp(n+1, -1);
        // dp[0] = 0, dp[1] = 0;
        // for(int i = 2 ; i<=n ; i++){
        //     dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        // }
        // return dp[n];

        // TABULATION + SPACE OPTIMIZATION
        int n = cost.size();
        if(n == 0) return 0;
        if(n == 1) return cost[0];
        int prevx = 0, prevy = 0, answer;
        for(int i = 2 ; i<=n ; i++){
            answer = min(prevx + cost[i-2], prevy + cost[i-1]);
            prevx = prevy;
            prevy = answer;
        }
        return answer;
    }
};