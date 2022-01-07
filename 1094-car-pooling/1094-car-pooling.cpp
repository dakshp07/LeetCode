class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int curr=0;
        vector<pair<int, int>> arr;
        for(int i=0; i<trips.size(); i++)
        {
            arr.push_back(make_pair(trips[i][1], trips[i][0]));
            arr.push_back(make_pair(trips[i][2], -trips[i][0]));
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++)
        {
            curr+=arr[i].second;
            if(curr>capacity)
            {
                return false;
            }
        }
        return true;
    }
};