class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort kar sakte hain but that will be O(nlogn) time
        // sort karke dekhte hain
        // if(nums.size()==0) return 0;
        // sort(nums.begin(), nums.end());
        // int mxStreak=1, currStreak=1;
        // for(int i=1; i<nums.size(); i++)
        // {
        //     if(nums[i]==nums[i-1]+1)
        //     {
        //         currStreak++;
        //     }
        //     else if(nums[i]==nums[i-1])
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         mxStreak=max(mxStreak, currStreak);
        //         currStreak=1;
        //     }
        // }
        // return max(mxStreak, currStreak);
        
        // now doing it in O(n) time
        // we will use set to keep track of elements
        unordered_set<int> st;
        // saare ele add karo in set
        for(int i=0; i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        // check karo if ele ka ele-1 hain kya set main
        // agar haa matlab ye ele nhi hain humaare seq ka start
        // agar naa matlab idhar se seq start hoga
        int res=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(st.count(nums[i]-1)==0)
            {
                int cnt=1;
                // ab baaki ka seq check karo +1 karte karte
                while(st.count(nums[i]+cnt)>0)
                {
                    cnt++;
                }
                res=max(res, cnt);
            }
        }
        return res;
    }
};
