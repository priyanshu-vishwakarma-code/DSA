class Solution {
public:
    set<vector<int>>s;
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>finalans;
        vector<int>ans;

        Csum(arr,ans,finalans,0,target);
        return finalans;
    }

    void Csum(vector<int>&arr , vector<int>&ans, vector<vector<int>>&finalans , int i , int tar){
        //base case
        if(i==arr.size() || tar<0) return;
        if(tar==0){
            if(!s.count(ans)){
            finalans.push_back(ans);
            s.insert(ans);
            }
            return;
        }

        //choice 1 (include 1 time)
        ans.push_back(arr[i]);
        Csum(arr,ans,finalans,i+1,tar-arr[i]);

        //choice 2 (incluce mulitple times)
        Csum(arr,ans,finalans,i,tar-arr[i]);

        //choice 3 (exclude current and include next)
        ans.pop_back();
        Csum(arr,ans,finalans,i+1,tar);
    }
};