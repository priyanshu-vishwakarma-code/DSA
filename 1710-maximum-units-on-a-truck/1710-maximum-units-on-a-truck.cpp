class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<float,int>>pq;
        int n = boxTypes.size();
        for(int i = 0 ; i<n ; i++){
            int itemIndex = i;
            float value = boxTypes[i][1];
            pq.push({value, itemIndex});
        }

        int spaceleft = truckSize, ans = 0;
        while((!pq.empty()) && (spaceleft > 0)){
            int i = pq.top().second;
            int val = boxTypes[i][1] , qty = boxTypes[i][0];
            pq.pop();

            if(qty <= spaceleft){
                ans += (qty * val);
                spaceleft -= qty;
            }else{
                ans += (spaceleft * val);
                spaceleft = 0;
            }
        }

        return ans;
    }
};