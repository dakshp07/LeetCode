class Solution {
public:
    // sort karte acc to vec[1]
    bool static cmpr(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort acc to cmpr
        sort(boxTypes.begin(), boxTypes.end(), cmpr);
        int ans=0;
        for(int i=0; i<boxTypes.size(); i++)
        {
            // choose min of boxType and truckSize
            int box=min(boxTypes[i][0], truckSize);
            ans+=(box*boxTypes[i][1]);
            truckSize-=box;
            if(truckSize==0)
            {
                break;
            }
        }
        return ans;
    }
};