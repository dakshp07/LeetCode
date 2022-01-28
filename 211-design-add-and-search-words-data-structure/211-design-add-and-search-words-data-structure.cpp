class WordDictionary {
    unordered_map<int, vector<string>> mp;
    
    bool isOk(string word1, string word2)
    {
        for(int i=0; i<word2.length(); i++)
        {
            if(word2[i]=='.')
            {
                continue;
            }
            if(word2[i]!=word1[i])
            {
                return false;
            }
        }
        return true;
    }
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.length()].push_back(word);
    }
    
    bool search(string word) {
        if(mp.find(word.size())==mp.end())
        {
            return false;
        }
        vector<string> storeWord=mp[word.size()];
        for(int i=0; i<storeWord.size(); i++)
        {
            if(isOk(storeWord[i], word))
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */