class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // we sort and check overlapping
        // we say a interval overlaps, if its previous ones ending happens after it starts
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int prev_end=intervals[0][1];
        int prev_start=intervals[0][0];
        for(int i=1; i<intervals.size(); i++)
        {
            // if prev end is greater than or equal to next intervals start
            if(prev_end>=intervals[i][0])
            {
                // means we can merge them up
                // so we update our prev end
                prev_end=max(prev_end, intervals[i][1]);
            }
            // if they overlap
            else
            {
                // then we push our till now merged end, start to res
                res.push_back({prev_start, prev_end});
                // and also update them
                prev_end=intervals[i][1];
                prev_start=intervals[i][0];
            }
        }
        // we push the last merged interval too
        // since the for loop ends we would still have a merged interval left to add
        res.push_back({prev_start, prev_end});
        return res;
    }
};