class Solution {
public:
    string getHint(string secret, string guess) {
        // map main nunber, freq daal dunga
        // maan lo if at i pos we dont have a specific dig then we see in map
        // agar same pos pe aagaya toh thik hi hain
        unordered_map<char, int> mp;
        for(int i=0; i<secret.size(); i++)
        {
            mp[secret[i]]++;
        }
        int i=0, j=0;
        int bulls=0, cows=0;
        for(int i=0; i<secret.size(); i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
                mp[guess[i]]--;
            }
        }
        for(int i=0; i<secret.size(); i++)
        {
            if(secret[i]!=guess[i] && mp[guess[i]]>0)
            {
                cows++;
                mp[guess[i]]--;
            }
        }
        string ans="";
        ans+=to_string(bulls);
        ans+='A';
        ans+=to_string(cows);
        ans+='B';
        return ans;
    }
};