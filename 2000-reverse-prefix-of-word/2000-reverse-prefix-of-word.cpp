class Solution {
public:
    string reversePrefix(string word, char ch) {
        int length=word.length();
        int pos=0;
        for(int i=0; i<length; i++)
        {
            if(word[i]==ch)
            {
                pos=i;
                break;
            }
        }
        int left=0;
        int right=pos;
        while(left<right)
        {
            swap(word[right], word[left]);
            left++;
            right--;
        }
        return word;
    }
};