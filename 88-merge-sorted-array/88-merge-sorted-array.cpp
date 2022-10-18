class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // we do a 2 pointer approach here
        // and check both the vector ele and add them to nums[1] acc
        int curr=m+n-1; // points to current ele
        m--, n--; // we start from behind, so making them in 0 based indexing
        while(m>=0 && n>=0)
        {
            if(nums1[m]>nums2[n])
            {
                // agar nums1 bada hua matlab mujhe peeche daalna usko
                nums1[curr]=nums1[m];
                // we keep on looking on m
                m--;
                curr--;
            }
            else
            {
                nums1[curr]=nums2[n];
                n--;
                curr--;
            }
        }
        // aisa ho sakta ki n waali array ie nums2 main element baaki rahenge kyuki agar woh badi huyi toh
        // nums1 main kabhi bhi ele nhi bachenge kyuki woh already m+n size hain
        while(n>=0) // jitne baaki sab peeche jaayenge
        {
            nums1[curr]=nums2[n]; // daaldo curr pe
            n--; // n ko bhi aage karo
            curr--; // curr ko aage karo
        }
    }
};