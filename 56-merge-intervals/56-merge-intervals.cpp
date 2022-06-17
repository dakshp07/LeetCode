class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // we have to check the end with the start of next interval
        sort(intervals.begin(), intervals.end()); // sort to make sure that they are in order
        vector<vector<int>> res; // our last array
        int prev_start=intervals[0][0]; // start
        int prev_end=intervals[0][1]; // end
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0]<=prev_end) // agar next interval ka start is less than or equal to prev ka end
            {
                prev_end=max(prev_end, intervals[i][1]); // toh update with max
            }
            else // agar end bada hain next ke start se matalb we found the overlap, update the prev start and end
            {
                res.push_back({prev_start, prev_end}); // push in res
                prev_start=intervals[i][0]; // update
                prev_end=intervals[i][1];
            }
        }
        res.push_back({prev_start, prev_end}); // whatever is remaining will push that too
        return res;
    }
};