class Solution {
public:
    int sumofn(int n)
    {
        return (n*(n+1))/2;
    }
    int numPairsDivisibleBy60(vector<int>& time) {
        int pair=0;
        vector<int> arr(60);
        for(int i=0; i<time.size(); i++)
        {
            arr[time[i]%60]++;
        }
        for(int i=1; i<30; i++)
        {
            pair+=arr[i]*arr[60-i];
        }
        pair+=sumofn(arr[0]-1)+sumofn(arr[30]-1);
        return pair;
    }
};