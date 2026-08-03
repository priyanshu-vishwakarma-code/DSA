class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // TABULATION METHOD (BOTTOM UP)
        // vector<int>dp(amount+1, amount+1);
        // dp[0] = 0;

        // for(int i = 1 ; i<= amount ; i++){
        //     for(int coin : coins){
        //         if(i-coin >= 0){
        //             dp[i] = min(dp[i], 1 + (dp[i-coin]));
        //         }
        //     }
        // }

        // return dp[amount]==amount+1? -1 : dp[amount];

        // RECURSION + MEMORIZATION
        vector<int>dp(amount+1, -1);
        int ans = recursion(amount, dp, coins);
        return ans==INT_MAX? -1 : ans;
    }

    int recursion(int amountleft, vector<int>&dp, vector<int>&coins){
        if(amountleft == 0) return 0;
        else if(amountleft < 0) return INT_MAX;
        
        if(dp[amountleft] != -1) return dp[amountleft];

        int mincoin = INT_MAX;
        for(int coin : coins){
            int temp = recursion(amountleft - coin, dp, coins);
            if(temp != INT_MAX){
                mincoin = min(temp+1, mincoin);
            }
        }

        return dp[amountleft] = mincoin;
    }
};