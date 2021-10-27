class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> vec1(26,0);
        vector<int> vec2(26,0);
        if(s2.length()<s1.length())
        {
            return false;
        }
        int left=0;
        int right=0;
        while(right<s1.length())
        {
            vec1[s1[right]-'a']+=1;
            vec2[s2[right]-'a']+=1;
            right+=1;
        }
        right-=1;
        while(right<s2.length())
        {
            if(vec1==vec2)
            {
                return true;
            }
            right+=1;
            if(right!=s2.length())
            {
                vec2[s2[right]-'a']+=1;
            }
            vec2[s2[left]-'a']-=1;
            left+=1;
        }
        return false;
    }
};