class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char,int>m;
        queue<int>q;

        for(int i = 0 ; i < n ; i++){
            if(m.count(s[i])) m[s[i]]++;
            else{
                q.push(i);
                m[s[i]] = 1;
            }

            while(q.size()>0 && m[s[q.front()]]>1) q.pop();
        }
            
        if(!q.empty()) return q.front();
        return -1;
    }
};