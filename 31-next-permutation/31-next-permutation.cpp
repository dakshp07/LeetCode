class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        // algo:
        // 1) traverse from behind, find the i where arr[i]<arr[i+1] store in ind1
        // 2) again traverse from behind, find the i where arr[i]>arr[ind1] store in ind2
        // 3) swap(arr[ind1], arr[ind2])
        // 4) reverse(ind1+1, arr.end())
        // return the arr
        // intution: if you see from behind, every next permuation increases for a while till it reaches max and then goes down. so we are trying to find the breakout points where we reach the max and then fall out from the max
        int ind1=-1; // initialise as -1 to cover the case wheret the arr is decreasing
        for(int i=arr.size()-2; i>=0; i--)
        {
            if(arr[i]<arr[i+1])
            {
                ind1=i;
                break;
            }
        }
        if(ind1>=0) // if no such index there
        {
            int ind2=-1;
            for(int i=arr.size()-1; i>=0; i--)
            {
                if(arr[i]>arr[ind1])
                {
                    ind2=i;
                    break;
                }
            }
            swap(arr[ind1], arr[ind2]);
        }
        reverse(arr.begin()+ind1+1, arr.end());
    }
};