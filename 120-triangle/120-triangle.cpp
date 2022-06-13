class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // upar se neeche jana hain aapne ko
        // iska matlab lagegi dp
        // we have to options either pick ith or pick i+1
        for(int lvl=1; lvl<triangle.size(); lvl++) // 1 se isliye kyuki 0 toh lena padega
        {
            for(int i=0; i<=lvl; i++)
            {
                // ab for a specific level
                // we can either take ith or i+1
                triangle[lvl][i]+=min(triangle[lvl-1][min(i, (int)size(triangle[lvl - 1]) - 1)], triangle[lvl - 1][max(i - 1, 0)]);
            }
        }
        // now return min from back
        return *min_element(begin(triangle.back()), end(triangle.back()));
    }
};