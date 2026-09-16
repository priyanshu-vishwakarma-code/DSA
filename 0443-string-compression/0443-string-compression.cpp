class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size() , idx = 0;

        for(int i = 0 ; i<n ; i++){
            char c = chars[i];
            int count = 0;

            while(i<n && chars[i]==c) count++ , i++;

            if(count==1) chars[idx++] = c;
            else{
                chars[idx++] = c;
                string s = to_string(count);
                for(char ch : s) chars[idx++] = ch;
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};