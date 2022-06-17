class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 2 ptrs laga sakte
        // ek ptr hoga nums1 pe or ek nums2 pe
        int curr=m+n-1; // ye current pe point karega, joh peeche se hoga chalu
        // peeche se chalu
        m--, n--;
        while(m>=0 && n>=0)
        {
            // agar nums1 bada hua matlab mujhe peeche daalna usko
            if(nums1[m]>nums2[n])
            {
                nums1[curr]=nums1[m]; // peeche daalna matlab curr pr daalna
                curr--; // curr ko aage karo
                m--; // m ko bhi
            }
            // agar nums2 bada hua toh woh peeche aayega ie ab nums2 curr pe jaayega
            else
            {
                nums1[curr]=nums2[n]; // daaldo curr pe
                curr--; // curr ko aage karo
                n--; // n ko bhi aage karo
            }
        }
        // aisa ho sakta ki n waali array ie nums2 main element baaki rahenge kyuki agar woh badi huyi toh
        // nums1 main kabhi bhi ele nhi bachenge kyuki woh already m+n size hain
        while(n>=0) // jitne baaki sab peeche jaayenge
        {
            nums1[curr]=nums2[n]; // daaldo curr pe
            curr--; // curr ko aage karo
            n--; // n ko bhi aage karo
        }
    }
};