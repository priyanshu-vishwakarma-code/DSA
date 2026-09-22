class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>finalans;

        subsets(nums,ans,finalans,0);
        return finalans;
    }

    void subsets(vector<int>&nums,vector<int>&ans,vector<vector<int>>&finalans,int i){
        if(i==nums.size()){
        finalans.push_back(ans);
        return;
        }

        //include
        ans.push_back(nums[i]);
        subsets(nums,ans,finalans,i+1);

        //exclude
        ans.pop_back();
        subsets(nums,ans,finalans,i+1);
    }
};