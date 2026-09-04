class Solution {
public:
    int recursion(int curr, int lane, int &n, vector<vector<int>>&dp, vector<int>&rocks){
        if(curr == n-1) return 0;

        if(dp[curr][lane] != -1) return dp[curr][lane];
        
        // if no rock is in front
        if(rocks[curr+1] != lane) return recursion(curr+1, lane, n, dp, rocks);

        // if rock is in front
        int jump = INT_MAX;
         
        // jump to lane 1
        if(lane != 1 && rocks[curr] != 1) jump = min(jump, recursion(curr+1, 1, n, dp, rocks) + 1);
        // jump to lane 2
        if(lane != 2 && rocks[curr] != 2) jump = min(jump, recursion(curr+1, 2, n, dp, rocks) + 1);
        // jump to lane 3
        if(lane != 3 && rocks[curr] != 3) jump = min(jump, recursion(curr+1, 3, n, dp, rocks) + 1);

        return dp[curr][lane] = jump;
    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>>dp(n, (vector<int>(4,-1)));
        int ans = recursion(0, 2, n, dp, obstacles);  // curr point, curr lane, n, obsticles
        return ans;
    }
};