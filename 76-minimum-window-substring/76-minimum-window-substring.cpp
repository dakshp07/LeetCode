class Solution {
public:
    string minWindow(string s, string t) {
        /*
        Explanation:
- Here we’re storing all the characters from string t to an unordered_map mp.
- We are taking 3 variables, ans(to store the size of the minimum substring), start(to store  the start index) & count(to store the map size, if it became 0 that means we got a substring)
- Now taking 2 pointers i & j, we’ll iterate using j & will decrement the element count in map.
- if at any point the value became 0 that means we got all the elements of that char till now, so we’ll decrement the size of the count.
- In this way, we will decrement and once the count will be 0 if there is a substring with all the elements present.
- Now we’ll increment i and check if there is possible to remove any more characters and get smaller substrings.
- We’ll store the smaller length to ans & store the ith index in the start variable. Also, we’ll add the element to our map and increment the count variable if it became greater than 0.
- Now if the ans have some length except int_max, then return the substring from start index to length of ans. Else return empty string.
- Time complexity: O(m), where m is the length of string s.
        */
        int m=s.size(), n=t.size();
        unordered_map<char, int> mp;
        
        int ans = INT_MAX; 
        int start = 0; 
        
        for(auto x:t)
            mp[x]++;
        
        int count = mp.size();
        
        int i = 0, j = 0;

        while (j < s.length()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;

            if (count == 0) {
                while (count == 0) {
                    if (ans > j - i + 1) {
                        ans = j - i + 1;
                        start = i;
                    }
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count++;

                    i++;
                }
            }
            j++;
        }
        if (ans != INT_MAX)
            return s.substr(start, ans);
        else
            return "";
    }
};