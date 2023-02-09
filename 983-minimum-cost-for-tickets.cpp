class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // so if we go through greedily ie to pick the longest increasing subsequence we observe that we can never get the minimum price (dry run a few cases)
        // so we have to check all three options
        // hence we use recursion and optmise it further
        /*
        int recursion(int ind)
        {
            // base case:
            // 1. if i reach end of days array
            if(ind>=days.size()) return 0;

            // option 1: take 1 day pass
            int op1=costs[0]+func(ind+1);

            // option 2: take 7 day pass
            // now if we take 7 day pass, we go to index the 7th day lies
            int new_ind;
            for(new_ind=ind; new_ind<days.size(); new_ind++)
            {
                // we do 6 as are already at day[ind]
                if(days[new_ind]>days[ind]+6) break;
            }
            // so now new_ind stored the max day we can reach with a 7 day pass
            int op2=costs[1]+func(new_ind);

            // option 3: take 29 day pass
            // now if we take 29 day pass, we go to index the 7th day lies
            for(new_ind=ind; new_ind<days.size(); new_ind++)
            {
                // we do 6 as are already at day[ind]
                if(days[new_ind]>days[ind]+29) break;
            }
            // so now new_ind stored the max day we can reach with a 30 day pass
            int op3=costs[2]+func(new_ind);

            // we return min of all 3
            return min({op1, op2, op3});
        }

        memoization:
        vector<int> dp(n+1, -1);
        int recursion(int ind)
        {
            if(dp[ind]!=-1) return dp[ind];
            // base case:
            // 1. if i reach end of days array
            if(ind>=days.size()) return 0;

            // option 1: take 1 day pass
            int op1=costs[0]+func(ind+1);

            // option 2: take 7 day pass
            // now if we take 7 day pass, we go to index the 7th day lies
            int new_ind;
            for(new_ind=ind; new_ind<days.size(); new_ind++)
            {
                // we do 6 as are already at day[ind]
                if(days[new_ind]>days[ind]+6) break;
            }
            // so now new_ind stored the max day we can reach with a 7 day pass
            int op2=costs[1]+func(new_ind);

            // option 3: take 29 day pass
            // now if we take 29 day pass, we go to index the 7th day lies
            for(new_ind=ind; new_ind<days.size(); new_ind++)
            {
                // we do 6 as are already at day[ind]
                if(days[new_ind]>days[ind]+29) break;
            }
            // so now new_ind stored the max day we can reach with a 30 day pass
            int op3=costs[2]+func(new_ind);

            // we return min of all 3
            return dp[ind]=min({op1, op2, op3});
        }
        */

        // tabulation:
        int n=days.size();
        vector<int> dp(n+1, INT_MAX);
        // base case:
        // 1. if i reach end of days array:
        dp[n]=0;

        // for loops
        for(int ind=n-1; ind>=0; ind--)
        {
            // option 1: take 1 day pass
            int op1=costs[0]+dp[ind+1];

            // option 2: take 7 day pass
            // now if we take 7 day pass, we go to index the 7th day lies
            int new_ind;
            for(new_ind=ind; new_ind<days.size(); new_ind++)
            {
                // we do 6 as are already at day[ind]
                if(days[new_ind]>days[ind]+6) break;
            }
            // so now new_ind stored the max day we can reach with a 7 day pass
            int op2=costs[1]+dp[new_ind];

            // option 3: take 29 day pass
            // now if we take 29 day pass, we go to index the 7th day lies
            for(new_ind=ind; new_ind<days.size(); new_ind++)
            {
                // we do 6 as are already at day[ind]
                if(days[new_ind]>days[ind]+29) break;
            }
            // so now new_ind stored the max day we can reach with a 30 day pass
            int op3=costs[2]+dp[new_ind];

            // we return min of all 3
            dp[ind]=min({op1, op2, op3});
        }
        return dp[0];
    }
};
