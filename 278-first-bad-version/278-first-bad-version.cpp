// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // FFFFFFTTTTFFF
        // so we essentially need to first look for the first T
        // we can use binary search to look for that
        int left=1;
        int right=n;
        int ans=0;
        while(left<=right)
        {
            long long mid=((long long)left+(long long)right)/2;
            if(isBadVersion(mid))
            {
                ans=mid;
                right=mid-1; // as we keep decreasing the search space since we need first T
            }
            else 
            {
                left=mid+1;
            }
        }
        return ans;
    }
};