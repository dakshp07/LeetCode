class Solution {
public:
    bool possibleTime(int mid, vector<int>& piles, int h)
    {
        // curr time var will keep track of the banas we ate till now
        long long curr_time=0;
        for(int i=0; i<piles.size(); i++)
        {
            // piles[i] banans will be eaten in ceil(piles[i]/mid) hrs, where mid is speed
            // we take ceil after seeing example 1
            // [3,6,7,11] and ans is 4
            // so [ceil(3/4),ceil(6/4),ceil(7/4),ceil(11/4)] == [1,2,2,2]
            // so sum is 1+2+2+2=7 which is <h
            curr_time+=ceil((double)piles[i]/mid);
        }
        // we return true if curr_time<=h
        if(curr_time<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // so we apply binary search on a search space which could potentially contain ans
        // the ans can be from 1 to max(piles)
        // the worst case would be if koko eats just 1 banana in hour
        // the best case is when she finishes all banans in piles.size() hours ie eating at a speed of max(piles)
        // so our ans is b/w [1,max(piles)]
        // a checker function keeps track of the hours for any speed 
        int left=1;
        int right=*max_element(piles.begin(), piles.end());
        int ans=right;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(possibleTime(mid, piles, h))
            {
                ans=mid;
                // we look for more small values on left
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