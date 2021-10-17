class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i=0;
        int res=0;
        for(int j=0; j<houses.size(); j++)
        {
            while(i<heaters.size()-1 && abs(heaters[i+1]-houses[j])<=abs(heaters[i]-houses[j]))
            {
                i++;
            }
            res=max(res, abs(heaters[i]-houses[j]));
        }
        return res;
    }
};