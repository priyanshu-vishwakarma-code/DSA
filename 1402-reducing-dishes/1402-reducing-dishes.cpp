class Solution {
public:
    int recursion(int curr, int time, vector<vector<int>>&dp, vector<int>&arr){
        if(curr >= arr.size()) return 0;

        if(dp[curr][time] != -1) return dp[curr][time];

        int include = (arr[curr] * time) + recursion(curr+1, time+1, dp, arr);
        int exclude = recursion(curr+1, time, dp, arr);

        return dp[curr][time] = max(include, exclude);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        // RECURSION + MEMORIZATION
        // int n = satisfaction.size();
        // sort(satisfaction.begin(), satisfaction.end());
        // vector<vector<int>>dp(n, vector<int>(n+1, -1));
        // return recursion(0, 1, dp, satisfaction);    

        // TABULATION
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>dp(n+1, vector<int>(n+2, 0));
        for(int curr = n-1 ; curr >= 0 ; curr--){
            for(int time = 1 ; time<=n ; time++){
                int include = (satisfaction[curr] * time) + dp[curr+1][time+1];
                int exclude = dp[curr+1][time];
                dp[curr][time] = max(include, exclude);
            }
        }

        return dp[0][1];
    }


};