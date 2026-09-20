class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int>prefix;
        int sum = 0;
        for(int i = 0 ; i<n ; i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }

        unordered_map<int,int>m;
        int count = 0;
        for(int i = 0 ; i<n ; i++){
            if(prefix[i]==k) count++;
            int tar = prefix[i]-k;
            if(m.count(tar)) count+=m[tar];
            if(!m.count(prefix[i])) m[prefix[i]] = 0;
            m[prefix[i]]++;
        }

        return count;
    }
};