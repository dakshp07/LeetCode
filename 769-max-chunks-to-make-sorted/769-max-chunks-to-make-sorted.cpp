class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_chunks=0;
        int max_val=0;
        for(int i=0; i<arr.size(); i++)
        {
            max_val=max(max_val, arr[i]);
            if(i==max_val)
            {
                max_chunks+=1;
            }
        }
        return max_chunks;
    }
};