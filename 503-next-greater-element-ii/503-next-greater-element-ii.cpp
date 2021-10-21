class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;
        for(int i=0; i<nums.size()*2; i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i%nums.size()])
            {
                res[st.top()]=nums[i%nums.size()];
                st.pop();
            }
            if(i<nums.size())
            {
                st.push(i);
            }
        }
        return res;
    }
};