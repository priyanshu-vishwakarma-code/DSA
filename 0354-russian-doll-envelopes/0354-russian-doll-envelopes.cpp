class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
        [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int n = envelopes.size();
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i = 1 ; i<n ; i++){
            int height = envelopes[i][1];
            auto it = lower_bound(ans.begin(), ans.end(), height);
            if (it == ans.end()) {
                ans.push_back(height);
            }
            else {
                *it = height;
            }
        }

        return ans.size();
        
    }
};