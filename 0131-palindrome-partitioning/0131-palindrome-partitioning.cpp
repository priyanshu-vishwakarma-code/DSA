class Solution {
public:
    void solve(string s, vector<string>&ans , vector<vector<string>>&finalans){
        if(s.length()==0){
            finalans.push_back(ans);
            return;
        }

        for(int i = 0 ; i<s.length() ; i++){
            string part = s.substr(0,i+1);
            if(ispalin(part)){
                ans.push_back(part);
                solve(s.substr(i+1),ans,finalans);
                ans.pop_back();
            }
        }
    }

    bool ispalin(string &part){
        int i = 0 , j = part.length()-1;
        while(i<j){
            if(part[i++]!=part[j--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        vector<vector<string>>finalans;
        solve(s,ans,finalans);
        return finalans;
    }
};