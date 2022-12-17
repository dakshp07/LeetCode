class Solution {
public:
    void func(int ind, string s, string temp, vector<string> &ans)
    {
        // base case:
        // 1. if we have processed all index of string
        if(ind==s.size())
        {
            ans.push_back(temp);
            return;
        }
        // so now we can either pick the next index or not pick
        // pick and convert it to uppercase or lowercase
        if(isalpha(s[ind]))
        {
            // if its alphabet, we can either make it upper case or lowercase
            temp+=tolower(s[ind]);
            func(ind+1, s, temp, ans);
            temp.pop_back(); // backtracking

            temp+=toupper(s[ind]);
            func(ind+1, s, temp, ans);
            temp.pop_back(); // backtracking
        }
        // not pick this ele and dont change it ie if ele is an digit
        if(isdigit(s[ind]))
        {
            temp+=s[ind];
            func(ind+1, s, temp, ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        // so we either pick a ele or not pick a ele (given its an char)
        // we can use recursion
        vector<string> ans;
        func(0, s, "", ans);
        return ans;
    }
};
