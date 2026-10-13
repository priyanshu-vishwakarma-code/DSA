class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int>s;

        //calculating previous smaller elements
        vector<int>left(n);
        for(int i = 0 ; i<n ; i++){
            while((!s.empty()) && heights[s.top()]>=heights[i]) s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        //calculating next smaller elements
        vector<int>right(n);
        while(!s.empty()) s.pop();
        for(int i = n-1 ; i>=0 ; i--){
            while((!s.empty()) && heights[s.top()]>=heights[i]) s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        

        int area = -1;
        for(int i = 0 ; i<n ; i++){
            int width = right[i] - left[i] -1;
            int currarea = heights[i] * width;
            area = max(area,currarea);
        }

        return area;
    }
};