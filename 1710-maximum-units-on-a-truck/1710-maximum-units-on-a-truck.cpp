class Solution {
public:
    static bool cmpr(vector<int> a, vector<int> b)
    {
        return a[1]>b[1]; // we will keep the box with max no of units in front
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // we need to maximize the no of units in truck
        // lets pick greedily and pick them accordingly
        sort(boxTypes.begin(), boxTypes.end(), cmpr);
        int res=0;
        for(int i=0; i<boxTypes.size(); i++)
        {
            // we try to pick minimum boxes that has max units in it so that we can maximize our output
            int pickBox=min(boxTypes[i][0], truckSize);
            // we picked up, lets reduce our truck size
            truckSize-=pickBox;
            // add our box to ans
            res+=pickBox*boxTypes[i][1];
            // if we reach zero in truck size we break
            if(truckSize==0) break;
        }
        return res;
    }
};