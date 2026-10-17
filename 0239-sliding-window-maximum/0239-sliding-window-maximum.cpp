class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>q;

        //first window
        for(int i = 0 ; i<k ; i++){
            while(q.size()>0 && nums[q.back()]<=nums[i]) q.pop_back();
            q.push_back(i);
        }

        //rest of the windows
        for(int i = k ; i<n ; i++){
            ans.push_back(nums[q.front()]);  //pushing back answer in the front

            while(q.size()>0 && q.front() <= i-k) q.pop_front(); //poping elements out of the window

            while(q.size()>0 && nums[q.back()]<=nums[i]) q.pop_back();  //poping smaller elements

            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);

        return ans;
    }
};