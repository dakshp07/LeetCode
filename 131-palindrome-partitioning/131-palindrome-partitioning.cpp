class Solution {
public:
    // helper for checking bool
    bool isPal(string s, int start, int end)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void func(int ind, string s, vector<string> &path, vector<vector<string>> &res)
    {
        if(ind==s.size()) // ie we are at last index
        {
            res.push_back(path); // push our path to ans
            return;
        }
        for(int i=ind; i<s.size(); i++) // iterating through string
        {
            // check if we put a partition here does the right, left parts become palindrome
            if(isPal(s, ind, i))
            {
                // if the right, left parts are palindrome we consider making a partiiton here
                // and will make recursive calls on this substring
                path.push_back(s.substr(ind, i-ind+1)); // pushing substring
                func(i+1, s, path, res); // recursive calls on substring
                path.pop_back(); // empty it for next recursive calls
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // we can peform a brute force since length is max 16
        // generate all substrings
        // first identify the place where we can parition our strings
        // and then peform recrusive calls on those strings
        // and again check the place where we can do partition and do recursive call on those strings
        // obs: check if you parition, pick substrings, make recursion calls from other index
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }
};