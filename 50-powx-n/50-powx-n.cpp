class Solution {
public:
    double myPow(double x, int n) {
        // try to make some observations of the power function
        // if n is even: x^n
        // n%2==0 -> x*x; n/2
        // if n is odd:
        // n%2==1 -> ans=ans*x; n=n-1;
        // we stop at n==0
        // O(logn)
        double ans=1.0;
        long long nums=n; // to handle big edge cases
        if(nums<0) nums=-1*nums; // agar n<0 hain toh usko positive karna
        while(nums)
        {
            if(nums%2==0)
            {
                x*=x;
                nums/=2;
            }
            else
            {
                ans*=x;
                nums-=1;
            }
        }
        if(n<0) ans=(double)(1.0)/(double)(ans); // x^-n is basically -> 1/x^n;
        return ans;
    }
};