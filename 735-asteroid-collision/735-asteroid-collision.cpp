class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // so we can use a stack
        // and push the ele into the stack
        // and just implement the rules, and pop accordingly
        // end answer will be present in our stack
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++)
        {
            // we push all +ve in stack
            if(st.empty() || asteroids[i]>0) st.push(asteroids[i]);
            // now when we see a -ve ele we peform the collision acc to rules
            else
            {
                // case 1: when the current asteroid is bigger then previous ones
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i]))
                {
                    st.pop();
                }
                // case 2: when the current asteroid is same size as previous ones
                if(!st.empty() && st.top()==abs(asteroids[i])) st.pop();
                // case 3: when the top of stack is also negative or st is empty
                else if(st.empty() || st.top()<0) st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};