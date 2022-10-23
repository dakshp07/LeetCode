class Solution {
public:
    bool possibleTime(int mid, vector<int>& dist, double hour)
    {
        // mid is our speed
        // time could be in integer, if its double we take ceil
        double time=0;
        // we run till last second ele only
        // because after the last train we dont have to wait since we reached destination
        for(int i=0; i<dist.size()-1; i++)
        {
            // so time=dist/speed
            // but we take ceil in order to keep it in integer
            time+=ceil((double)dist[i]/mid);
        }
        // now we add the last train time
        time+=((double)dist.back())/mid;
        // we return true only if time<=hour
        if(time<=hour) return true;
        return false; // else we return false
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // so one of the ways is to find range of speed
        // min speed could be 1 and max speed could be 1e7 (given in question)
        // we are very sure that our ans will lie in range of [1,1e7]
        // so we peform a bs on this range
        // a check function keeps track of hours
        // and then we return min ans
        if(ceil(hour)<dist.size()) return -1;
        int left=1;
        int right=1e7;
        // res will be intialized as -1 as thats the value we need to return 
        // if its not possible to reach in given time
        int res=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            // if our given mid we were able to reach in hour hours
            if(possibleTime(mid, dist, hour))
            {
                // then we update res
                res=mid;
                // and keep on looking on left for more small values
                right=mid-1;
            }
            // if its not possible to reach in hour hours
            else
            {
                // we look for ans on right search space
                left=mid+1;
            }
        }
        return res;
    }
};