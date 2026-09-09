class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0 , end = nums.size()-1;
        while(start<=end){
            int mid = start + ((end-start)/2);

            if(mid==0 || mid==nums.size()-1) return nums[mid];

            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            else if(nums[mid-1]==nums[mid] && mid%2==1) start = mid + 1;
            else if(nums[mid-1]==nums[mid] && mid%2==0) end = mid - 1;
            else if(nums[mid+1]==nums[mid] && mid%2==1) end = mid - 1;
            else if(nums[mid+1]==nums[mid] && mid%2==0) start = mid + 1;
        }
        return -1;
    }
};