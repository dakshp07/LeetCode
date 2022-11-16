class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // we map letters in order similar to english letter order
        // order = "hlabcdefgijkmnopqrstuvwxyz" gets mapped to "abcdefghijklmnopqrstuvwxyz"
        // and then we replace the words with all these english equivalent letters
        // So for eg, The word "hello" is transformed to "agbbo"
        // and then we check if words array is sorted or not
        // beacuse if its sorted in english letters, then we return true
        // as no matter whats the language it has to be sorted in all lang letter order
        unordered_map<char, char> mp;
        for(int i=0; i<order.size(); i++)
        {
            mp[order[i]]=i+'a'; // map order with english letter order
        }
        // now we replace all strings char in words with their english equivalent letters
        for(int i=0; i<words.size(); i++)
        {
            for(int j=0; j<words[i].size(); j++)
            {
                words[i][j]=mp[words[i][j]];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};