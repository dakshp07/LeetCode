class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        // Brute: 89ms and 49.18% of rest submission
        // int ans=0;
        // for(int i=0; i<items.size(); i++)
        // {
        //     if((ruleKey=="type" && ruleValue==items[i][0]) || (ruleKey=="color" && ruleValue==items[i][1]) || (ruleKey=="name" && ruleValue==items[i][2]))
        //     {
        //         ans++;
        //     }
        // }
        // return ans;
        
        // Optimised
        int j=0, ans=0;
        if(ruleKey=="type") j=0;
        if(ruleKey=="color") j++;
        if(ruleKey=="name") j+=2;
        for(int i=0; i<items.size(); i++)
        {
            if(items[i][j]==ruleValue)
            {
                ans++;
            }
        }
        return ans;
    }
};