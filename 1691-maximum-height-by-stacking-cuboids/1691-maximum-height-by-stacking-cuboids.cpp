class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // sort each array
        for(vector<int>&a : cuboids){
            sort(a.begin(), a.end());
        }

        // sort the whole 2d array
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<int>dp(n);
        for(int i = 0 ; i<n ; i++){
            dp[i] = cuboids[i][2];
            for(int j = 0 ; j<i ; j++){
                if(cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]){
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }

        int ans = -1;
        for(int i : dp){
            ans = max(ans, i);
        }
        return ans;
    }
};