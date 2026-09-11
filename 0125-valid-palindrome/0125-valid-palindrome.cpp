class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==1) return true;
        int left = 0 , right = s.length()-1;
        while(left<=right){
            if(!isalphanum(s[left])){
                left++;
                continue;
            }

            if(!isalphanum(s[right])){
                right--;
                continue;
            }
            
            if(tolower(s[left])==tolower(s[right])) left++ , right--;
            else return false;
        }
        return true;
    }

    bool isalphanum(char c){
        if(c>=48 && c<=57) return true;
        if(c>=65 && c<=90) return true;
        if(c>=97 && c<=122) return true;
        return false;
    }
};