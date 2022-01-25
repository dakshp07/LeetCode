class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)
        {
            return false;
        }
        int curr=0;
        while(curr<arr.size()-1 && arr[curr]<arr[curr+1])
        {
            curr++;
        }
        if(curr==0 || curr==arr.size()-1)
        {
            return false;
        }
        while(curr<arr.size()-1 && arr[curr]>arr[curr+1])
        {
            curr++;
        }
        if(curr==arr.size()-1)
        {
            return true;
        }
        return false;
    }
};