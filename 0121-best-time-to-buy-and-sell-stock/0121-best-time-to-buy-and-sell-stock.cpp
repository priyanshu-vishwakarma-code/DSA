class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy , bestsell, maxprofit;
        int n = prices.size();
        bestbuy = prices[0] , maxprofit = 0;

        for(int i = 0 ; i<n ; i++){
            int profit = prices[i]-bestbuy;
            maxprofit = max(maxprofit,profit);

            if(prices[i]<bestbuy) bestbuy = prices[i];     
        }

        return maxprofit;
    }
};