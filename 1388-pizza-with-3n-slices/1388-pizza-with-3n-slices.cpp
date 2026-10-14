class Solution {
public:
    int solve(int curr, int end, int n, vector<vector<int>>&dp, vector<int>&slices){
        // base case
        if(n == 0 || curr > end) return 0;

        // dp check
        if(dp[curr][n] != -1) return dp[curr][n];

        // case 1 (take)
        int take = slices[curr] + solve(curr+2, end, n-1, dp, slices);

        // case 2 (skip)
        int skip = solve(curr+1, end, n, dp, slices);

        return dp[curr][n] = max(take, skip);
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int n = k/3;

        vector<vector<int>>dp1(k, vector<int>(n+1,-1));
        vector<vector<int>>dp2(k, vector<int>(n+1,-1));

        int takefirst = solve(0, k-2, n, dp1, slices);
        int takesecond = solve(1, k-1, n, dp2, slices);

        return max(takefirst, takesecond);
    }
};