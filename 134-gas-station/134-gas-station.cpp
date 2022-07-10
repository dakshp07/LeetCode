class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // greedily karenge
        int pos=0, sum=0, total=0;
        for(int i=0; i<gas.size(); i++)
        {
            // temp variable sum to keep a check if we get <0
            sum+=(gas[i]-cost[i]);
            
            // if our temp gets negative we know our ans is not this index and we add this sum to total to get the point were diff becomes 0 or >0 and then make sum 0 for new traversal
            if(sum<0) pos=i+1, total+=sum, sum=0;
        }
        // we add sum to total
        total+=sum;
        // if we ever get total as 0 or >0 we know our position is here
        if(total>=0) return pos;
        return -1;
    }
};