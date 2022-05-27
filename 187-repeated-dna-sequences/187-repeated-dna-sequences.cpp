class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // map laga lo
        // string, uski freq daalenge
        unordered_map<string, int> mp;
        vector<string> res;
        if(s.length()<10) return res;
        for(int i=0; i<s.length()-9; i++)
        {
            // current pattern of 10 length
            string temp=s.substr(i, 10);
            // agar pattern map main hain, uska freq is 1
            // means woh phele aa chuka so add in vector
            if(mp.find(temp)!=mp.end() && mp[temp]==1)
            {
                res.push_back(temp);
            }
            // agar nhi hain woh map main toh add kardo
            mp[temp]++;
        }
        return res;
    }
};