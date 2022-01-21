class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0, curr=0, ans=0;
        for(int i=0; i<gas.size(); i++)
        {
            total+=gas[i]-cost[i];
            curr+=gas[i]-cost[i];
            if(curr<0)
            {
                curr=0;
                ans=i+1;
            }
        }
        if(total<0)
        {
            ans=-1;
        }
        return ans;
    }
};