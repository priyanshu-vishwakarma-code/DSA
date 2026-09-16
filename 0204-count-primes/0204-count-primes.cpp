class Solution {
public:
    int countPrimes(int n) {
        vector<bool>prime(n,true);
        
        int count = 0 , i = 2;
        while(i<n){
            if(prime[i]==true){
                count++;
                int j = i*2, k = 2;
                while(j<n){
                    prime[j] = false;
                    j += i;
                }

            }
            i++;
        }
        return count;
    }
};