class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        if(p.size()<=2)
            return p.size();

        // p[i][0] & p[j][0] is x-points
        // p[i][1] & p[j][1] is y-points
        int maxi=0;
        for(int i=0; i<p.size()-1; i++)
        {
            map<double,int> mp;
            for(int j=i+1; j<p.size(); j++)
            {
                double s=0;//slope
                if((p[j][0]-p[i][0])==0)
                {
                    s=INT_MAX;//if p[i][0] - p[j][0] is 0 then slope will become infinite, So handle this case separately.
                }
                else
                {
                    s=double(p[j][1]-p[i][1])/double(p[j][0]-p[i][0]);
                }
                mp[s]++;

                //After storing the count of each slope value in the map then simultaneously find the maximum value from the map.

                //1-In every itreration slope-value will be stored in the map.
                //2-Whenever we store slope-values in the map, we increase the count value for that particular slope.
                //Simulatneously find the max count value from the map on every iteration & store them in 'maxi'.
                maxi=max(mp[s], maxi);
            }
        }

        //Here we're incrementing maxi bcoz we'll include the current point as well
        return maxi+1;
    }
};
