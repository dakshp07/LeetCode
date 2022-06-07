class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 2 ptr se ez
        // current pos ka track ke liye curr
        int curr=m+n-1;
        // last main point kar rahe 2 ptr
        m--;
        n--;
        // 2 ptr lagao
        while(m>=0 && n>=0)
        {
            // agar nums1 > nums2
            if(nums1[m]>nums2[n])
            {
                // usko curr pe daalo
                // curr-- karo and m--
                nums1[curr]=nums1[m];
                curr--;
                m--;
            }
            // baaki cases
            else
            {
                // curr pe daalo 
                // curr-- and n--
                nums1[curr]=nums2[n];
                curr--;
                n--;
            }
        }
        // maan lo n wali arr badi hain and kuch ele rhe gaye usmain
        // note: first waali array choti nhi hogi kyuki woh already m+n size ki hain
        while(n>=0)
        {
            // woh sab curr pe jaayenge
            // curr-- and n--;
            nums1[curr]=nums2[n];
            curr--;
            n--;
        }
    }
};