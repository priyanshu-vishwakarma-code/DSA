class Solution {
public:
    double myPow(double x, int exp) {
        //handling negatives
        long long n = exp;
        if(n<0) n = -n, x = 1/x;

        //binary exponentiation
        double ans = 1;
        while(n>0){
            if(n%2==1) ans*= x;
            x*=x , n/=2;
        }
        return ans;
    }
};