class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>finalans;
        vector<int>ans;

        sort(nums.begin(),nums.end());
        subset(nums,finalans,ans,0);
        return finalans;
    }

    void subset(vector<int>&nums, vector<vector<int>>&finalans , vector<int>&ans, int i){
        if(i==nums.size()){
            finalans.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        subset(nums,finalans,ans,i+1);

        ans.pop_back();
        int idx = i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        subset(nums,finalans,ans,idx);
    }
};