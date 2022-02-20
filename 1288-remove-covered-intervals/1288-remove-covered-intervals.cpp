class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int x=intervals[0][0], y=intervals[0][1]; // initial intervals
        int res=1; // first interval ko consider karlo
        for(int i=1; i<intervals.size(); i++)
        {
            // agar overlap hoga toh ith interval ka 0th item kum hoga
            // or 1th item bhi kum hoga
            // upar waali condition hogi tabhi overlap marenge
            if(x<intervals[i][0] && y<intervals[i][1])
            {
                res++;
            }
            // agar upar waali condition satisfy nhi huyi toh update x, y
            // update isliye karna hoga kyuki sort kiya hain 
            // toh aage waale item bade interval honge
            if(intervals[i][1]>y)
            {
                x=intervals[i][0], y=intervals[i][1];
            }
        }
        return res;
    }
};