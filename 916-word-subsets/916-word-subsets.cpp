class Solution {
public:
    bool subset(vector<int> src, vector<int> des)
    {
        // we loop for all 26 chars
        for(int i=0; i<26; i++)
        {
            // if they are different
            if(des[i]>src[i]) return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // one of the brute force way is to compare the letters of every string in word2 with every word in word1
        // tc: O(word1.size * word2.size)
        // the next optimal way is combine the word2 string into one, we will combine then by seeing the max no of times each char appears in every word of word2
        // tc: O(word1.length()+word2.length())
        vector<string> res;
        vector<int> freq(26); // we will store the max count of word in word2
        for(int i=0; i<words2.size(); i++)
        {
            // since we need max we wil use one temp array
            vector<int> temp(26);
            for(int j=0; j<words2[i].length(); j++)
            {
                char c=words2[i][j];
                temp[c-'a']++;
                // we will pick max of all char and put it in target
                freq[c-'a']=max(freq[c-'a'], temp[c-'a']);
            }
        }
        // we nee count of all char of string in word1
        for(int i=0; i<words1.size(); i++)
        {
            vector<int> temp(26);
            for(int j=0; j<words1[i].length(); j++)
            {
                char c=words1[i][j];
                temp[c-'a']++;
            }
            // now we check if the freq is subset of the temp array or not
            if(subset(temp, freq))
            {
                // if we get true we add word to res
                res.push_back(words1[i]);
            }
        }
        return res;
    }
};
