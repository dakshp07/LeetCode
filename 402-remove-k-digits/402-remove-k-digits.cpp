class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<int> st;
        if(k==nums.size())
        {
            // cout<<0<<"\n";
            return "0";
        }
        for(int i=0; i<nums.length(); i++)
        {
            while(!st.empty() && k>0 && st.top()>nums[i])
            {
                st.pop();
                k--;
            }
            if(st.empty() && nums[i]=='0')
            {
                continue;
            }
            st.push(nums[i]);
        }
        while(k-- && !st.empty())
        {
            st.pop();
        }
        string res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        if(res=="")
        {
            // cout<<0<<"\n";
            return "0";
        }
        // else
        // {
        //     cout<<res<<"\n";
        // }
        return res;
    }
};