class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dono ways try karlo
        // 1 step chadne ka or 2 step chadne ka
        // choose min
        for(int i=2; i<cost.size(); i++)
        {
            // min step chaiye from 1 step, 2 step
            cost[i]+=min(cost[i-1], cost[i-2]);
        }
        // i-1 and i-2 ka minimum return karo
        return min(cost[cost.size()-1], cost[cost.size()-2]);
    }
};