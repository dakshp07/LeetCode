class Solution {
public:
    bool possibleTrips(long long mid, vector<int>& time, int totalTrips)
    {
        // so we create a var to see possible trips
        long long possible_trips=0;
        for(long long i=0; i<time.size(); i++)
        {
            // so i came to the below formula after seeing test case 1 explaination
            // if t=3, the final array looks like [3,1,1]
            // which is essentially the time array but divided by 3 and taken floor
            // [floor(1/3),floor(2/3),floor(3/3)] which becomes [3,1,1]
            
            // so total possible trips is sum of all these ele
            possible_trips+=floor(mid/(long long)time[i]);
        }
        // if possible trips is greater than or equal to our given trips we return true
        if(possible_trips>=totalTrips) return true;
        // else we return false
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // so we can do one thing we can identify the min time and max time
        // in which our ans lies ie our ans lies in range of [min,max]
        // so the min is 1
        // max of the binary search space, 10 ^ 7 * 10 ^ 7, which corresponds to the worst case that only 1 bus is available and it need to finish 10 ^ 7 trips.
        // and peform a bs on the range and a checker func will return true/false acc
        long long left=1;
        long long right=1e14;
        long long ans=1e14; // as thats the max value
        while(left<=right)
        {
            long long mid=(left+right)/2;
            // if its possible to complete given no of trips with mid time
            if(possibleTrips(mid, time, totalTrips))
            {
                // we update ans
                ans=mid;
                // and since we need minimum we look on left side
                right=mid-1;
            }
            // if its not possible
            else
            {
                // we look for ans on right side
                left=mid+1;
            }
        }
        return ans;
    }
};