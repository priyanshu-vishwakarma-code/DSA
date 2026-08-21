class Solution {
public:
    int minimum(int &a, int &b, int &c){
        if(a<=b && a<=c) return a;
        if(b<=a && b<=c) return b;
        if(c<=a && c<=b) return c;
        return -1;
    }

    int recursion(int i, vector<int>&dp, vector<int>&days, vector<int>&costs){
        if(i >= days.size()) return 0;

        if(dp[i] != -1) return dp[i];

        // choice 1 (1 day pass)
        int next = i+1;
        int pass1 = costs[0] + recursion(next, dp, days, costs);

        // choice 2 (7 days pass)
        next = i;
        while(next<days.size() && days[next]<days[i]+7) next++;
        int pass2 = costs[1] + recursion(next, dp, days, costs);

        // choice 3 (30 days pass)
        next = i;
        while(next<days.size() && days[next]<days[i]+30) next++;
        int pass3 = costs[2] + recursion(next, dp, days, costs);

        return dp[i] = minimum(pass1, pass2, pass3);
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // RECURSION + MEMORIZATION
        // vector<int>dp(days.size(), -1);
        // return recursion(0, dp, days, costs);

        // TABULATION
        int n = days.size();
        vector<int>dp(n+1, 0);
        for(int i = 1 ; i<=n ; i++){
            int pass1, pass2, pass3;

            pass1 = costs[0] + dp[i-1];

            int j = i - 1;
            while (j >= 0 && days[j] >= days[i - 1] - 6) j--;
            pass2 = costs[1] + dp[j + 1];

            j = i - 1;
            while (j >= 0 && days[j] >= days[i - 1] - 29) j--;
            pass3 = costs[2] + dp[j + 1];

            dp[i] = minimum(pass1, pass2, pass3);
        }
        return dp[n];
    }
};