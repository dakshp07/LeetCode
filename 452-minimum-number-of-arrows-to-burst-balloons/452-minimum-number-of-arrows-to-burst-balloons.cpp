class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int shot = 1;
        int min = points[0][0];
        int max = points[0][1];
    
        for(int i = 1; i <points.size(); i++)
        {
            if(points[i][0] <= max)
            {
                if(points[i][1] <= max)
                {
                    max = points[i][1];
                }
            }
            else
            {
                shot++;
                max = points[i][1];
            }
        }  
        return shot;
    }
};