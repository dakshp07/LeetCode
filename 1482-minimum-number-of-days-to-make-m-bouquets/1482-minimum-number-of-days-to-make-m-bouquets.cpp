class Solution {
public:
    bool possibleAns(int mid, vector<int>& bloomDay, int m, int k)
    {
        int bloomed=0;
        int total_bouquet=0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            // so we need to consider one bouquet only if there are k flowers that bloom together
            // if bloomDay[i]<=mid means the flower will be bloomed at this day
            if(bloomDay[i]<=mid)
            {
                // means this floor is bloomed at mid days
                // so this flower is bloomed
                bloomed++;
            }
            // if the flower is not bloomed this means now my cycle of continuous bloomed flowers is break, so bloomed is 0
            else
            {
                bloomed=0;
            }
            // now if no of bloomed flowers >=m we can consider mid as our ans
            if(bloomed==k)
            {
                // we increment our no of bouquet
                total_bouquet++;
                // and reset our windows since we need to see if we can make >m bouquet
                bloomed=0;
            }
        }
        // if we were able to create bouquet>=k we return true
        if(total_bouquet>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // we can use bs to find our ans by finding a possible search space in which our ans would lie
        // so the min ans could be 1 and max ans could be max(bloomDay)
        // since when its 1 we could get just one bouquet or even 0 in worst case
        // and when its max(bloomDay) we can take all flowers and use them as bouquet
        // a check function keeps track whether given mid can be picked
        int left=1;
        int right=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(possibleAns(mid, bloomDay, m, k))
            {
                ans=mid;
                // we look for more min ans
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};