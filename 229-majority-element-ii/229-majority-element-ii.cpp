class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // multiple ways:
        // check for every ele, n^2
        // sort karlo, nlogn
        // use map or freq array, space complexity
        // boyer moore lagega but todha obs ke saath
        // at max there could be two elemts coming more than n/3 times
        // toh normal boyer moore lagao or ye 2 ele pe check karte jaao
        int nums1=-1, nums2=-1;
        int c1=0, c2=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==nums1) c1++;
            else if(nums[i]==nums2) c2++;
            else if(c1==0) c1=1, nums1=nums[i];
            else if(c2==0) c2=1, nums2=nums[i];
            else c1--, c2--;
        }
        vector<int> ans; // since we have to return an arr and we have our two possibility in nums1, nums2
        c1=0, c2=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==nums1) c1++; // check count of each
            else if(nums[i]==nums2) c2++;
        }
        if(c1>nums.size()/3) // if > size/3 add it
        {
            ans.push_back(nums1);
        }
        if(c2>nums.size()/3)
        {
            ans.push_back(nums2);
        }
        return ans;
    }
};