class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        // normal 3 pointer approach
        int mod=1e9+7;
        long res=0;
        for(int i=0; i<arr.size(); i++)
        {
            // freq store karo
            vector<int> freq(101, 0);
            for(int j=i+1; j<arr.size(); j++)
            {
                int k=target-arr[i]-arr[j];
                if(k>=0 && k<=100 && freq[k]>0)
                {
                    res+=freq[k];
                    res%=mod;
                }
                freq[arr[j]]++;
            }
        }
        return (int)res;
    }
};