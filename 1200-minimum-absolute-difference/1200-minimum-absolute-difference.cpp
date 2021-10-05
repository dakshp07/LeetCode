class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int length=arr.size();
        vector<vector<int>> res;
        int min_diff=INT_MAX;
        for(int i=1; i<length; i++)
        {
            min_diff=min(arr[i]-arr[i-1], min_diff);
        }
        for(int i=1; i<length; i++)
        {
            if(arr[i]-arr[i-1]==min_diff)
            {
                vector<int> pairs;
                pairs.push_back(arr[i-1]);
                pairs.push_back(arr[i]);
                res.push_back(pairs);
            }
        }
        return res;
    }
};