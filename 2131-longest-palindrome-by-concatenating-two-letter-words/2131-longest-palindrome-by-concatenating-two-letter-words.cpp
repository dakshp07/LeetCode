class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // essentially i've to look for every ith letters reverse in the array
        // if i've the reverse with me i can take both these strings
        // at the end i'll also check if theres any string in words which has both chars same
        // eg: gg, cc etc
        // if yes ill add that too
        // brute will be using two for loops. tc: O(n^2) and sc: O(1)
        
        // we can use a hashmap to do in one traversal. tc: O(n) and sc: O(n)
        unordered_map<string, int> mp;
        // we store the count of strings in map
        // if we find any string which is reverse of an existing string in the map
        // then we pair them and make ans+=4 and also reduce the freq count in map
        int ans=0;
        for(int i=0; i<words.size(); i++)
        {
            string og=words[i]; // original string
            string rev=words[i];
            reverse(rev.begin(), rev.end());
            // we check if this rev string exists in map or not
            if(mp.find(rev)!=mp.end())
            {
                // make ans+=4 as we can make a pair now
                ans+=4;
                // then we reduce the count of rev string
                mp[rev]--;
                // we remove mp[rev] if its freq becomes 0
                if(mp[rev]==0) mp.erase(rev);
            }
            // if we dont find the rev string in map
            else
            {
                // then we enter the og as a new entry with a freq of 1
                mp[og]++;
            }
        }
        // now we go over the map again to see the chars such as aa,bb,gg etc
        for(auto it: mp)
        {
            // if both chars are same
            if(it.first[0]==it.first[1])
            {
                // increment ans by 2
                ans+=2;
                // we break here as we can at max add one pair of these strings in the middle
                break;
            }
        }
        return ans;
    }
};