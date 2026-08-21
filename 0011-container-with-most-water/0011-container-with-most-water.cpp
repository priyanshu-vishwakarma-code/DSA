class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0 , right = height.size()-1 , maxwater = 0;


        while(left<right){
            int water = (right-left) * (min(height[left],height[right]));
            maxwater = max(water,maxwater);

            if(height[left]<height[right]) left++;
            else right--;
        }

        return maxwater;
    }
};