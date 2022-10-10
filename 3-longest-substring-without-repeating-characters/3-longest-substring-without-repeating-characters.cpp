class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // we can use the concept of sliding window and map
        // map will keep track of the unique elements and the window will move
        if(s.length()==0)return 0;   //if string of length zero comes simply return 0
        unordered_map<char, int> mp;
        // now two pointers will keep track of the window
        // i is left and j is right, we pop from left and add from right
        int i=0, j=0, ans=INT_MIN;
        while(j<s.size())
        {
            mp[s[j]]++; // add ele to map
            // if map size is equal to window size, means all ele in this window are unique
            if(mp.size()==j-i+1)
            {
                // in this case we update ans
                ans=max(ans, j-i+1);
            }
            // now if mp.size()<window size means there are duplicates in this window, so we pop the duplicates
            else if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--; // remove duplicates, we use i since its the left and j is right
                    // we remove the entry completely if it becomes 0
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    // and increment i
                    i++;
                }
            }
            j++; // update j ie right
        }
        return ans;
    }
};