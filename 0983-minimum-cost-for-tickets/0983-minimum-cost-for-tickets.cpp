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
        vector<int>dp(days.size(), -1);
        return recursion(0, dp, days, costs);
    }
};