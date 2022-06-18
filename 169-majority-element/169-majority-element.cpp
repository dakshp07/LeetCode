class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // multiple ways:
        // pick one element and check if it occurs n/2 times, n^2
        // sort (violates) nlogn
        // use freq array or map, space complexity
        // moore voting algo lagao
        // traverse the arr, keep cnt and ele
        // if cnt==0 update ele with curr ele
        // else if ele==arr[i] -> cnt++ or else cnt--;
        // return ele
        int ele=0, cnt=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(cnt==0) ele=nums[i];
            if(ele==nums[i]) cnt++;
            else cnt--;
        }
        return ele;
    }
};