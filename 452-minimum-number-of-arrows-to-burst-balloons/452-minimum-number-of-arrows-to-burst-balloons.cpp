class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
        {
            return 0;
        }
        sort(points.begin(), points.end(), [](auto &v1,auto &v2){
            return v1[1]<v2[1];});
        int end=points[0][1], arrow=1;
        for(int i=1; i<points.size(); i++)
        {
            if(points[i][0]>end)
            {
                arrow++;
                end=points[i][1];
            }
        }
        return arrow;
    }
};