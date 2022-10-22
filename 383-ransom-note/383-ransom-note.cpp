class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq_m(26, 0);
        for(int i=0; i<magazine.length(); i++)
        {
            freq_m[magazine[i]-'a']++;
        }
        for(int i=0; i<ransomNote.length(); i++)
        {
            if(freq_m[ransomNote[i]-'a']==0) return false;
            freq_m[ransomNote[i]-'a']--;
        }
        return true;
    }
};