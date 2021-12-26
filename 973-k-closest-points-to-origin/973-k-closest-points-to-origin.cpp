class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<double, vector<vector<int>>> umap;
        vector<vector<int>> ans;
        for(int i=0; i<points.size(); i++)
        {
            umap[(double)sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1])].push_back(points[i]);
        }
        for(auto x: umap)
        {
            for(auto y: x.second)
            {
                ans.push_back(y);
                k--;
                if(k==0)
                {
                    return ans;
                }
            }
        }
        return {};
    }
};