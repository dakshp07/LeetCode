class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // brute force is to just traverse every ele in nums2 for every ele in nums1
        // and enter the next greater ele in an array
        // tc: O(len1*len2) sc: O(1)
        // the other way is to maintain a stack and keep an increasing sequence in it
        map<int, int> mp;
        stack<int> st;
        vector<int> ans;
        for(int i=0; i<nums2.size(); i++)
        {
            while(!st.empty() && st.top()<nums2[i])
            {
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i=0; i<nums1.size(); i++)
        {
            if(mp[nums1[i]]==0) ans.push_back(-1);
            else ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};