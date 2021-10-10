class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int length1=nums1.size();
        int length2=nums2.size();
        int point1=0, point2=0;
        while(point1<length1 && point2<length2)
        {
            if(nums1[point1]==nums2[point2])
            {
                res.push_back(nums1[point1]);
                point1++;
                point2++;
            }
            else if(nums1[point1]>nums2[point2])
            {
                point2++;
            }
            else if(nums1[point1]<nums2[point2])
            {
                point1++;
            }
        }
        return res;
    }
};