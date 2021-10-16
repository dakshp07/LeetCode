class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> umap;
        vector<int> res;
        for(int i=0; i<intervals.size(); i++)
        {
            umap[intervals[i][0]]=i;
        }
        for(int i=0; i<intervals.size(); i++)
        {
            auto it=umap.lower_bound(intervals[i][1]);
            if(it==umap.end())
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(it->second);
            }
        }
        return res;
    }
};