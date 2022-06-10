class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window use karenge  and use a map to keep the track of visited elements
        unordered_map<int, int> mp;
        int res=0; // length of window
        int curr=0; // pointing to current element
        for(int i=0; i<s.length(); i++)
        {
            // i-curr will give the length of current window
            res=max(res, i-curr);
            // agar char is present in the map but no in our window, so we include it
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=curr)
            {
                curr=mp[s[i]]+1;
            }
            mp[s[i]]=i;
        }
        // agar sabse lambi substring is in end toh curr kabhi bhi update nhi hoga
        // for that we will do:
        if(res<s.length()-curr)
        {
            return s.length()-curr;
        }
        return res;
    }
};