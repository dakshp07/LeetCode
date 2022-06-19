class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ek toh hain ki sort karlo or current streak, max maintain karo
        // sort is o(nlogn)
        // but we have to do in o(n)
        // set main daalo sabko and check if nums[i]-1 is present or not
        unordered_set<int> st;
        int longStreak=0;
        for(int i=0; i<nums.size(); i++) st.insert(nums[i]);
        for(int i=0; i<nums.size(); i++)
        {
            if(!st.count(nums[i]-1)) // if set has nums[i]-1 ele
            {
                int currNum=nums[i]; // we set curr value as that nums
                int currStreak=1; // and start streak here
                while(st.count(currNum+1)) // we try to find more nums+1
                {
                    currNum+=1; // and set the curr value to curr
                    currStreak+=1; // increment curr streak by one
                }
                longStreak=max(currStreak, longStreak); // pick the longest as ans
            }
        }
        return longStreak;
    }
};

