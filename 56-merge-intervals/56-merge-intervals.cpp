class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // so we pick any ith ele from vector and check
        // if they are overlapping
        // if they are then we update the result vector
        sort(intervals.begin(), intervals.end()); // sort to make sure that they are in order
        // for two intervals to overlap
        // intervals[i][1]>=intervals[j][0] && intervals[i][0]<=intervals[j][1] or vice-versa
        // as we sorted the vector intervals[i][0]<=intervals[j][1] is satisfied
        // so we maitain a res vector and check if the new ele start is <= last ele of res end
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=0; i<intervals.size(); i++)
        {
            if(intervals[i][0]<=res.back()[1])
            {
                res.back()[1]=max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};