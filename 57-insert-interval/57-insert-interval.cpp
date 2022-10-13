class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // there could be three cases in total
        // 1. the new interval is entirely before any intervals[i]
        // 2. the new interval is entirely after any intervals[i]
        // 3. it overlaps any other interval
        vector<vector<int>> res;
        for(int i=0; i<intervals.size(); i++)
        {
            // means the new interval is before this
            if(intervals[i][0]>newInterval[1])
            {
                // we push the ans
                res.push_back(newInterval);
                // and update the newInterval to intervals[i]
                newInterval=intervals[i];
            }
            // means the new interval is after this
            else if(intervals[i][1]<newInterval[0])
            {
                // in this case we first push the intervals[i] to ans
                res.push_back(intervals[i]);
                // and after all calculations at end we will push newInterval
            }
            // means the new intervals lies in b/w this
            else
            {
                // so we modify the end, start
                newInterval[0]=min(intervals[i][0], newInterval[0]);
                newInterval[1]=max(intervals[i][1], newInterval[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};