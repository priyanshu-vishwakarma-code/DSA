class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i = 0 ; i<nums.size() ; i++){
            int val = target-nums[i];
            if(m.count(val)) return {i,m[val]};
            m[nums[i]] = i;
        }
        return {-1,-1};
    }
};