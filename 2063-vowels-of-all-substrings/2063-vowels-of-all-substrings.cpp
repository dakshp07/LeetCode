class Solution {
public:
    bool isVowel(char a)
    {
        return a=='a'||a=='e'||a=='i'||a=='o'||a=='u';
    }
    long long countVowels(string word) {
        long long ans=0;
        for(long long i=0; i<word.length(); i++)
        {
            if(!isVowel(word[i]))
            {
                continue;
            }
            ans+=(i+1)*(word.length()-i);
        }
        return ans;
    }
};