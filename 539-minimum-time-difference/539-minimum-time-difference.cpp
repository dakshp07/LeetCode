class Solution {
public:
    int find(string s)
    {
        int h=stoi(s.substr(0,2));
        int m=stoi(s.substr(3));
        return h*60+m;
    }
    int findMinDifference(vector<string>& s) 
    {
        int n=s.size();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(find(s[i]));
        }
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int s1=abs(v[i%n]-v[(i-1+n)%n]);
            ans=min({ans,s1,1440-s1});
        }
        return ans;
    }    
};