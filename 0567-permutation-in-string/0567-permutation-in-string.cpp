class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int>freq1(26,0);
        for(int i = 0 ; i<s1.length() ; i++) freq1[s1[i]-'a']++;

        int i = 0 , j = s1.length()-1;
        while(j<s2.length()){

            vector<int>freq2(26,0);
            for(int a = i ; a <= j ; a++) freq2[s2[a]-'a']++;
            if(freq1==freq2) return true;
            i++ , j++;
        }
        return false;
    }
};