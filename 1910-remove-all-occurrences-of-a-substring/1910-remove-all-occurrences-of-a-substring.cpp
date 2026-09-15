class Solution {
public:
    string removeOccurrences(string s, string p) {
        int i = 0;
        while(i<s.length()){
            if(s[i]==p[0]){
                int j = i , k = 0 , idx = i;
                while(j<s.length() && k<p.length() && s[j]==p[k]){
                    if(k==p.length()-1){
                        s.erase(s.begin()+idx,s.begin()+j+1);
                        i=-1;
                        break;
                    }
                    j++,k++;
                }
            }

            i++;
        }

        return s;
    }
};