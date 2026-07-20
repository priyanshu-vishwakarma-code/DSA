class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        else{
            int prev1 = 2, prev2 = 1;
            int ans;
            for(int i = 3 ; i<=n ; i++){
                ans = prev1 + prev2;
                prev2 = prev1;
                prev1 = ans;
            }
            return ans;
        }
    }
};