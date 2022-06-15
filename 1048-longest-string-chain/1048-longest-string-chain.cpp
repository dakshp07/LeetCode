class Solution {
public:
    bool check(string &a, string &b)
    {
        if(a.size()!=b.size()+1) return false; // agar ek char se zyaada badi huyi toh chain nhi
        int first=0;
        int second=0;
        while(first<a.size()) // a bada hain
        {
            if(a[first]==b[second]) // same huye toh dono aage
            {
                first++;
                second++;
            }
            else // alag huye to a ko jaane do, usko refer karke chain dekh rahe isliye
            {
                first++;
            }
        }
        if(first==a.size() && second==b.size()) return true; // agar dono pointer saath khatam huye toh badiya
        return false;
    }
    
    static bool comp(string &a, string &b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp); // acc to length sort
        // use lis
        // instead of increase check if the strings are differentiating by one char
        // tabulation method
        int n=words.size();
        int mx=1;
        vector<int> dp(n, 1); // dp of size n
        // dp[i]=signifies the lis that ends at i
        for(int i=0; i<n; i++) // starting se end taak chalo
        {
            for(int prev=0; prev<i; prev++) // or prev ka track rakho
            {
                if(check(words[i], words[prev]) && 1+dp[prev]>dp[i]) // can my prev words be a part of curr ? if yes then my lis now +1 of the prev lis
                {
                    dp[i]=1+dp[prev]; 
                }
            }
            mx=max(mx, dp[i]); // puri dp ka max is my ans
        }
        return mx;
    }
};