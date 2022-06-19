class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // using a freq array to store the indexes
        vector<int> freq(256, -1);
        int left=0, right=0, len=0; // keep a pointer left, right starting at 0
        while(right<s.size())
        {
            if(freq[s[right]]!=-1) // check the freq of s[right]
            {
                left=max(freq[s[right]]+1, left); // update it with the most recent index
            }
            freq[s[right]]=right; // if it doesnt exist we make it
            len=max(len, right-left+1); // update the len
            right++; // update right
        }
        return len;
    }
};

/*
another approach:
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
*/