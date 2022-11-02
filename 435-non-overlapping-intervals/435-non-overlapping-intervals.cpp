class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1]; // sort on end time basis
        // so we sort on ascending basis of end
        // [1,2],[2,3],.....
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort the intervals on basis of end time and we start traversing
        // and cnt will intially be equal to 0
        // as we find overlapping intervals we increment the cnt
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt=0; 
        vector<int> prev=intervals[0];
        for(int i=1; i<intervals.size(); i++)
        {
            // now we dont need to check end time
            // as we sorted on that basis
            // we check start time, if any interval start time is <prev end time
            // means they overlap
            if(prev[1]>intervals[i][0])
            {
                cnt++;
            }
            // if they dont overlap then we update our prev
            else
            {
                prev=intervals[i];
            }
        }
        return cnt;
    }
};
