class Solution {
public:
    bool isHappy(int n) {
        int sum=0;
        // we repeat till n becomes 0
        while(n!=0)
        {
            // sum of all digits
            sum+=pow(n%10, 2);
            // to get next digits
            n/=10;
        }
        // if sum<5 and its not equal to 1 then we cannot break it such that sum of digits is 1 (obs)
        if(sum<5 && sum!=1) return false;
        // if sum==1 we return true
        if(sum==1) return true;
        return isHappy(sum); // we continue doing this for all the other sums too
    }
};