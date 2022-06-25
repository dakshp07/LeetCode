// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    // sort them acc to end time
    static bool cmpr(pair<int, int> a, pair<int, int> b)
    {
        return a.second<b.second;
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // sort karo and see how many meets you can peform at once
        vector<pair<int, int>> meets;
        for(int i=0; i<n; i++)
        {
            meets.push_back(make_pair(start[i], end[i]));
        }
        sort(meets.begin(), meets.end(), cmpr);
        // now we will store the first meet end time
        int end_time=meets[0].second;
        int res=1;
        for(int i=1; i<meets.size(); i++)
        {
            // lets see next meet start
            if(meets[i].first>end_time) // if new meet starts when prev one ended, we can conduct that meet in one flow
            {
                // update our end time
                end_time=meets[i].second;
                res++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends