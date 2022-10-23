// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // binary search lagake we will check the first occurence of T
        // FFFFFFTTTTT we will look out for first T
        int low=1;
        int high=n;
        while(low<=high)
        {
            long long mid=((long long)low+(long long)high)/2;
            if(isBadVersion(mid))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};