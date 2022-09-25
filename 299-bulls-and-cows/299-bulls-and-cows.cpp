class Solution {
public:
    string getHint(string secret, string guess) {
        // we will store the secret in our map
        // map<char,freq> and then iterate over both the strings
        // if at a position the char matches we put them as bulls and reduce fre by 1
        // and similarly we do for cows
        unordered_map<char, int> mp;
        // store secret freq
        for(int i=0; i<secret.size(); i++)
        {
            mp[secret[i]]++;
        }
        // now iterate to find bulls
        int bulls=0;
        for(int i=0; i<secret.size(); i++)
        {
            // if both char match we increment bulls counter and decrease its freq by 1
            if(secret[i]==guess[i])
            {
                bulls++;
                mp[secret[i]]--;
            }
        }
        // now iterate to find cows
        int cows=0;
        for(int i=0; i<secret.size(); i++)
        {
            // if both char dont match
            // but we have the guess char in our map with freq >0
            // we increment our cows count
            if(secret[i]!=guess[i] && mp[guess[i]]>0)
            {
                cows++;
                mp[guess[i]]--;
            }
        }
        // frame ans
        string ans=to_string(bulls)+'A'+to_string(cows)+'B';
        return ans;
    }
};