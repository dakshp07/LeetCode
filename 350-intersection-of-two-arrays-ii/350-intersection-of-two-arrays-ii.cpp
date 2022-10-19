class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // we can use two map or two vec to keep track of freq
        vector<int> freq_1(1001, 0);
        vector<int> freq_2(1001, 0);
        for(int i=0; i<nums1.size(); i++)
        {
            freq_1[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++)
        {
            freq_2[nums2[i]]++;
        }
        vector<int> ans;
        for(int i=0; i<1001; i++)
        {
            if(freq_1[i]>0 && freq_2[i]>0)
            {
                int n=min(freq_1[i], freq_2[i]);
                while(n!=0)
                {
                    ans.push_back(i);
                    n--;
                }
            }
        }
        return ans;
    }
};