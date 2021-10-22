class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        vector<int> res(st.size());
        for(int i=0; i<nums.size(); i++)
        {
            if(st.empty() || nums[i]>0)
            {
                st.push(nums[i]);
            }
            else
            {
                while(true)
                {
                    if(st.top()<0)
                    {
                        st.push(nums[i]);
                        break;
                    }
                    else if(st.top()==-nums[i])
                    {
                        st.pop();
                        break;
                    }
                    else if(st.top()>-nums[i])
                    {
                        break;
                    }
                    else
                    {
                        st.pop();
                        if(st.empty())
                        {
                            st.push(nums[i]);
                            break;
                        }
                    }
                }
            }
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};