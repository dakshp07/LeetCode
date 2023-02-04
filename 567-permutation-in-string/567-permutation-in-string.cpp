class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // so we just dont need to check if chars exist
        // but we also need to check if they exist as permutations
        // which means we have to use sliding window

        // we use two freq chars, both initially populated with s1 lenghts
        // and then we remove ele from left and add new ele from right
        // if at any point the chars become equal we return true

        // base case: if s1 is bigger than s1 or if s2 is empty
        if(s1.size()>s2.size() || s2.size()==0) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        // intially populate both freq chars with s1 lenght
        for(int i=0; i<s1.size(); i++)
        {
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }

        // now we start sliding window
        for(int i=s1.size(); i<s2.size(); i++)
        {
            // if freq array are same return true
            if(freq1==freq2) return true;
            // else we remove ele from left and add new ele from right in freq2
            freq2[s2[i-s1.size()]-'a']--;
            freq2[s2[i]-'a']++;
        }
        // after all iteration we check if freq1==freq2 or not 
        return freq1==freq2;
    }
};
