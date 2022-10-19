class Solution {
public:
    bool shipPossible(int mid, vector<int>& weights, int days)
    {
        // a curr wt variable will check the current wt
        int curr_wt=0;
        int curr_days=0; // it will keep a check on no of days
        for(int i=0; i<weights.size(); i++)
        {
            curr_wt+=weights[i];
            if(curr_wt>mid)
            {
                // that means we can now ship the next weights on next day
                curr_days++;
                // and the curr wt on next day will be the new ship starting wt
                curr_wt=weights[i];
            }
        }
        // now total no of days we need will be curr_days+1 since we started with 0
        // so now if curr_days+1 is <= days then we return true since mid could be a ans
        if(curr_days+1<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // brute force would be to use recursion, backtracking
        // and find all possible PnC for subarrays and then find the minimum of them
        // tc: O(n^2*days) so for any ele i can have n options and i repeat the process for days
        
        // we can use binary search but we do a bs on ans
        // ie we find the min wt and max wt and do a binary search on them
        // we keep a checker function to see if for the mid i can ship them in days time or not
        // now left will be minimum wt to ship all my weights successfully so ie max(weights)
        // now right will be max wt to ship all my weights successfully so ie sum(weights)
        int left=*max_element(weights.begin(), weights.end());
        int right=accumulate(weights.begin(), weights.end(), 0);
        int ans=INT_MAX; // as we need minimum
        while(left<=right)
        {
            int mid=(left+right)/2;
            // now we check if we can ship in days time with a ship of wt mid
            if(shipPossible(mid, weights, days))
            {
                // then we update ans 
                ans=mid;
                // and keep on looking for more small ans on left
                right=mid-1;
            }
            // if im unable to ship wt in days time with a ship of wt mid
            else
            {
                // then i look on right side
                left=mid+1;
            }
        }
        return ans;
    }
};