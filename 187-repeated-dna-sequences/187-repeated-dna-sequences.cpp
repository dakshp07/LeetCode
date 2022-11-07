class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // so we know that the pattern is of 10 size
        // we can put all those patterns in map with freq
        if(s.length()<10) return {};
        unordered_map<string, int> mp;
        vector<string> res;
        // so we have a window size of 10, essentially 9 as we start from 0 index
        int i=0, j=9;
        // we traverse the string till j reaches end
        while(j<s.length())
        {
            // we add the substring to our map
            mp[s.substr(i, j-i+1)]++; // we add 10 size substring
            // we increment i, j to keep window size of 10
            i++;
            j++;
        }
        // now we check map, if for any 10 size pattern we have freq>1 we add them to res
        // as they are repeated
        for(auto it: mp)
        {
            if(it.second>1)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};